#include<stdio.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main()
{
/*3.12  函数dup和dup2  
    int fd3=dup(STDOUT_FILENO);
    printf("fd3=%d\n",fd3);
    write(fd3,"write with fd3.\n",strlen("write with fd3.\n"));
 */
    /* fgets一次从文件fd读取一行，总是把换行符和null写在末尾。*/
    char buff[128];
    memset(buff,0,sizeof(buff));
    fgets(buff,128,stdin);
    printf("%s",buff);
    for(int i=0;i<10;i++)
        printf("%d, ",buff[i]);
    printf("\n");
    


}