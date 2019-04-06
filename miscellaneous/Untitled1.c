#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char x[1001],y[20];
    scanf("%d",&t);
    int arr[10][4] = {{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};
    while(t--)
    {
        int lx, ly, a, b, c;
        scanf("%s %s",x,y);
        lx = strlen(x);
        ly = strlen(y);
        a = (x[lx-1]-'0')%10;
        b = (ly>=2)?((y[ly-2]-'0')*10 + (y[ly-1]-'0')):(y[ly-1]-'0');
        if(b==0 && ly==1)
            printf("1\n");
        else
        {
            c = (b%4)-1;
            if(c<0)
                c=c+4;
            printf("%d\n",arr[a][c]);
        }
    }
    return 0;
}
