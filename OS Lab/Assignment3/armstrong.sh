echo "Enter a number"
read n
m=$n
cube=0
sum=0
dig=0
while [ $n -ne 0 ]
do
dig=`expr $n % 10`
n=`expr $n / 10`
cube=`expr $dig \* $dig \* $dig`
sum=`expr $sum + $cube` 
done
if [ $m -eq $sum ]
then
echo $m is an Armstrong Number
else
echo 
echo $m is not an armstrong number
fi
