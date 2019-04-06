echo "Enter a number"
read m
rev=0
dig=0
while [ $m -ne 0 ]
do
dig=`expr $m % 10`
rev=`expr \( $rev \* 10 \) + $dig`
m=`expr $m / 10`
done
echo Reversed number is $rev
