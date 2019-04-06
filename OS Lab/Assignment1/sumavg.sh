echo Enter three values
read a b c
d=`expr $a + $b + $c`
e=`echo $d \* 0.33 |bc`
echo Sum is $d
echo Average is $e
