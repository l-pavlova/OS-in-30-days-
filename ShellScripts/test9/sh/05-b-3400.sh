#!/bin/bash
read -p "Enter file name " fileName
read -p "Enter content to look for " string
grep -qF "${string}" "${fileName}"
echo $?

