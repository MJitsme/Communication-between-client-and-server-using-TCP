//importing libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<ctype.h>

//Define global variables
#define MAX 100
#define PORT 9014
#define SA struct sockaddr
#define SAI struct sockaddr_in

//creating function to chat
void chat(int connfd)
{
  char buff[MAX];
  int n;
  while(1)
  {
    bzero(buff,MAX);
    read(connfd,buff,sizeof(buff));
    printf("message from client: %s",buff);
    if (strncmp(buff,"exit",4)==0)
    {
      printf("Server exits as Client exits.... ");
      break;
    }
    bzero(buff,MAX);
    printf("Enter the message to Client:");
    n=0;
    while((buff[n++]=getchar())!='\n');
    write(connfd,buff,sizeof(buff));
    if (strncmp(buff,"exit",4)==0)
    {
      printf("Server exits .... ");
      break;
    }
  }
}

//main function
int main()
{
  int connfd,sockfd,len;
  SAI server,client;
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  printf("Socket creation successful...\n");
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=htonl(INADDR_ANY);
  server.sin_port=htons(PORT);

  if((bind(sockfd,(SA*)&server,sizeof(server)))==0)
  {
    printf("Socket Binding successful\n");
  }
  else
  {
    printf("Socket Binding Failed");
    return 1;
  }

  if(listen(sockfd,5)==0)
  {
    printf("Server listening on port 9014\n");
  }
  else
  {
    printf("Server not listening...");
    return 1;
  }
  len=sizeof(client);
  connfd=accept(sockfd,(SA*)&client,(socklen_t*)&len);
  printf("Server accept client...\n");

  chat(connfd);
  close(sockfd);
  return 0;
}

