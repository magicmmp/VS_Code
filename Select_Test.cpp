#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<sys/select.h>

#define BUFSIZE = 4096
const int rocID_List[32]={5,2,3,4,5,11,7,8,9,11,12,13,14,15,16,17,18,19,20};
 
int main()
{  
   
	char buff[BUFSIZ];
    
    int recv_len;
    int i,j;
    
    int PrintFlag[22];
    for(i=0;i<22;i++)
        PrintFlag[i]=0;
    int udp_fd[22];
    int maxFd=-1;
    struct sockaddr_in sin[22];
    if(rocID_List[0]>=22)
    for(i=0;i<22;i++)
    {
        bzero(&sin[i],sizeof(struct sockaddr_in));
        sin[i].sin_family=AF_INET;
        sin[i].sin_addr.s_addr=htonl(INADDR_ANY);
        sin[i].sin_port=htons(58880+i);
        udp_fd[i]=socket(AF_INET,SOCK_DGRAM,0);
        if(udp_fd[i]>maxFd)
            maxFd=udp_fd[i];
        bind(udp_fd[i],(struct sockaddr *)&sin[i],sizeof(struct sockaddr_in));
    }
    else
    for(i=0;i<rocID_List[0];i++)
    {
        bzero(&sin[i],sizeof(sin[i]));
        sin[i].sin_family=AF_INET;
        sin[i].sin_addr.s_addr=htonl(INADDR_ANY);
        sin[i].sin_port=htons(58880+rocID_List[i+1]);
        udp_fd[i]=socket(AF_INET,SOCK_DGRAM,0);
        if(udp_fd[i]>maxFd)
            maxFd=udp_fd[i];
        bind(udp_fd[i],(struct sockaddr *)&sin[i],sizeof(struct sockaddr_in));
    }
    maxFd=maxFd+1;

    
    fd_set 	ReadSet;
	struct timeval tv;

	while(1)
	{
		FD_ZERO(&ReadSet);
        for(i=0;i<rocID_List[0];i++)
		    FD_SET(udp_fd[i],&ReadSet);
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		
		switch (select(maxFd, &ReadSet, NULL,NULL, &tv)) 
		{  
			case -1:  
				printf("select =-1,error\n");
				break;  
			case 0:  
				break;
			default:
			{
                for(i=0;i<rocID_List[0];i++)
                if (FD_ISSET(udp_fd[i],&ReadSet))
				{
					recv_len=recvfrom(udp_fd[i],buff,BUFSIZ,0,NULL,NULL);
                    if(recv_len>0)
                    {
                        
                        if(PrintFlag[i]%10000==0)
                        {
                            printf("ROC %d Receive %d Bytes,Times=%d.\n",rocID_List[i+1]-1,recv_len,PrintFlag[i]);
                        }
                        PrintFlag[i]++;
                        
                    }
                    else
                    {
					    printf("UDP recv len=%d\n",recv_len);
				    }
					
				}
				break;
			}
		}
	}
    

    

   
    
   
    for(i=0;i<rocID_List[0];i++)
        close(udp_fd[i]);
	
	printf("UDP recv exit.\n");
   
  
   
}
