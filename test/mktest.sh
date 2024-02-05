#!/bin/bash

clear
cd ./test
echo "Test ID;Return code validation;Out result;StdErr result;File creation result;Global result" > ./results.csv

passed=0
failed=0
total=0
malformed=0

for i in Test*
do
  ./test.sh $i ../results.csv
  result=$?
  if [ $result -eq 0 ]
  then
    let "failed=$failed+1"
  elif [ $result -eq 1 ]
  then
    let "passed=$passed+1"
  else
    let "malformed=$malformed+1"
  fi
  let "total=$total+1"
done

echo "Passed tests     : $passed"
echo "Failed tests     : $failed"
echo "Malformed tests  : $malformed"
echo "--------------------"
echo "Total            : $total"
