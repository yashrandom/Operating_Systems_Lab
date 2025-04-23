#!/bin/bash
user="admin"
adminstrator="admin"

if [ "$user" = "$adminstrator" ]; then
    echo "The strings match"
else
    echo "The strings do not match"
fi
