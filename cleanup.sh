# !/bin/bash
# Author: Edson Alves - edsonalves@unb.br
# Date: 26/11/2010

# root directory
rm -f *~
rm -f aclocal.m4 configure Makefile.in Makefile
rm -f config.log config.status libtool
rm -rf config autom4te.cache

# include
cd include
rm -f *~
rm -f config.h config.h.in stamp-h1 Makefile.in Makefile
cd ..

# src
cd src
rm -f *~
rm -f config.h config.h.in stamp-h1 Makefile.in Makefile
rm -f *.o
rm -f ninjasiege
cd ..

# media
cd media
rm -f Makefile.in Makefile
