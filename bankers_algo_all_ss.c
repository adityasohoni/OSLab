#include <stdio.h> 
#include <stdbool.h>
int n,m,ssl;
int max[9][9],alloc[9][9],need[9][9],avail[9],ss[9];
bool finish[9];

void check_safety()
{
	int flag;
	if(ssl==n)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",ss[i]);
		printf("\n");
		return;
	}
	int k;
	for(int i=1;i<=n;i++)
	{
			
		if(finish[i]==false)
		{
			flag=1;
			for(int j=1;j<=m;j++)
			{
				if(need[i][j]>avail[j])
				{	flag=0;break; }
			}
			
			if(flag==1)
			{
				
				ssl++;
				ss[ssl]=i;
				for(int k=1;k<=m;k++)
					avail[k]+=alloc[i][k];	
				finish[i]=true;	
				check_safety();
				ssl--;
				for(int k=1;k<=m;k++)
					avail[k]-=alloc[i][k];	
				finish[i]=false;
			}
		}
	}


}



int main() 
{
	
	printf("Enter the number of processes ");
	scanf("%d",&n);
	printf("Enter the number of resource types ");
	scanf("%d",&m);

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


	
	
	for(int i=1;i<=n;i++)
		finish[i]=false;


	ssl=0;
	check_safety();
	

}	
	
