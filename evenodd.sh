#!/bin/bash
read -p "Enter a number: " num

if [ $((num % 2)) -eq 0 ]
then
    echo "Your number is even"
else
    echo "Your number is odd"
fi
