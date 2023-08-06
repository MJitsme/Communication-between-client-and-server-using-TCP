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
    scanf("%s",buff);
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

    
    
