#!/bin/bash

seekInfo()
{
  echo -en "[*] Enter IP to scan : "
  read ip
  echo -en "[*] Enter ports to scan: \n"
  echo -en "\t\tStart port : "
  read start
  echo -en "\t\tEnd port : "
  read end
}

if  [ $# -lt 3 ]
then
  echo -en "[*] Less args passed , would be asking for input\n"
  echo -en "[*] Usage : ./$0 <IP_To_Scan> <Start_Port> <End_Port>\n"
  seekInfo
else
  ip=$1
  start=$2
  end=$3
fi

AllClosed=1
for i in $( seq $start $end)
do
  (echo -en "--hey port--" > /dev/tcp/$ip/$i &> /dev/null ) &> /dev/null
  if [ $? -eq  0 ]
  then
    AllClosed=0
    echo -en "[*] Port open : $i\n"
  fi
  echo -en "[#] Port $i not open\n" >> .checking.log
done
rm .checking.log
if [ AllClosed -eq 1 ]
then
  echo -en "[#] All ports are closed\n"
  exit 0
fi
