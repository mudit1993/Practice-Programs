#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef char* String;
void sort(String s)
{
    int i,j,temp;
    for(i=0;i<strlen(s);i++)
    {
        for(j=0;j<strlen(s)-i-1;j++)
        {
            if(s[j]>s[j+1])
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
void findSingleEclosure(String NFA[10][10],String init,int state)
{
    int i,j,k,h;
    for(i=0; NFA[state][2][i]!='\0'; i++)
        init[i]=NFA[state][2][i];

    for(j=0; NFA[state][2][j]!='\0'; j++)
    {
        h=NFA[state][2][j]-48;
        for(k=0; NFA[h][2][k]!='\0'; k++)
            init[i++]=NFA[h][2][k];
    }

    init[i]='\0';

    for(i=0; init[i]!='\0'; i++)
    {
        for(j=i+1; init[j]!='\0'; j++)
        {
            if(init[i]==init[j])
            {
                for(k=j; init[k]!='\0'; k++)init[k]=init[k+1];
                i=i-1;
            }
        }
    }
    sort(init);
}
void findSetEclosure(String NFA[10][10],String initE,String set)
{
    int i,j,k,h;
    String init=(String)malloc(sizeof(20));

    for(i=0; set[i]!='\0'; i++)
    {
        findSingleEclosure(NFA,init,set[i]-48);
        strcat(initE,init);
    }

    for(i=0; initE[i]!='\0'; i++)
    {
        for(j=i+1; initE[j]!='\0'; j++)
        {
            if(initE[i]==initE[j])
            {
                for(k=j; initE[k]!='\0'; k++)initE[k]=initE[k+1];
                i=i-1;
            }
        }
    }
    sort(initE);
}
void move(String NFA[10][10],String start,int symbol,String temp)
{
    int i,j,k=0;
    String t=(String)malloc(20);
    for(i=0; i<20; i++)
        t[i]='\0';
   
    for(i=0;start[i]!='\0';i++)
    {
        if(NFA[start[i]-48][symbol][0]!='o')
         {
          
            for(j=0;NFA[start[i]-48][symbol][j]!='\0';j++)
            temp[k++]=NFA[start[i]-48][symbol][j];
       	}
    }
    temp[k]='\0';
    for(i=0;i<strlen(temp);i++)
    {
        findSingleEclosure(NFA,t,temp[i]-48);
       strcat(temp,t);
    }
    for(i=0; temp[i]!='\0'; i++)
    {
        for(j=i+1; temp[j]!='\0'; j++)
        {
            if(temp[i]==temp[j])
            {
                for(k=j; temp[k]!='\0'; k++)temp[k]=temp[k+1];
                i=i-1;
            }
        }
    }
    sort(temp);
}
main()
{
    int n,in,i,j,flag,k;
    String NFA[10][10],DFA[10][10],init,initE,states[10],temp,symbols;
    printf("Enter the number of states\n");
    scanf("%d",&n);
    printf("Enter the number of input symbols\n\t");
    scanf("%d",&in);
    printf("Enter the NFA transition o for no transition\n");
    for(i=0; i<10; i++)
     {
        states[i]=(String)malloc(20);
        for(j=0; j<10; j++)
        {
            NFA[i][j]=(String)malloc(20);
            DFA[i][j]=(String)malloc(20);
        }
     }
    init=(String)malloc(20);
    symbols=(String)malloc(20);
    initE=(String)malloc(20);
    temp=(String)malloc(20);
    for(i=0; i<20; i++)
    {
        init[i]='\0';
        initE[i]='\0';
        temp[i]='\0';
    }
    for(j=0; j<=in; j++)
        {
        	if(j<in)symbols[j]=97+j;
        	else symbols[j]='E';
    		printf("\t%c",symbols[j]);
        }
    for(i=0; i<n; i++)
    {
        printf("\n%d\t",i);
        for(j=0; j<=in; j++)
        {
            scanf("%s",NFA[i][j]);
        }
    }
    findSingleEclosure(NFA,init,0);
    strcpy(states[0],init);
    findSetEclosure(NFA,initE,init);
    k=0;
    for(i=0;states[i][0]!='\0';i++)
    {
    	flag=1;
    	move(NFA,states[i],0,temp);
    	for(j=0;j<=k;j++)
    	{
    		if(!strcmp(states[j],temp)){flag=0;break;}
    	}
    	if(flag)
    	{strcpy(states[++k],temp);}
    	strcpy(DFA[i][0],temp);
    	flag=1;
    	move(NFA,states[i],1,temp);
    	for(j=0;j<=k;j++)
    	{
    		if(!strcmp(states[j],temp)){flag=0;break;}
    	}
    	if(flag)
    	{strcpy(states[++k],temp);}
    	strcpy(DFA[i][1],temp);
   }
    
    for(i=0;states[i][0]!='\0';i++)
    {
    if(DFA[i][0][0]=='\0')strcpy(DFA[i][0],"o");
    if(DFA[i][1][0]=='\0')strcpy(DFA[i][1],"o");
    }
    printf("%s\n",temp);
    printf("DFA\n");
    for(j=0;j<in;j++)
    printf("\t%c",symbols[j]);
    for(i=0;states[i][0]!='\0';i++)
    {printf("\n%s\t",states[i]);
    for(j=0;j<in;j++)
    {
    printf("%s\t",DFA[i][j]);
    }
    }
    printf("\n");
}
