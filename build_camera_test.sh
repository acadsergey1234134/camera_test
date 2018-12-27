#!/bin/bash

set -e
set -x

component="$1"

. ../set_environment.sh

#cd $PROJECT_DIR/camera_test
sb2 -t $SB2_TARGET -R qmake camera_test.pro -spec linux-g++ "CONFIG+=cross_compile sailfish_os"
sb2 -t $SB2_TARGET -R make
mb2 -t $SB2_TARGET build

set +x
set +e

echo;
echo OK!!!!

