#!/bin/sh

for test in *.js
do
  echo $test
  if node $test; then
    printf "\e[32m ... ok\n\e[39m"
  else
    printf "\e[31m ... error\n\e[39m"
  fi
done
