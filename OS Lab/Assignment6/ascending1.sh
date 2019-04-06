echo enter size of the array
read n
i=0
j=0
t=0
while [ $i -lt $n ]
do
read a[$i]
i=`expr $i + 1`
done
i=0
while [ $i -lt $n ]
do
s=$i
j=`expr $i + 1`
while [ $j -lt $n ]
do
if [ ${a[$s]} -gt ${a[$j]} ]
then
s=$j
fi
j=`expr $j + 1`
done
t=${a[$i]}
a[$i]=${a[$s]}
a[$s]=$t
i=`expr $i + 1`
done
echo Ascending order 
i=0
while [ $i -lt $n ]
do
echo ${a[$i]}
i=`expr $i + 1`
done
