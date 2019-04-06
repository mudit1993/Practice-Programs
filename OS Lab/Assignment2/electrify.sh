echo "Enter number of Units"
read n
if [ $n -ge 0 -a $n -le 200 ]
then
e=`echo 0.5 \* $n | bc`
elif [ $n -gt 200 -a $n -lt 401 ]
then
d=`expr $n - 200`
l=`echo $d \* 0.65 | bc`
e=`echo 100 + $l |bc`
elif [ $n -gt 400 -a $n -lt 601 ]
then
d=`expr $n - 400`
l=`echo $d \* 0.80 | bc`
e=`echo 150 + $l | bc`
elif [ $n -gt 600 ]
then
d=`expr $n - 600`
l=`echo $d \* 1 | bc`
e=`echo 200 + $l | bc`
fi
echo $e is the electricity bill 
