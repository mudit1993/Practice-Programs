echo "Enter a number"
read a
if [ $a -gt 0 ]
then 
echo "Number is positive"
elif [ $a -lt 0 ]
then
echo "Number is Negative"
else
echo "Number is Zero"
fi
