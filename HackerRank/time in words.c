#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *words[31];
    int h,m;
    words[0]="o' clock";
    words[1]="one";
    words[2]="two";
    words[3]="three";
    words[4]="four";
    words[5]="five";
    words[6]="six";
    words[7]="seven";
    words[8]="eight";
    words[9]="nine";
    words[10]="ten";
    words[11]="eleven";
    words[12]="twelve";
    words[13]="thirteen";
    words[14]="fourteen";
    words[15]="quarter";
    words[16]="sixteen";
    words[17]="seventeen";
    words[18]="eighteen";
    words[19]="nineteen";
    words[20]="twenty";
    words[30]="half past";
    scanf("%d%d",&h,&m);
    if(m==0)
        printf("%s %s\n",words[h],words[m]);
    else if(m==30)
        printf("%s %s\n",words[m],words[h]);
    else if(m>30)
    {
        m=60-m;
        if(m>20)
            printf("%s %s minutes to %s",words[20],words[m%10],words[(h%12)+1]);
        else{
                if(m==15)
                    printf("%s to %s",words[15],words[(h%12)+1]);
                else
                {
                    if(m==1)
                        printf("%s minute to %s",words[m],words[(h%12)+1]);
                    else
                        printf("%s minutes to %s",words[m],words[(h%12)+1]);
                }
            }
    }
    else if(m<30)
    {
        if(m>20)
            printf("%s %s minutes past %s",words[20],words[m%10],words[h]);
        else{
                if(m==15)
                    printf("%s past %s",words[15],words[h]);
                else
                {
                    if(m==1)
                    printf("%s minute past %s",words[m],words[h]);
                    else
                    printf("%s minutes past %s",words[m],words[h]);
                }
            }
    }
    return 0;
}
