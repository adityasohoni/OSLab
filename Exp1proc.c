#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

extern int errno;

void handle_sigint()
{
	exit(0);
}
int main()
{
	printf("\nEXECL\n");//EXECL
	printf("Before execl");
	//execl("/bin/ls", "ls", "-l", NULL);
	printf("After execl");
	/*
	printf("\nFORK\n");//FORK
	pid_t pid = fork();
	if(pid == 0) 
    	printf("this is a child: my new unique pid is %d\n", getpid());
 	else 
    	printf("this is the parent: my pid is %d and I have a child with pid %d \n", getpid(), pid);
	
    printf("\nFORK and WAIT\n");
    pid_t cpid; 
    if (fork()==0) 
        exit(0);           
    else
        cpid = wait(NULL); 

	
    printf("Parent pid = %d\n", getpid()); 
    printf("Child pid = %d\n", cpid);

    printf("\nEXIT\n");
    char choice;
    //choice = getchar();
    /*if(choice=='Q') 
    	exit(0);
    else
    	printf("Process Still Running\n");
*/
    printf("\nGET\n");
    printf("These are the following ids\n");
    printf("real user ID : %d\n",getuid());
    printf("effective user ID : %d\n",geteuid());
    printf("real group ID : %d\n",getgid());
    printf("effective group ID : %d\n",getegid());
    printf("process ID : %d\n",getpid());
    printf("parent process ID : %d\n",getppid());

    printf("\nSIGNAL\n");
    signal(SIGINT, handle_sigint); 
    /*while (1) 
    { 
        printf("hello world\n"); 
        sleep(1); 
    }
*/
    
    printf("\nKILL\n");//KILL
    kill (getppid(), SIGUSR1);


    printf("Alarm in 5 seconds\n");
	alarm(5);
	printf("\nALARM\n");


	printf("CHDIR");
	char s[100];
	printf("%s\n", getcwd(s, 100)); 
  
    
    chdir(".."); 
  
   
    printf("%s\n", getcwd(s, 100));
	





}

