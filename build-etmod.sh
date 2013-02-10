#!/bin/bash

if [ ${1} ]; then
  if [ ${1} = "new" ]; then
    BUILD_NUMBER=`cat build.id`
    NEW_BUILD=`expr $BUILD_NUMBER + 1`
    echo $NEW_BUILD > build.id
  fi
fi

mkdir build
cd build
cmake ../
make

