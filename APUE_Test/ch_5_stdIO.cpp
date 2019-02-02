#include<stdio.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main()
{

    /*5.7 fgets一次从文件fd读取一行，总是把换行符和null写在末尾。*/
    char buff[128];
    memset(buff,0,sizeof(buff));
    fgets(buff,128,stdin);
    printf("%s",buff);
    for(int i=0;i<10;i++)
        printf("%d, ",buff[i]);
    printf("\n");
    


}