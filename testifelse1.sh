#!/bin/bash
if [ -f data.txt ]; then
    echo "File exists"
else
    touch data.txt
    echo "New file created"
fi
