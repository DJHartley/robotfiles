/**
 * r0b0tfiles - My Template files for coding a tool using limobiledevice, lplist, lusb-1.0, IOKit, CoreFoundation and MobileDevice.
 * Copyright (C) 2014  Louis Kremer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include <string.h>
#include <CoreFoundation/CoreFoundation.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <libgen.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>

#include <zlib.h>

#include <fcntl.h>
#include <sys/mman.h>

#include <ioshdev.h>

#include <libusb-1.0/libusb.h>
#include <usb.h>

#include <libimobiledevice/libimobiledevice.h>
#include <libimobiledevice/lockdown.h>
#include <libimobiledevice/mobile_image_mounter.h>
#include <libimobiledevice/mobilebackup2.h>
#include <libimobiledevice/installation_proxy.h>
#include <libimobiledevice/notification_proxy.h>
#include <libimobiledevice/afc.h>
#include <libimobiledevice/sbservices.h>
#include <libimobiledevice/file_relay.h>
#include <libimobiledevice/diagnostics_relay.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void help(void){
    printf("%s[*] ./program -option (Do it)\n", KCYN);
    printf("%s[*] ./program anything\n", KCYN);
    printf("%s", KNRM);
}

int main(int argc, char *argv[]) {
    if(argc == 2 && strcmp(argv[1], "--help")==0)
    {
        help();
        return -1;
    }
    else if(argc == 2 && strcmp(argv[1], "-help")==0){
        help();
        return -1;
    }
    else if(argc == 2 && strcmp(argv[1], "-h")==0){
        help();
        return -1;
    }
    else if(argc == 1){
        help();
        return -1;
    }
}
