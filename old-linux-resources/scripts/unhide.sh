#!/bin/bash
#shopt -s dotglob

# Set directry var = to first argument passed 
dir=$1

cd $1

for file in .[^.]*; do
	if [ ! -d $file ]; # if file is not a directory
	then
		substring=$(echo $file | cut -c 2-)
		mv $file $substring
	fi
done
