#include <stdio.h> 
#include <stdbool.h>
/*int check_safety()
{
	int work[m+1];
	for(int i=1;i<=m;i++)
		work[i]=avail[i];
	bool finish[n+1];
	for(int i=1;i<=n;i++)
		finish[i]=false;
	int fc=0,flag;
	while(fc<n)
	{
		for(int i=1;i<=n;i++)
		{
			if(finish[i]==0)
			{
				flag=1;
				for(int j=1;j<=m;j++)
				{
					if(!need[i][j]<=work[j])
					{	flag=0;break; }
				}
			}
			if(flag==1)
			{
				for(int k=1;k<=m;k++)
					work[k]+=alloc[i][k];	
				finish[i]=1;	
				fc++;		
			}
		}
	}
}
 */


int main() 
{
	int n,m;
	printf("Enter the number of processes ");
	scanf("%d",&n);
	printf("Enter the number of resource types ");
	scanf("%d",&m);
	int max[n+1][m+1],alloc[n+1][m+1],need[n+1][m+1],avail[m+1];

	printf("Enter the Maximum Demand matrix\n");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&max[i][j]);

	printf("Enter the Allocation matrix\n");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}

	printf("Enter the Available array\n");
	for(int i=1;i<=m;i++)
		scanf("%d",&avail[i]);
	


	//SAFETY ALGORITHM
	int ss[n+1];
	int ssc=1;
	int work[m+1];
	for(int i=1;i<=m;i++)
		work[i]=avail[i];
	bool finish[n+1];
	for(int i=1;i<=n;i++)
		finish[i]=false;
	int fc=0,flag,bf=1;
	while(bf==1)
	{
		bf=0;
		for(int i=1;i<=n;i++)
		{
			
			if(finish[i]==false)
			{
				flag=1;
				for(int j=1;j<=m;j++)
				{
					if(need[i][j]>work[j])
					{	flag=0;break; }
				}
			
				if(flag==1)
				{
					//printf("\n%d was finished\n",i);
					bf=1;
					for(int k=1;k<=m;k++)
						work[k]+=alloc[i][k];	
					finish[i]=true;	
					fc++;
					ss[ssc++]=i;
				}
			}
		}
	}
	if(fc!=n)
		printf("There is no safe sequence\n");
	else
	{
		printf("The safe sequence is\n");
		for(int i=1;i<=n;i++)
			printf("%d ",ss[i]);
	}



}	
	