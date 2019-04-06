c=0
for c in {0..99}
do
n=`expr $c % 2`
if [ $n -eq 0 ]
then
echo $c
fi
c=`expr $c + 1`
done 
