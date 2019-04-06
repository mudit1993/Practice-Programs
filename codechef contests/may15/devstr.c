#include<stdio.h>
int main()
{
    int t,flag;
    long int n,k,i,pos,sum,k1,k0;
    char s[100001],res[100001];

    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%ld%ld",&n,&k);
        scanf("%s",s);
        if(k==1)
        {
            for(i=0;i<n;i++)
            {
                if(i%2==0)// even having 1
                {
                    if(s[i]=='0')
                    {res[i]='1';sum++;}
                    else
                     res[i]=s[i];
                }
                else{
                    if(s[i]=='1')
                    {res[i]='0';sum++;}
                    else
                     res[i]=s[i];
                }
            }
            if(sum<(n-sum))
            {
                printf("%ld\n",sum);
                for(i=0;i<n;i++)
                    printf("%c",res[i]);
                    printf("\n");
            }
            else{
                printf("%ld\n",n-sum);
                for(i=1;i<n;i++)
                printf("%c",res[i]);
                printf("%c\n",res[n-2]);
            }
        }
        else{ // k>=2
                pos=0;
                k1=k0=0;
                sum=0;
                flag=0;
                for(i=0;i<n;i++)
                {
                    if(s[i]=='1')
                    {
                        k1++;
                        if(k1>k)   //  check if k1 exceeds the limit of k
                        {
                            //printf("k0=%ld,k1=%ld,i=%ld,pos=%ld, (i-k)=%ld\n",k0,k1,i,pos,i-k);
                            if(pos==(i-k) && flag==1)
                            {
                               // printf("i=%ld,pos=%ld, (i-k)=%ld\n",i,pos,i-k);
                                s[pos-1]=s[pos];
                                s[pos]='0';
                                pos++;
                                flag=0;
                                printf("%s\n",s);
                            }
                            else{
                            pos=i;      //saving the flipped position
                            s[i]='0';
                            k0=1;
                            flag=1;
                            sum++;
                            k1=0;
                            printf("%s\n",s);
                            }
                        }
                        else if(k0>0)
                        {
                          k0=0;
                          //flag=0;
                          //pos=i;
                        }
                    }
                    else{
                        k0++;

                        if(k0>k)   //  check if k0 exceeds the limit of k
                        {
                            //printf("k0=%ld,k1=%ld,i=%ld,pos=%ld, (i-k)=%ld\n",k0,k1,i,pos,i-k);
                             if(pos==(i-k) && flag==1)
                            {
                               // printf("i=%ld,pos=%ld\n",i,pos);
                                s[pos-1]=s[pos];
                                s[pos]='1';
                                pos++;
                                flag=0;
                                //printf("%s\n",s);
                            }
                            else{
                            pos=i;      //saving the flipped position
                            s[i]='1';
                            k1=1;
                            flag=1;
                            sum++;
                            k0=0;
                            printf("%s\n",s);
                            }
                        }
                        else if(k1>0)
                        {
                         k1=0;
                            //flag=0;
                        }

                    }

                }
                printf("%ld\n",sum);
                for(i=0;i<n;i++)
                    printf("%c",s[i]);
                printf("\n");
        }

    }

return 0;
}
