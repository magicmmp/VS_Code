#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;
char* env_init[]={"USER=unknown","PATH=/home/tuhao/VS_Code/APUE_Test",NULL};

int gval=8;

int main()
{
/*8.3 函数fork的使用*/
    int lVal=2;
    pid_t pid;
/*
    printf("Before fork\n");

    if((pid=fork())<0)
        perror("fork error");
    else if(pid==0)
    {
        gval=100;
        lVal=101;
    }
    else
        sleep(1);
    if(pid>0)
        write(STDOUT_FILENO,"Parent pid\n",strlen("parent pid\n"));
    else if(pid==0)
        write(STDOUT_FILENO,"Child  pid\n",strlen("parent pid\n"));
    printf("pid=%ld,gval=%d,lval=%d\n",(long)getpid(),gval,lVal);
*/
/*8.10 函数exec的使用*/

    if((pid=fork())<0)
        perror("execle fork error");
    else if(pid==0)
    {
        if(execle("/home/tuhao/VS_Code/APUE_Test/echoall","arg1","execle",(char*)0,env_init)<0)
            perror("execle error");
    }
    if(waitpid(pid,NULL,0)<0)
        perror("wait error");
    
    if((pid=fork())<0)
        perror("execlp fork error");
    else if(pid==0)
    {
        if(execlp("./echoall","arg1","exelp",(char*)0)<0)
            perror("execlp error");
    }
    if(waitpid(pid,NULL,0)<0)
        perror("wait error");
    
/*8.13 函数system的使用*/
    if(system("./echoall")<0)
        perror("system() error");
    

    




    return 0;

}







