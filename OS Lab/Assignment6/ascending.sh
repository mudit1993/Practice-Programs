echo enter size of the array
read n
i=0
j=0
c=0
t=0
d=0
while [ $i -lt $n ]
do
read a[$i]
i=`expr $i + 1`
done
i=0
j=0
while [ $i -lt $n ]
do
d=`expr $n - $i - 1`
while [ $j -le $d ]
do
c=`expr $j + 1`
if [ ${a[$j]} -gt ${a[$c]} ]
then
t=${a[$j]}
a[$j]=${a[$c]}
a[$c]=$t
fi
j=`expr $j + 1`
done
j=0
i=`expr $i + 1`
done
echo Ascending order 
i=0
while [ $i -lt $n ]
do
echo ${a[$i]}
i=`expr $i + 1`
done
