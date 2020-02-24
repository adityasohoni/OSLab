//Round Robin
//FCFS
#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct process 
{
	int id;
	int a; 
	int b; 
	int ta;
	int w;
	int c;    
};





int compare(const void* x, const void* y)
{
	if(((struct process*)x)->a>((struct process*)y)->a)
		return 1;
	else
		return 0;
}

void main()
{
	int n;

	
	printf("Enter the number of processes ");
	scanf("%d",&n);
	struct process p[n];
	int arrs[40][n];
	int arrsub[n];
	for(int i=0;i<n;i++)
		ub[i]=-1;
	printf("Enter the process id, arrival time and burst time for all the processes\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&p[i].id,&p[i].a,&p[i].b);
		arrs[p[i].a][++arrsub[p[i].a]]-p[i].id;
	}
	
	int curr[n];
	int currub=-1;
	int currcnt=0;
	for(int i=0;;i++)
	{
		for(int j=0;j<=arrsub[i];j++)
			curr[++currub]=arrs[i][j];
		currub++;
		p[curr[(currcnt)%(currub)]].b--;
		if(p[curr[(currcnt)%(currub)]].b==0)
		{
			for(int k=0;i)
		}
		currcnt++;
	}

	printf("\nProcess id   Turnaround Time     Wait Time\n");
	for(int i=0;i<n;i++)
	{
		printf("%d          %d                    %d\n",p[i].id,p[i].ta,p[i].w);
	}
	printf("Number of Context Switches : %d",n-1);
	
}