/*
 * (C) Copyright 2016 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __CONFIG_RK3328_COMMON_H
#define __CONFIG_RK3328_COMMON_H

/* #include "rockchip-common.h" */
/* from rockchip-common.h ... */
#define COUNTER_FREQUENCY               24000000
#define CONFIG_SYS_ARCH_TIMER
#define CONFIG_SYS_HZ_CLOCK     24000000

#define CONFIG_SYS_NS16550_MEM32

#define CONFIG_NR_DRAM_BANKS            2
#define CONFIG_DISPLAY_BOARDINFO_LATE
/* End of from rockchip-common.h ... */


#define CONFIG_SYS_MALLOC_LEN		(32 << 20)
#define CONFIG_SYS_CBSIZE		1024
#define CONFIG_SKIP_LOWLEVEL_INIT

#define CONFIG_SPL_FRAMEWORK

#define CONFIG_SYS_TEXT_BASE		0x00200000
#define CONFIG_SYS_INIT_SP_ADDR		0x00300000
#define CONFIG_SYS_LOAD_ADDR		0x00800800
#define CONFIG_SPL_STACK		0x00400000
#define CONFIG_SPL_TEXT_BASE		0x00000000
#define CONFIG_SPL_MAX_SIZE             0x10000
#define CONFIG_SPL_BSS_START_ADDR	0x00400000
#define CONFIG_SPL_BSS_MAX_SIZE         0x2000
#define CONFIG_SYS_BOOTM_LEN	(64 << 20)	/* 64M */

#define GICD_BASE			0xFF811000
#define GICC_BASE			0xFF812000

#define CONFIG_ROCKUSB_G_DNL_PID	0x320C

/* MMC/SD IP block */
#define CONFIG_BOUNCE_BUFFER

#define CONFIG_SUPPORT_VFAT
#define CONFIG_FS_EXT4

/* RAW SD card / eMMC locations. */
#define CONFIG_SYS_SPI_U_BOOT_OFFS	(128 << 10)

/* FAT sd card locations. */
#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION	1
#define CONFIG_SYS_SDRAM_BASE		0
#define SDRAM_MAX_SIZE			0xff000000

#define CONFIG_SPI_FLASH
#define CONFIG_SPI
#define CONFIG_SF_DEFAULT_SPEED 20000000
#undef	CONFIG_BOOTCOMMAND

#ifndef CONFIG_SPL_BUILD

/* usb mass storage */
#define CONFIG_USB_FUNCTION_MASS_STORAGE

#define ENV_MEM_LAYOUT_SETTINGS \
	"scriptaddr=0x00500000\0" \
	"pxefile_addr_r=0x00600000\0" \
	"fdt_addr_r=0x01f00000\0" \
	"kernel_addr_r=0x02080000\0" \
	"ramdisk_addr_r=0x04000000\0"

/* #include <config_distro_bootcmd.h> 
#define CONFIG_EXTRA_ENV_SETTINGS \
	ENV_MEM_LAYOUT_SETTINGS \
	RKIMG_DET_BOOTDEV \
	"partitions=" PARTS_DEFAULT \
	ROCKCHIP_DEVICE_SETTINGS \
	BOOTENV
*/
#undef	RKIMG_DET_BOOTDEV
#undef	RKIMG_BOOTCOMMAND

#define RKIMG_DET_BOOTDEV \
	"rkimg_bootdev=setenv devtype mmc; setenv devnum 1; echo Boot from SDcard;"

#define CONFIG_EXTRA_ENV_SETTINGS \
        "bootenv=NOVAsomParams\0" \
        "baudrate=115200\0" \
        "image=Image\0" \
        "initrd=uInitrd\0" \
        "fdt_file=dtb.dtb\0" \
        "console=ttyFIQ0\0" \
        "splashpos=m,m\0" \
        "fdt_addr=0x01f00000\0" \
        "fsaddr=0x04000000\0" \
        "loadaddr=0x02080000\0" \
        "ethaddr=5c:b8:b2:91:9f:29\0" \
	"ramdisk_size=96000\0" \
        "mmcdev=1\0" \
        "mmcpart=8\0" \
        "usbdev=0\0" \
        "usbpart=1\0" \
        "ramroot=/dev/ram rootwait rw\0" \
        "mmcloadimage=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${image}\0" \
        "mmcloadinitrd=fatload mmc ${mmcdev}:${mmcpart} ${fsaddr} ${initrd}\0" \
        "mmcloadfdt=fatload mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}\0" \
        "mmcloadbootenv=fatload mmc ${mmcdev}:${mmcpart}  ${loadaddr} ${bootenv}\0" \
        "importbootenv=echo Importing environment ...; env import -t ${loadaddr} ${filesize}\0" \
        "usbloadbootscript=fatload usb ${usbdev}:${usbpart} ${loadaddr} ${script};\0" \
        "usbloadimage=fatload usb ${usbdev}:${usbpart} ${loadaddr} ${image}\0" \
        "usbloadinitrd=fatload usb ${usbdev}:${usbpart} ${fsaddr} ${initrd}\0" \
        "usbloadfdt=fatload usb ${usbdev}:${usbpart} ${fdt_addr} ${fdtfile}\0" \
        "boardargs=setenv bootargs console=${console},${baudrate} root=${ramroot} ramdisk_size=${ramdisk_size};\0" \
        "board_boot=echo Booting ...; " \
                "run boardargs; " \
                "booti ${loadaddr} ${fsaddr} ${fdt_addr};\0" \

/* #define CONFIG_BOOTCOMMAND \ 
*/
#define RKIMG_BOOTCOMMAND \
           "mmc dev ${mmcdev}; "\
                "if mmc rescan; then " \
                        "if run mmcloadbootenv; then " \
                                "echo Loaded environment ${bootenv};" \
                                "run importbootenv;" \
                                "run uenvcmd;" \
                        "fi;" \
                        "if run mmcloadimage; then " \
                                "if run mmcloadfdt; then " \
                                        "if run mmcloadinitrd; then " \
                                                "run board_boot; " \
                                        "fi; " \
                                "fi; " \
                        "fi; " \
                "fi; " \
           "usb start;" \
                   "if run usbloadbootscript; then " \
                           "run bootscript; " \
                    "else " \
                           "if run usbloadimage; then " \
                                "if run usbloadfdt; then " \
                                        "if run usbloadinitrd; then " \
                                           "run board_boot; " \
                                        "fi; " \
                                 "fi; " \
                           "fi; " \
                   "fi; " \
                "fi; " \
           "run board_boot;"

#endif 

/* #define CONFIG_PREBOOT */

/* rockchip ohci host driver */
#define CONFIG_USB_OHCI_NEW
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	1

#endif
