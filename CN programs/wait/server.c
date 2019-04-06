#include <stdio.h>          /* These are the usual header files */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>


#define PORT 3550   /* Port that will be opened */ 
#define BACKLOG 2   /* Number of allowed connections */
#define MAXDATASIZE 100
#define MESSAGE_LENGTH 10

main()
{
 
  int fd, fd2; /* file descriptors that will refer to different sockets used in the program*/

  struct sockaddr_in server; /* server's address information */
  struct sockaddr_in client; /* client's address information */

  int sin_size;
  
  char buf[MAXDATASIZE];
  int numbytes;
  char * message = "My Message";
  int pointer;


  if ((fd=socket(AF_INET, SOCK_STREAM, 0)) == -1 ){  /* calls socket() */
    printf("socket() error\n");
    exit(-1);
  }

  server.sin_family = AF_INET;         
  server.sin_port = htons(PORT);  
  server.sin_addr.s_addr = INADDR_ANY;     
  bzero(&(server.sin_zero),8);
  
  if(bind(fd,(struct sockaddr*)&server,sizeof(struct sockaddr))==-1){ /* calls bind() */
      printf("bind() error\n");
      exit(-1);
  }     

  if(listen(fd,BACKLOG) == -1){  /* calls listen() */
      printf("listen() error\n");
      exit(-1);
  }

while(1){
  sin_size=sizeof(struct sockaddr_in);
  if ((fd2 = accept(fd,(struct sockaddr *)&client,&sin_size))==-1){ /* calls accept() */
    printf("accept() error\n");
    exit(-1);
  }
  
  //printf("You got a connection from %s\n",inet_ntoa(client.sin_addr) ); /* prints client's IP */
  
  //send(fd2,"Welcome to my server.\n",22,0); /* send to the client welcome message */
  
//  printf("\nMy Code\n");
  
	int i;
	
	send(fd2,(char *)&message[0],1,0);
	
	for (i=1; i<strlen(message); )
	{		
		if ((numbytes=recv(fd2,buf,MAXDATASIZE,0)) == -1)
		{
			printf("recv() error\n");
			exit(-1);
		}
		buf[numbytes]='\0';
		
		if (strcmp(buf, "ack0") == 0)
		{
			if (i%2 == 1)
				send(fd2,(char *)&message[++i],1,0);
			else
				send(fd2,(char *)&message[i],1,0);
		}
		else if (strcmp(buf, "ack1") == 0)
		{
			if (i%2 == 0)
				send(fd2,(char *)&message[++i],1,0);
			else
				send(fd2,(char *)&message[i],1,0);
		}
	}
  
  close(fd2); /*  close fd2 */
 }

 
}
