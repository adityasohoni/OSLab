#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h>
extern int errno; 
int main() 
{   

	char filename[]="expt1.txt";

	printf("\nCREATE\n");//CREA
	int fd=creat(filename,S_IRWXU);
	printf("fd = %d\n", fd);

	printf("\nOPEN\n");//OPEN
    fd = open(filename, O_RDWR);
    printf("fd = %d\n", fd);

    printf("\nWRITE\n");//Write
    write(fd, "This is Experiment One\n", strlen("This is Experiment One\n")); 
    

    printf("\nLINK\n");//LSEEK
    lseek(fd,0,SEEK_SET);
    
    printf("\nREAD\n");//READ
    char c[100]; 
    int sz=read(fd, c, strlen("This is Experiment One\n"));
    printf("This is what was read : \n%s\n", c); 
    
    printf("\nDUPLICATE\n");//Duplicate
    int cpy = dup(fd);
    printf("This is the normal file descriptor -> %d\nThis is the duplicate file descriptor -> %d\n",fd,cpy);

    printf("\nLINK\n");//LINK
	#define NEWLINK "EXP1cpy.txt"
	int lk=link (filename, NEWLINK);
    printf("lk = %d\n", lk);
    perror("link");
    
    printf("\nDELINK\n");//DELINK
	//lk=unlink (NEWLINK);
    printf("lk = %d\n", lk);

    printf("\nACCESS\n");
    int ac=access(filename,F_OK);
    printf("%d\n",ac);

    printf("\nCHMOD\n");
    int chm=chmod(filename,S_IWUSR);
    printf("%d\n",chm);

    printf("\nCHOWN\n");
    int cow=chown(filename,00,12);
    printf("%d\n",cow);
    perror("CHOWN");

    printf("\nMASK\n");
    umask(0000);
    creat("umsk.txt",666);

    
    //Print
    printf("fd = %d\n", fd); 
    
    
    close(fd);  
    
} 
