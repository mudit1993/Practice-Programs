echo enter size of the array
read n
i=0
vow=0
while [ $i -lt $n ]
do
read a[$i]
case ${a[$i]} in
a)
vow=`expr $vow + 1`;;
e)
vow=`expr $vow + 1`;;
i)
vow=`expr $vow + 1`;;
o)
vow=`expr $vow + 1`;;
u)
vow=`expr $vow + 1`;;
A)
vow=`expr $vow + 1`;;
E)
vow=`expr $vow + 1`;;
I)
vow=`expr $vow + 1`;;
O)
vow=`expr $vow + 1`;;
U)
vow=`expr $vow + 1`;;
*)
esac
i=`expr $i + 1`
done
echo "Vowels:" $vow
echo "Consonants:" `expr $n - $vow`
