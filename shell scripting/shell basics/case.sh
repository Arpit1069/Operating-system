#!/bin/bash

read choice

case $choice in 
            1)date;;
            2)ls -ltr;;
            3)pwd;;
            *) echo not a valid choice
esac