echo "Enter a number"
read n
m=$n
dig=0
sum=0
while [ $m -ne 0 ]
do
dig=`expr $m % 10`
sum=`expr $sum + $dig`
m=`expr $m / 10`
done
echo Sum of the digits is $sum
