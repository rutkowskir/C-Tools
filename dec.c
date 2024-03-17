#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BAUD_RATE 300
#define BITS_PER_CHARACTER 8
#define DELAY ((float)BITS_PER_CHARACTER / BAUD_RATE)

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
    printf("\nKA630-A.V1.3\n\n");
    printf("Performing normal system tests.\n\n");
    usleep(1000000);
    printf("  7..");
    usleep(1000000);
    printf("6..");
    usleep(1000000);
    printf("5..");
    usleep(1000000);
    printf("4..3..\n\n");
    usleep(1000000);
    printf("Tests completed.\n\n");

    printf(">>>");
    scanf("%s", label);
    while (strncmp(label, "b", 1) != 0)
    {
        usleep(1000000);
        printf("(BOOT/R5:0 DIA0:)\n");
        usleep(1000000);
        printf("\n  2..");
        usleep(7);
        printf("\n-R2IZZC$DIA0\n");
        usleep(1000000);
        printf("  1..");
        usleep(1000000);
        printf("0..\n\n\n");
        usleep(1000000);
        printf("    VAX/VMS Version V5.5-2   Major version id = 1   Minor version id = 0\n\n");
        usleep(1000000);
        printf("$!   Copyright (c) 1991 Digital Equipment Corporation.  All rights reserved.\n\n");
        usleep(1000000);

        now = time(NULL);
        datebuf = localtime(&now);
        printf("%%STDRV-I-STARTUP, VMS startup begun at %.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d\n\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        usleep(1000000);
        printf("The VAX/VMS system is now executing the system startup procedure.\n\n");
        usleep(6);

        printf("%%SET-I-NEWAUDSRV, identification of new audit server process is 002A\n");
        usleep(1000000);
        now = time(NULL);
        datebuf = localtime(&now);
        printf("\a%%%%%%%%%%%%%%%%%%%%%%  OPCOM  %.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d  %%%%%%%%%%%%%%%%%%%%%%%%\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printf("Operator _PKA004$OPA0: has been enabled, username SYSTEM\n\n");
        usleep(1000000);
        now = time(NULL);
        datebuf = localtime(&now);
        printf("\a%%%%%%%%%%%%%%%%%%%%%%  OPCOM  %.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d  %%%%%%%%%%%%%%%%%%%%%%%%\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printf("Operator status for operator _PKA004$OPA0:\n");
        printf("CARDS\n\n");
        usleep(1000000);
        now = time(NULL);
        datebuf = localtime(&now);
        printf("\a%%%%%%%%%%%%%%%%%%%%%%  OPCOM  %.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d  %%%%%%%%%%%%%%%%%%%%%%%%\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printf("Logfile has been initialized by operator _PKA004$OPA0:\n");
        printf("Logfile is PKA004::SYS$SYSROOT:[SYSMGR]OPERATOR.LOG;26\n\n");
        usleep(1000000);
        now = time(NULL);
        datebuf = localtime(&now);
        printf("\a%%%%%%%%%%%%%%%%%%%%%%  OPCOM  %.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d  %%%%%%%%%%%%%%%%%%%%%%%%\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printf("Operator status for operator PKA004::SYS$SYSROOT:[SYSMGR]OPERATOR.LOG;26\n");
        printf("CENTRAL, PRINTER, TAPES, DISKS, DEVICES, CARDS, NETWORK, CLUSTER, SECURITY,\n");
        printf("LICENSE, OPER1, OPER2, OPER3, OPER4, OPER5, OPER6, OPER7, OPER8, OPER9, OPER10,\n");
        printf("OPER11, OPER12\n\n\n");
        usleep(1000000);
        printf("The VAX/VMS system is now executing the site-specific startup commands.\n\n");
        usleep(1000000);
        printf("%%MOUNT-I-MOUNTED, APPDISK01     mounted on _$1$DIA1:\n");
        usleep(1000000);
        printf("%%MOUNT-I-MOUNTED, APPDISK02     mounted on _$1$DIA2:\n");
        usleep(1000000);
        printf("%%MOUNT-I-MOUNTED, APPDISK03     mounted on _$1$DIA3:\n");
        usleep(1000000);
        printf("%%MOUNT-I-MOUNTED, APPDISK04     mounted on _$1$DIA4:\n");
        usleep(1000000);
        printf("%%MOUNT-I-MOUNTED, APPDISK05     mounted on _$1$DIA5:\n");
        usleep(1000000);
        printf("%%MOUNT-I-MOUNTED, APPDISK06     mounted on _$1$DIA6:\n\n");
        usleep(1000000);
        printf("%%CHE-I-ENDPROC, end of procedure SYS$MANAGER:SYSTARTUP_V5.COM\n");
        usleep(1000000);
        now = time(NULL);
        datebuf = localtime(&now);
        printf("%%SET-I-INTSET, login interactive limit = 64, current interactive value = 0\n");
        printf("   %.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        usleep(1000000);
        printf("%%DECW-W-NODEVICE, No graphics drivers found on this system\n");
        printf("%%DECW-I-NODECW, DECwindows graphics drivers will not be loaded\n");
        now = time(NULL);
        datebuf = localtime(&now);
        printf("  SYSTEM       job terminated at %.2d-%s-%.4d %.2d:%.2d:%.2d.%.2d\n\n",
               datebuf->tm_mday, mnth[datebuf->tm_mon], datebuf->tm_year + 1900,
               datebuf->tm_hour, datebuf->tm_min, datebuf->tm_sec, 0);
        printf("Accounting information:\n");
        printf("Buffered I/O count:            1594          Peak working set size:      932\n");
        printf("Direct I/O count:              1013          Peak page file size:      11254\n");
        printf("Page faults:                   7979          Mounted volumes:              6\n");
        usleep(1000000);
        printf("%%FATAL-F-DEVTIMOUT, I/O error... System initialization failed.\n\n");
        printf("?02 EXT HLT\n");
        printf("    PC = 802AA3F1\n");
        printf(">>>");
        while ((getchar()) != '\n');  // Clear input buffer
        scanf("%2s", label);
    }

    return 0;
}
