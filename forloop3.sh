#!/bin/bash  
for file in /root/*  
do  
    chmod 755 "$file"  
    echo "update permission for: $file"  
done 
