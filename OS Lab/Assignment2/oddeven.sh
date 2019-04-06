echo "Enter a number"
read n
a=`expr $n % 2`
if [ $a -eq 0 ]
then
echo "Number is Even"
else
echo "Number is odd"
fi
