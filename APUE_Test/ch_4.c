#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char** argv)
{


/*
4.16 重命名一个文件:
   if(rename("/home/tuhao/VS_Code/APUE_Test/newname.txt","/home/tuhao/newname.txt")==-1) 
    {
        perror("rename error");
        return -1;
    }
    else
    {
        printf("rename success!\n");
    }

4.17 在当前目录创建一个符号链接，指向一个别处的文件:
    ln -s /home/tuhao/FileName  a_symbol_link_name

4.18 创建一个符号链接：
   if(symlink("/home/tuhao/VS_Code/APUE_Test/ch_4.c","/home/tuhao/symlink_ch_4.c")==-1) 
    {
        perror("create symlink error");
        return -1;
    }
    else
    {
        printf("create symlink success!\n");
    }
4.18 读取符号链接所指向文件的文件名：
    char LinkNameBuff[256];
    if(readlink("/home/tuhao/symlink_ch_4.c",LinkNameBuff,256)==-1) 
    {
        perror("readlink  error");
        return -1;
    }
    else
    {
        printf("LinkName= %s\n",LinkNameBuff);
    }
4.20 文件的访问时间、修改时间的更改：
    if(utimes("/home/tuhao/VS_Code/APUE_Test/ch_4.c",NULL)==-1) 
    {
        perror("utimes  error");
        return -1;
    }
    else
    {
        printf("utimes success!\n");
    }
4.21 先获取当前目录的权限，用于新建目录的默认权限参数：
    char buff[256];
    if(getcwd(buff,256)==NULL) 
    {
        perror("chdir 1  error");
        return -1;
    }
    else
    {
        printf("1. cwd=%s\n",buff);
    }
    struct stat statbuff;
    stat(buff,&statbuff);
4.21 新建目录：
    if(mkdir("dirMKbyFun",statbuff.st_mode)==-1) 
    {
        perror("mkdir  error");
        return -1;
    }
    else
    {
        printf("mkdir success\n");
    }
4.23 获取进程当前工作目录：
    char buff[256];
    if(getcwd(buff,256)==NULL) 
    {
        perror("chdir 1  error");
        return -1;
    }
    else
    {
        printf("1. cwd=%s\n",buff);
    }
4.23 更改当前工作目录：
    if(chdir("/home/tuhao/VS_Code/")==-1) 
    {
        perror("chdir  error");
        return -1;
    }
    else
    {
        printf("chdir success!\n");
    }
4.23 查看更改后的工作目录：
    if(getcwd(buff,256)==NULL) 
    {
        perror("chdir 2  error");
        return -1;
    }
    else
    {
        printf("2. cwd=%s\n",buff);
    }

*/


    return 0;
}