#!/bin/bash

set -e

rm -rf *.elf
rm -rf *.srec

ESDK=${EPIPHANY_HOME}
ELIBS=${ESDK}/tools/host/lib
EINCS=${ESDK}/tools/host/include
ELDF=${ESDK}/bsps/current/internal.ldf

SCRIPT=$(readlink -f "$0")
EXEPATH=$(dirname "$SCRIPT")
cd $EXEPATH

CROSS_PREFIX=
case $(uname -p) in
	arm*)
		# Use native arm compiler (no cross prefix)
		CROSS_PREFIX=
		;;
	   *)
		# Use cross compiler
		CROSS_PREFIX="arm-linux-gnueabihf-"
		;;
esac

# Build HOST side application
${CROSS_PREFIX}gcc -std=gnu99 -D_BSD_SOURCE feldspar-parallella.c gen/host.c -o cipher -Iinclude -I ${EINCS} -L ${ELIBS} -le-hal -le-loader -lpthread

cd gen
for f in core*.c
do
    ELF=../${f%.*}.elf
    SREC=../${f%.*}.srec

    # Build DEVICE side programs
    e-gcc -std=gnu99 -I../include -T ${ELDF} ../feldspar-parallella.c $f -o ${ELF} -le-lib -lm -Os
    # Convert ebinaries to SREC files
    e-objcopy --srec-forceS3 --output-target srec ${ELF} ${SREC}
done
cd ..

