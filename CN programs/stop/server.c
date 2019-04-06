#include <stdio.h>          /* These are the usual header files */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>


#define PORT 3550   /* Port that will be opened */ 
#define BACKLOG 2   /* Number of allowed connections */
#define MAXDATASIZE 100

main()
{
 
  int fd, fd2; /* file descriptors that will refer to different sockets used in the program*/

  struct sockaddr_in server; /* server's address information */
  struct sockaddr_in client; /* client's address information */

  int sin_size;
  
  char buf[MAXDATASIZE];
  int numbytes;


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
  
	int j;
	
	send(fd2,"New Packet recieved\n",20,0);
	
	for (j=0; j<4; j++)
	{
		if ((numbytes=recv(fd2,buf,MAXDATASIZE,0)) == -1)
		{
			printf("recv() error\n");
			exit(-1);
		}
		
		buf[numbytes]='\0';
		if (strcmp(buf, "ack") == 0)
		{
			send(fd2,"New Packet recieved\n",20,0);
		}
	}
  
  close(fd2); /*  close fd2 */
 }

 
}
