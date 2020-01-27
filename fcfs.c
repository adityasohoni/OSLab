//FCFS

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
	printf("Enter the process id, arrival time and burst time for all the processes\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&p[i].id,&p[i].a,&p[i].b);
		//p[i].id=i+1;
	}
	qsort(p,n,sizeof(struct process),compare);
	printf("CPU Idle Time\n");

	for(int i=0;i<n;i++)
	{
		if(i==0)
		{	
			p[i].ta=p[i].b;
			p[i].c=p[i].a+p[i].ta;
			p[i].w=0;
			if(p[i].a>0)
				printf("0 -> %d\n",p[i].a);
		}
		else
		{
			if(p[i].a>=p[i-1].c)
			{
				if(p[i].a>p[i-1].c)
					printf("%d -> %d\n",p[i-1].c,p[i].a);
				p[i].ta=p[i].b;
				p[i].c=p[i].a+p[i].ta;
				p[i].w=0;
			}
			else
			{
				p[i].w=p[i-1].c-p[i].a;
				p[i].ta=p[i].w+p[i].b;
				p[i].c=p[i].a+p[i].ta;
			}
		}
	}
	printf("\nProcess id   Turnaround Time     Wait Time\n");
	for(int i=0;i<n;i++)
	{
		printf("%d          %d                    %d\n",p[i].id,p[i].ta,p[i].w);
	}
	printf("Number of Context Switches : %d",n-1);
	
}