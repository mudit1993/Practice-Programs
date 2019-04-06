#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
main()
{
int i,k=0,sockfd,a,b;
char buf[100];
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_STREAM,0);
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=6008;
i=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));
for(i=0;i<100;i++) buf[i]='\0';
recv(sockfd,buf,100,0);
printf("%s",buf);
int flag=0;
int len=strlen(buf);
for(i=0;i<len/2;i++)
{
if(buf[len-i-1]!=buf[i]) {flag=1;break;}
}
for(i=0;i<100;i++)
buf[i]='\0';
if(flag==0)
strcpy(buf,"yes, a palindrome");
else
strcpy(buf,"Not a palindrome");
send(sockfd,buf,100,0);
close(sockfd);
}
