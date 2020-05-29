#!/bin/bash
echo "Enter Username"
read name
who | grep $name
exit 0
