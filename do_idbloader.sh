#!/bin/sh
MINILOADER="rk322xh_miniloader_v2.46.bin"
DDR="rk3328_ddr_333MHz_v1.13.bin"

tools/mkimage -n rk3328 -T rksd -d ${DDR} idbloader.img
cat ${MINILOADER} >> idbloader.img
