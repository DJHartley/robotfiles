/**
 * OpeniDev Project - ioshdev ioshdev.h
 * ioshdev - Header file for easier communication with iPhones in all modes.
 * Copyright (C) 2014  Louis Kremer
 * Special Credits: Nikias Bassen(pimskeks) for libusb-1.0
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

#include <stdlib.h>
#include <stdio.h>
#include <libusb-1.0/libusb.h>
#include <usb.h>
#include <string.h>
#include <CoreFoundation/CoreFoundation.h>

#ifndef iOSHDEV_H
#define iOSHDEV_H

#ifdef __cplusplus
extern "C" {
#endif

    #define ADNCI_MSG_CONNECTED     1
    struct am_device_notification_callback_info {
        struct am_device *dev;
    }
    __attribute__ ((packed)) am_device_notification_callback_info;
    __attribute__ ((packed)) am_device;
    CFStringRef AMDeviceCopyDeviceIdentifier(struct am_device *device);
    
    struct am_device_notification *notify;
    struct am_device *device;

    struct libusb_device_handle *handle;
    int libusb_open();
    int rec_open();
    int rec_connect();
    int rec_close();
    int rec_restart();
    int rec_reset();
    int rec_send_cmd(char* command[]);
    int rec_saveenv();
    int rec_reboot();
    int set_autoboot_true();
    int normal_udid();
    int boot_logo_conf();
    void getdata(struct am_device_notification_callback_info *info);
    void sendata(*device);

    void getdata(struct am_device_notification_callback_info *info)
    {
        sendata(info->dev);
    }
    
    void sendata(*device)
    {
        CFStringEncoding encoding = CFStringGetSystemEncoding();
        const char *udid = CFStringGetCStringPtr(AMDeviceCopyDeviceIdentifier(device), encoding);
        printf("%s", udid);
        exit(EXIT_SUCCESS);
    }
    
    int rec_open() {
        handle = libusb_open_device_with_vid_pid(NULL, 0x05AC, 0x1281);
    }
    
    int rec_connect() {
        libusb_init(NULL);
        rec_open();
    }
    
    int rec_close() {
        libusb_close(handle);
    }
    
    int rec_restart() {
        rec_close();
        rec_open();
    }
    
    int rec_reset() {
        libusb_reset_device(handle);
    }
    
    int rec_send_cmd(char* command[]) {
        if (libusb_control_transfer(handle, 0x40, 0, 0, 0, command[0], (strlen(command[0]) + 1), 1000)) {
            printf("[*] Successfully sent command.\r\n");
        } else {
            printf("[*] Error with sending the command");
        }
    }
    
    int rec_saveenv() {
        char *saveenv = "saveenv";
        rec_send_cmd(&saveenv);
    }
    
    int rec_reboot() {
        char *reboot = "reboot";
        rec_send_cmd(&reboot);
    }
    
    int rec_autoboot_true() {
        char *setenv = "setenv auto-boot true";
        rec_send_cmd(&setenv);
    }
    
    int normal_udid() {
        AMDeviceNotificationSubscribe(&getdata, NULL, NULL, NULL, &notify);
        CFRunLoopRun();
    }
    
    int boot_logo_conf() {
        char* background[3];
        background[1] = "setpicture 0";
        background[2] = "bgcolor 0 0 0";
        background[3] = "bgcolor 192 192 192";
        rec_send_cmd(&background[1]);
        rec_send_cmd(&background[2]);
        rec_send_cmd(&background[3]);
    }
    
#ifdef __cplusplus
}
#endif
#endif
