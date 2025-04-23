#!/bin/bash
for log in $(cat ~/testfile)
do
    echo "Log entry: $log"
done
