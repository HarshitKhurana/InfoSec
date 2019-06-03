#!/bin/bash
if [ $# -lt 1 ]
then
  echo -en "[#] Pass the program name to compile\n"
  echo -en "[#] Usage:\n\t./$0 program.c\n"
  exit 1
else
  fileName=$1
  echo -en "[*] Compiling $fileName\n"
  outputName=`echo $fileName | cut -d "." -f 1`
  gcc -m32 -z execstack -fno-stack-protector $fileName -o $outputName
  echo -en ""
  exit 0
fi
