#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BAUD_RATE 150
#define BITS_PER_CHARACTER 8
#define DELAY ((float)BITS_PER_CHARACTER / BAUD_RATE)

void printWithBaudRate(const char *text);

int main()
{
    char *mnth[] = {
        "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
        "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
    };
    char label[2];
    struct tm *datebuf;
    time_t now;

    system("clear");  // Clear the screen

    usleep(1000000);
    printWithBaudRate("\nKA630-A.V1.3\n\n");

    printWithBaudRate("Performing normal system tests.\n\n");
    usleep(4000000);

    printWithBaudRate("  7..");
    usleep(3000000);

    printWithBaudRate("6..");
    usleep(2000000);

    printWithBaudRate("5..");
    usleep(4000000);

    printWithBaudRate("4..3..\n\n");
    usleep(2000000);

    printWithBaudRate("Tests completed.\n\n");

    printWithBaudRate(">>>");
    scanf("%s", label);
    while (strncmp(label, "p", 1) != 0)
    {
        usleep(3000000);
        printWithBaudRate("(BOOT/R5:0 DIA0:)\n");
        usleep(3000000);

        printWithBaudRate("\n  2..");
        usleep(7);

        printWithBaudRate("\n-R2IZZC$DIA0\n");
        usleep(4000000);

        printWithBaudRate("  1..");
        usleep(2000000);

        printWithBaudRate("0..\n\n\n");
        usleep(5000000);

        printWithBaudRate("    VAX/VMS Version V5.5-2   Major version id = 1   Minor version id = 0\n\n");
        printWithBaudRate("$!   Copyright (c) 1991 Digital Equipment Corporation.  All rights reserved.\n\n");
        usleep(2000000);

        now = time(NULL);
        datebuf = localtime(&now);
        printWithBaudRate("%%STDRV-I-STARTUP, VMS startup begun at ");
	printf("%.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d\n\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        usleep(3000000);

        printWithBaudRate("The VAX/VMS system is now executing the system startup procedure.\n\n");
        usleep(1000000);

        printWithBaudRate("%%SET-I-NEWAUDSRV, identification of new audit server process is 002A\n");
        usleep(2000000);

        now = time(NULL);
        datebuf = localtime(&now);
        printWithBaudRate("\a%%%%%%%%%%%%%%%%%%%%%%  OPCOM  ");
	printf("%.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printWithBaudRate("  %%%%%%%%%%%%%%%%%%%%%%%%\n");

	printWithBaudRate("Operator _PKA004$OPA0: has been enabled, username SYSTEM\n\n");
        usleep(2000000);

        now = time(NULL);
        datebuf = localtime(&now);
        printWithBaudRate("\a%%%%%%%%%%%%%%%%%%%%%%  OPCOM  ");
	printf("%.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printWithBaudRate("  %%%%%%%%%%%%%%%%%%%%%%%%\n");

        printWithBaudRate("Operator status for operator _PKA004$OPA0:\n");
        printWithBaudRate("CARDS\n\n");
        usleep(2000000);

        now = time(NULL);
        datebuf = localtime(&now);
        printWithBaudRate("\a%%%%%%%%%%%%%%%%%%%%%%  OPCOM  ");
	printf("%.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printWithBaudRate("  %%%%%%%%%%%%%%%%%%%%%%%%\n");
        printWithBaudRate("Logfile has been initialized by operator _PKA004$OPA0:\n");
        printWithBaudRate("Logfile is PKA004::SYS$SYSROOT:[SYSMGR]OPERATOR.LOG;26\n\n");
        usleep(2000000);

        now = time(NULL);
        datebuf = localtime(&now);
        printWithBaudRate("\a%%%%%%%%%%%%%%%%%%%%%%  OPCOM  ");
	printf("%.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printWithBaudRate("  %%%%%%%%%%%%%%%%%%%%%%%%\n");
        printWithBaudRate("Operator status for operator PKA004::SYS$SYSROOT:[SYSMGR]OPERATOR.LOG;26\n");
        printWithBaudRate("CENTRAL, PRINTER, TAPES, DISKS, DEVICES, CARDS, NETWORK, CLUSTER, SECURITY,\n");
        printWithBaudRate("LICENSE, OPER1, OPER2, OPER3, OPER4, OPER5, OPER6, OPER7, OPER8, OPER9, OPER10,\n");
        printWithBaudRate("OPER11, OPER12\n\n\n");
        usleep(2000000);

        printWithBaudRate("The VAX/VMS system is now executing the site-specific startup commands.\n\n");
        usleep(4000000);

        printWithBaudRate("%%MOUNT-I-MOUNTED, APPDISK01     mounted on _$1$DIA1:\n");
        usleep(3000000);
        printWithBaudRate("%%MOUNT-I-MOUNTED, APPDISK02     mounted on _$1$DIA2:\n");
        usleep(3000000);
        printWithBaudRate("%%MOUNT-I-MOUNTED, APPDISK03     mounted on _$1$DIA3:\n");
        usleep(3000000);
        printWithBaudRate("%%MOUNT-I-MOUNTED, APPDISK04     mounted on _$1$DIA4:\n");
        usleep(3000000);
        printWithBaudRate("%%MOUNT-I-MOUNTED, APPDISK05     mounted on _$1$DIA5:\n");
        usleep(3000000);
        printWithBaudRate("%%MOUNT-I-MOUNTED, APPDISK06     mounted on _$1$DIA6:\n\n");
        usleep(5000000);

        printWithBaudRate("%%CHE-I-ENDPROC, end of procedure SYS$MANAGER:SYSTARTUP_V5.COM\n");
        usleep(3000000);

        now = time(NULL);
        datebuf = localtime(&now);
        printWithBaudRate("%%SET-I-INTSET, login interactive limit = 64, current interactive value = 0\n");
        printf("   %.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printWithBaudRate("%%DECW-W-NODEVICE, No graphics drivers found on this system\n");
        printWithBaudRate("%%DECW-I-NODECW, DECwindows graphics drivers will not be loaded\n");
	usleep(1000000);

        now = time(NULL);
        datebuf = localtime(&now);
        printWithBaudRate("  SYSTEM       job terminated at ");
	printf("%.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d\n\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
	usleep(2000000);

        printWithBaudRate("Accounting information:\n");
        printWithBaudRate("Buffered I/O count:            1594          Peak working set size:      932\n");
        printWithBaudRate("Direct I/O count:              1013          Peak page file size:      11254\n");
        printWithBaudRate("Page faults:                   7979          Mounted volumes:              6\n");
        usleep(4000000);

        printWithBaudRate("%%FATAL-F-DEVTIMOUT, I/O error... System initialization failed.\n\n");
        printWithBaudRate("?02 EXT HLT\n");
        printWithBaudRate("    PC = 802AA3F1\n");
        printWithBaudRate(">>>");

        while ((getchar()) != '\n');  // Clear input buffer
        scanf("%2s", label);
    }

    return 0;
}

void printWithBaudRate(const char *text) {
    while (*text) {
        putchar(*text);
        fflush(stdout);  // Flush output to display immediately
        usleep(1000000 * DELAY);  // Delay between characters
        text++;
    }
}
