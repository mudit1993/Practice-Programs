echo "Enter a number"
read n
m=$n
sum=0
fact=1
d=0
while [ $fact -lt $m ]
do
d=`expr $m % $fact`
if [ $d -eq 0 ]
then
sum=`expr $fact + $sum`
fi
fact=`expr $fact + 1`
done
if [ $sum -eq $n ]
then
echo $n is a Perfect Number
else
echo $n is not a Perfect Number
fi
