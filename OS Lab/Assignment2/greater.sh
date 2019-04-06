echo "ENTER 2 VALUES"
read a b
if [ $a -gt $b ]
then
echo $a is greater than $b
elif [ $b -gt $a ]
then
echo $b is greater than $a
else
echo "Numbers are equal"
fi
