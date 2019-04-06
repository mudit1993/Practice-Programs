echo "Enter a number"
read n
i=1
echo Factors of $n are
while [ $i -le $n ]
do
if [ `expr $n % $i` -eq 0 ]
then
echo $i
fi
i=`expr $i + 1`
done
