echo "Enter 3 values"
read a b c
if [ $a -gt $b ]
then
if [ $a -gt $c ]
then
echo $a is the greatest number
fi
else 
if [ $b -gt $c ]
then
echo $b is the greatest number
else
echo $c is the greatest number
fi
fi
