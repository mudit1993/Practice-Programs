echo "Enter a number"
read n
i=2
flag=0
while [ $i -lt $n ]
do
if [ `expr $n % $i` -eq 0 ]
then
flag=1
fi
i=`expr $i + 1`
done
if [ $flag -eq 1 ]
then
echo $n is Not a Prime Number
else
echo $n is a Prime Number
fi
