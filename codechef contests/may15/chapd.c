#include<stdio.h>
#include<string.h>
 int aa[20],bb[20],cc[20],lena,lenb,inc[20],leni;
void change(char c){
    int i,flag=0;
    if(c=='a')
    {
        for(i=lena-1;i>=0;i--)
       {
           if(cc[i]==0 && flag==0){lena--;}
           else{
            flag=1;
           }
        aa[i]=cc[i];
       }
    }
    else{
      for(i=lenb-1;i>=0;i--)
       {
           if(cc[i]==0 && flag==0){lenb--;}
           else{
            flag=1;
           }
        bb[i]=cc[i];
       }
    }

}
  char subtract()
  {

      int lenc,flag=0;
      int i;
       for(i=0;i<19;i++)
            cc[i]=0;
      if(lena<lenb) lenc=lenb;
      else if(lena>lenb) {lenc=lena;flag=1;}
      else{
           for(i=lena-1;i>=0;i--)
           {
               if(aa[i]>bb[i])
               {
                   lenc=lena;flag=1;break;
               }
               else if(aa[i]<bb[i]){
                lenc=lenb;break;
               }
           }

      }

    //printf("%d,%d,%d,flag-%d\n",lena,lenb,lenc,flag);
       if(lenc==lena && flag==1){
            //printf("hello\n");
       for(i=0;i<lenc;i++)
       {
            //printf("aa[%d]=%d,bb[%d]=%d\n",i,aa[i],i,bb[i]);
           if(bb[i]>aa[i])
           {
            // printf("Inside-aa[%d]=%d,bb[%d]=%d\n",i,aa[i],i,bb[i]);
               cc[i]= (aa[i]+10) - bb[i];
              // printf("%d\n",cc[i]);
               aa[i+1]=aa[i+1]-1;
           }
           else{
            cc[i]=aa[i]-bb[i];
           }
         //  printf("%d-",cc[i]);
       }
       return 'a';
       }
       else{
        for(i=0;i<lenc;i++)
       {
           if(aa[i]>bb[i])
           {
               cc[i]=(bb[i]+10) - aa[i];
               bb[i+1]=bb[i+1]-1;
           }
           else{
            cc[i]=bb[i]-aa[i];
           }
       }
       return 'b';
       }
      //  printf("\n");
        // for(i=lenc-1;i>=0;i--)
          //  printf("%d",cc[i]);

  }
  int check_equal()
  {
      int i;
      if(lena==lenb)
      {
          for(i=0;i<lena;i++)
          {
              if(aa[i]!=bb[i]) return 0;
          }
          return 1;
      }
      else{
        return 0;
      }

}

void increment()
{
   int i,f=0;
   for(i=0;i<leni;i++)
    {
        if(i==0)
            inc[i]+=1;
        if(inc[i]>9)
        {
            inc[i]=0;
            leni++;
            inc[i+1]+=1;
        }
    }

}

int main()
{
    int t,i,lenc;
    char a[20],b[20];
    int aa1[20],bb1[20];
    scanf("%d",&t);
    while(t--)
    {
        leni=1;
        for(i=0;i<19;i++)
            inc[i]=a[i]=b[i]=0;
        scanf("%s%s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        lenc=lena;
        for(i=0;i<lena;i++)
           {
               aa[--lenc]=(int)(a[i]-48);
               aa1[lenc]=aa[lenc];
           }
        lenc=lenb;
        for(i=0;i<lenb;i++)
        {
            bb[--lenc]=(int)(b[i]-48);
            bb1[lenc]=bb[lenc];
        }
   char ch;
   while(lenb!=0 && lena!=0 )
   {
        change(subtract());

        if(check_equal())
            break;
   }
   for(i=lena;i<=18;i++)
        bb[i]=aa[i]=0;
   //printf("%d-%d",lena,lenb);
   /*
    for(i=0;i<lena;i++)
        printf("%d",aa[i]);
        printf(" ");
        for(i=0;i<lenb;i++)
        printf("%d",bb[i]);
        printf("\n");
*/
    if(aa[0]==1 && lena==1)
    {
        printf("No\n");
    }
    else{
    lenb=strlen(b);
    for(i=0;i<lenb;i++)
        bb[i]=bb1[i];//  bb contains the original number
    do{
         //   printf("Bef-lena=%d\n",lena);
           char ch=(subtract());

            if(ch=='a')  break;
           change(ch);
           increment();
     for(i=0;i<lenb;i++)
        printf("%d",bb[i]);
        printf(" ");
        //for(i=0;i<lenb;i++)
       // printf("%d",bb[i]);
       // printf("\n");
            printf("lena=%d,lenb=%d\n",lena,lenb);
       }while(lenb!=0);
       printf("leni=%d,",leni);
       for(i=leni-1;i>=0;i--)
        if(inc[i]==0)
            leni--;
            else break;
            lenb=leni;
            for(i=0;i<leni;i++)
                bb[i]=inc[i];
                lena=strlen(a);
            for(i=0;i<lena;i++)
                aa[i]=aa1[i];

        for(i=0;i<lena;i++)
        printf("%d",aa[i]);
        printf(" ");
        for(i=0;i<lenb;i++)
        printf("%d",bb[i]);
        printf("\n");
        do{
            char ch=(subtract());
            if(ch=='a')
           change('a');
           else break;
        }while(lena!=0);
        for(i=0;i<lena;i++)
            printf("%d,",aa[i]);
        if(check_equal())
            printf("Yes\n");
        else
            printf("No\n");
    }
}
return 0;
}
