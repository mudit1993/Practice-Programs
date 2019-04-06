echo enter size of the array
read n
i=0
while [ $i -lt $n ]
do
read a[$i]
i=`expr $i + 1`
done
echo Reverse order
i=`expr $n - 1`
while [ $i -ge 0 ]
do
echo ${a[$i]}
i=`expr $i - 1`
done
