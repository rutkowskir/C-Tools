// Compile using 'gcc comde.c -o comde -lz'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define CHUNK 16384

// Function to compress a file using zlib
int compressFile(const char *inputFile, const char *outputFile) {
    FILE *source = fopen(inputFile, "rb");
    FILE *dest = fopen(outputFile, "wb");
    if (!source || !dest) {
        perror("Failed to open files");
        return -1;
    }

    int ret, flush;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK) {
        return ret;
    }

    do {
        strm.avail_in = fread(in, 1, CHUNK, source);
        if (ferror(source)) {
            (void)deflateEnd(&strm);
            return Z_ERRNO;
        }
        flush = feof(source) ? Z_FINISH : Z_NO_FLUSH;
        strm.next_in = in;

        do {
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = deflate(&strm, flush);
            have = CHUNK - strm.avail_out;
            if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
                (void)deflateEnd(&strm);
                return Z_ERRNO;
            }
        } while (strm.avail_out == 0);

    } while (flush != Z_FINISH);

    (void)deflateEnd(&strm);
    fclose(source);
    fclose(dest);
    return Z_OK;
}

// Function to decompress a file using zlib
int decompressFile(const char *inputFile, const char *outputFile) {
    FILE *source = fopen(inputFile, "rb");
    FILE *dest = fopen(outputFile, "wb");
    if (!source || !dest) {
        perror("Failed to open files");
        return -1;
    }

    int ret;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = inflateInit(&strm);
    if (ret != Z_OK) {
        return ret;
    }

    do {
        strm.avail_in = fread(in, 1, CHUNK, source);
        if (ferror(source)) {
            (void)inflateEnd(&strm);
            return Z_ERRNO;
        }
        if (strm.avail_in == 0) {
            break;
        }
        strm.next_in = in;

        do {
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = inflate(&strm, Z_NO_FLUSH);
            switch (ret) {
                case Z_NEED_DICT:
                case Z_DATA_ERROR:
                case Z_MEM_ERROR:
                    (void)inflateEnd(&strm);
                    return ret;
            }
            have = CHUNK - strm.avail_out;
            if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
                (void)inflateEnd(&strm);
                return Z_ERRNO;
            }
        } while (strm.avail_out == 0);

    } while (ret != Z_STREAM_END);

    (void)inflateEnd(&strm);
    fclose(source);
    fclose(dest);
    return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

// Main function to provide a command-line interface
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <compress|decompress> <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "compress") == 0) {
        if (compressFile(argv[2], argv[3]) != Z_OK) {
            fprintf(stderr, "File compression failed\n");
            return EXIT_FAILURE;
        }
    } else if (strcmp(argv[1], "decompress") == 0) {
        if (decompressFile(argv[2], argv[3]) != Z_OK) {
            fprintf(stderr, "File decompression failed\n");
            return EXIT_FAILURE;
        }
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
