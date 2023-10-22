#!/bin/sh
FileName="NodeCustomize"
killall -15 $FileName
$(pwd)/$FileName $(pwd)/config/list.conf
