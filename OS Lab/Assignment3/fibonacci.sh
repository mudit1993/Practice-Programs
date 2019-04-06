echo "Fibonacci Series"
a=-1
b=1
c=0
while [ $c -lt 18 ]
do
echo $c
c=`expr $a + $b`
a=$b
b=$c
done
