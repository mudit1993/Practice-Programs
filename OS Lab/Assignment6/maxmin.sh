echo enter size of the array
read n
echo input $n values
i=0
while [ $i -lt $n ]
do
read a[$i]
i=`expr $i + 1`
done
max=${a[0]}
min=${a[0]}
i=1
while [ $i -lt $n ]
do
if [ ${a[$i]} -gt $max ]
then
max=${a[$i]}
fi
if [ ${a[$i]} -lt $min ]
then
min=${a[$i]}
fi
i=`expr $i + 1`
done
echo maximum value is $max 
echo minimum value is $min


