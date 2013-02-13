#!/bin/sh
#
# This script calls uncrustify for each file of project
#

for i in src/game/*.c; do uncrustify --no-backup -c uncrustify.cfg "$i"; done
for i in src/game/*.cpp; do uncrustify --no-backup -c uncrustify.cfg "$i"; done
for i in src/game/*.h; do uncrustify --no-backup -c uncrustify.cfg "$i"; done

# EOF
