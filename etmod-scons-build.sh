#!/bin/sh

mkdir etmod
cd src

scons

cd ..
rm -rf src/build src/qagame.mp.i386.so src/scons.signatures.dblite src/scons_utils.pyc src/site.conf

./mkpak2.sh

cp -av resource-config/* etmod/

# EOF
