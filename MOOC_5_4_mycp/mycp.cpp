#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include <errno.h>
#include<string>


extern errno;

using namespace std;

int N=0;  /*普通文件计数*/
string Dstpath("~");

/*实现了计算目录下所有普通文件个数，至于文件复制功能，以后再改进。*/
int FileCopy(string FileName,string DstPath)
{
    printf("File name= %s\n",FileName.c_str());
    N++;
    return 0;
}

int ReadPath(string Srcpath)
{
    string substr("/.");
    if(Srcpath.find(substr)!=-1)  /*不计算隐含文件*/
        return 0;
    DIR * dir;  /*与文件名关联的目录流*/
    struct dirent *DirentBuff;  /*被打开目录下的一个子文件*/
    struct stat statBuff;
    
	if (lstat(Srcpath.c_str(), &statBuff) < 0)	/* stat error */
	{
        printf("%s :can't stat!\n",Srcpath.c_str());
        return -1;
    }
    
	if (S_ISDIR(statBuff.st_mode) == 0)	/* not a directory */
		return FileCopy(Srcpath,Dstpath);
    else  /*是目录则打开目录*/
    {
        if ((dir = opendir(Srcpath.c_str())) == NULL)	/* can't read directory */
		{
            printf("dir: %s can't open!",Srcpath.c_str());
            return -1;
        }

	    while ((DirentBuff = readdir(dir)) != NULL) 
	    {
		    if (strcmp(DirentBuff->d_name, ".") == 0  || strcmp(DirentBuff->d_name, "..") == 0)
				continue;		/* ignore dot and dot-dot */
            
		    if (ReadPath(Srcpath +'/' + DirentBuff->d_name)!= 0)		/* recursive */
			    break;	/* time to leave */
	    }
	    if (closedir(dir) < 0)
        {
            printf("can't close directory :%s\n",Srcpath.c_str());
            return -1;
        }
		    
    }
    return 0;
}


int main(int argc, char* argv[])
{
    ReadPath("/home/tuhao/");
    printf("N= %d\n",N);
    return 0;

}