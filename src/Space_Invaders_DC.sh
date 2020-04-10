
echo Executing Pre Build commands ...
. /opt/toolchains/dc/kos/environ.sh

make clean

make
echo Done
make
echo Executing Post Build commands ...
echo "password_here" | sudo -kS /opt/toolchains/dc/bin/dc-tool -t /dev/ttyUSB0 -b 1500000 -x main.elf
echo Done
