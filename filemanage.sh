#!/bin/bash

echo "Enter directory name:"
read d
mkdir $d

echo "Enter file name:"
read f
touch $f

echo "Files and Directories:"
ls

echo "Current Directory:"
pwd

echo "Deleting file..."
rm $f

echo "Removing directory..."
rmdir $d

echo "Done."
