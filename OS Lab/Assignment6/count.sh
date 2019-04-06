echo enter array size
read n
i=0
even=0
while [ $i -lt $n ]
do
read a[$i]
c=`echo ${a[$i]} % 2 |bc`
if [ $c -eq 0 ]
then
even=`expr $even + 1`
fi
i=`expr $i + 1`
done
echo "even:" $even
echo "odd:" `expr $n - $even`
