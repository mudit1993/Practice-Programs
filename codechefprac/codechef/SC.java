import java.io.*;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Class Cshortcuts
{
void main()
{
int T,N,Q,i,j,A,B,cnt;
char MAP[200];
do{
scanf("%d",&T);
}while(T<1 ||T>10);
while(T!=0)
{
    cnt=0;
    do{
scanf("%d",&N);
    }while(N<1 || N>200);
//char MAP[N][N];
for(i=0;i<N;i++)
{
   // for(j=0;j<N;j++)
    //{
       scanf("%s",&MAP[i]);
    //}
}
do{scanf("%d",&Q);}while(Q>2000 || Q<1);
while(Q!=0)
{
    do{
scanf("%d%d",&A,&B);
}while((A>=N && B>=N)|| (A<0&&B<0));
Q--;
}
i=B;
if(MAP[A]=='Y'|| MAP[A]=='y')
    printf("1\n");
else{
while(A!=B)
{
if(MAP[A]=='Y'||MAP[A]=='y')
{
    cnt++;
    A=i;
    i=B;
}
else{
    i--;
}
}
System.out.println(cnt);
}
T--;
}

}

