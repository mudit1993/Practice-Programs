echo Enter number of days
read d
m=`expr $d / 30`
da=`expr $d - \( $m \* 30 \)`
echo $m months $da days
