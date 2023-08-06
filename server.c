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
  char buff[max];
  int n;
  while(1)
  {
    bzero(buff,max);
    read(connfd,buff,sizeof(buff));
    printf("message from client: %s",buff);
    bzero(buff,max);
    printf("Enter the message to Client:");
    scanf("%s",buff);
    write(connfd,buff,sizeof(buff));
    if strncmp((buff,"exit",4)==0)
    {
      printf("Server exits .... ");
      break;
    }
  }
}

