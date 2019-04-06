echo 'Enter 2 numbers' 
read a b
c=`echo $a + $b |bc`
echo Sum is $c 
c=`echo $a \* $b |bc`
echo Product is $c
c=`echo $a - $b |bc` 
echo Difference is $c
c=`echo $a / $b |bc`
echo Quotient is $c
