#!/bin/bash
# chmod -R 777 copy_to.sh 

if [ $# -ne 2 ]; then
    echo "usage: "
    echo "./copy_to.sh file_path_to_paste name_of_file"
    exit 1
fi

dstdir=$1$2

if [ ! -d "$1" ]; then 
    echo "$1 does not exist"
    exit 1
else
    cp -i ./template.cpp "./$dstdir"
    echo -e "copy success."
fi