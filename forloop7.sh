#!/bin/bash
for file in ~/.* ; do
    if [[ "$file" == "./data.txt" ]]
    then
        echo "$file is available"
        break
    fi
done
