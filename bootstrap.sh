# !/bin/bash
# Author: Edson Alves - edsonalves@unb.br
# Date: 26/11/2010

mkdir -p config
aclocal
libtoolize -f -c
autoconf -f
autoheader -f
automake -a -c --add-missing
