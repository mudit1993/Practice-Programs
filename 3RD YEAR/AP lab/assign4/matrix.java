import java.util.*;
class matrix
{
public static void main(String arg[])throws Exception
{
int r,c,i,j;
System.out.println("Enter no. of rows and columns of both matrix respectively");
Scanner s=new Scanner(System.in);
r=s.nextInt();
c=s.nextInt();
int a1[][]=new int[r][c];
int a2[][]=new int[r][c];
int rr[][]=new int[r][c];
int tr[][]=new int[c][r];
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
System.out.println("Enter element in row-"+(i+1)+" column-"+(j+1)+" of matrix A");
a1[i][j]=s.nextInt();
}
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
System.out.println("Enter element in row-"+(i+1)+" column-"+(j+1)+" of Matrix B");
a2[i][j]=s.nextInt();
rr[i][j]=a1[i][j]+a2[i][j];
tr[j][i]=rr[i][j];
}
}
System.out.println("Matrix A:");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
System.out.print(a1[i][j]+"\t");
}
System.out.println();
}
System.out.println("Matrix B:");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
System.out.print(a2[i][j]+"\t");
}
System.out.println();
}
System.out.println("Resultant Matrix");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
System.out.print(rr[i][j]+"\t");
}
System.out.println();
}
System.out.println("Transpose of the Resultant matrix:");
for(i=0;i<c;i++)
{
for(j=0;j<r;j++)
{
System.out.print(tr[i][j]+"\t");
}
System.out.println();
}
}
}