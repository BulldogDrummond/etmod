#!/bin/sh

cd src
mkdir bin

scons BUILD=release COPYBINS=1

# EOF
