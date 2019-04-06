#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
main()
{
int sockfd,fd1,length,ta1,i;
char buf[100],str[50];
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_STREAM,0);
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=INADDR_ANY;
sa.sin_port=6008;
i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
printf("test %d%d\n",sockfd,i);
listen(sockfd,5);
length=sizeof(sa);
fd1=accept(sockfd,(struct sockaddr *)&ta1,&length);
for(i=0;i<100;i++)
buf[i]='\0';
printf("Enter string");
scanf("%s",str);
strcpy(buf,str);
send(fd1,buf,100,0);

for(i=0;i<100;i++)
buf[i]='\0';

recv(fd1,buf,100,0);
printf("%s\n",buf);
close(fd1);

}
