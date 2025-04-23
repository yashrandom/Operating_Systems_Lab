#!/bin/bash
auth_user="admin"
read -p "What's your name? " user

if [[ "$user" == "$auth_user" ]]; then
    echo "You are an administrator"
elif [[ -z "$user" ]]; then
    echo "Please enter a username"
    read user
    echo "Hello $user, Greetings!"
else
    echo "You are a standard user"
fi
