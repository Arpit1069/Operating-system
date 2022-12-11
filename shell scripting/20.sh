#! /bin/bash
echo "Enter a Number";
read n
temp=$n
while ((temp>0))
   do
      ans=$((ans*10))
      mod=$((temp%10))
      ans=$((ans+mod))
      temp=$((temp/10))
   done
if (($n == $ans))
   then
      echo "$n is a Palindrome Number"
   else
   echo "$n is not a Palindrome Number"
   fi
echo "Reverse  of $n is $ans"
