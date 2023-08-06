//importing libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

//defining global variables
#define MAX 100
#define PORT 9014
#define SA struct sockaddr
#define SAI struct sockaddr_in

//function for chat
void chat(int sockfd)
{
  char buff[MAX];
  int n;
  while(1)
  {
    bzero(buff,MAX);
    printf("Enter the message to server: \n");
    n=0;
    while((buff[n++]=getchar())!='\n');
    write(sockfd,buff,sizeof(buff));
    bzero(buff,MAX);
    read(sockfd,buff,sizeof(buff));
    if(strncmp(buff,"exit")==0)
    {
      printf("Client exits ....");
      break;
    }
    printf("Message from server: %s\n",buff);
  }
}


//main function
int main()
{
  int sockfd;
  SAI server;
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  printf("Socket created successfully...");

  server.sin_family=AF_INET;
  server.sin_addr.s_addr=htonl(INADDR_ANY);
  server.sin_port=htons(PORT);

  if(connect(sockfd,(SA*)&server,sizeof(server))==0)
    printf("Connected to server successfully...\n");
  else
  {
    printf("Connection to server failed!..");
    return 1;
  }
  chat(sockfd);
  close(sockfd);
  return 0;
}
