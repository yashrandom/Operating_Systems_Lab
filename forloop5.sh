#!/bin/bash  
for serverd in A B C; do  
    for app in apache dp; do  
        echo "$serverd can run $app LAMP package"  
    done  
done
