#!/bin/bash
#
# copy.sh DESTDIR TARGETS
#
# Copy the TARGETS to DESTDIR.  Relative paths are preserved
# e.g. copy.sh /foo bar/baz will copy bar/baz to /foo/bar/baz
#
# $Id: copy.sh,v 1.2 2013/04/17 22:27:18 klautsan Exp $

# Exit if errors are encountered
set -e

DEST=$1
shift

for file
do
   target=$DEST/$file
   dir=`dirname $target`
   test -d $dir || mkdir -p $dir
   if [ ! -e $target -o $file -nt $target ]; then
      cp -pf $file $target
   fi
done
