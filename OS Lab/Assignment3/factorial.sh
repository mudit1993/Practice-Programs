echo "Enter a number"
read n
i=1
fact=1
while [ $i -le $n ]
do
fact=`expr $i \* $fact`
i=`expr $i + 1`
done
echo Factorial value is $fact
