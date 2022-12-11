#!/bin/bash
os=('windows' 'Ubuntu' 'linux')
os[3]='mac'
unset os[2]
echo "${os[@]}"
echo "${os[0]}"
echo "${!os[@]}"
echo "${#os[@]}"