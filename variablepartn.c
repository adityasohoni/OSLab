#include<stdio.h>
int main()
{
	int n,m;
	printf("Enter the number of processes ");
	scanf("%d",&n);
	printf("Enter the size of each processs\n");
	int prsz[n];
	for(int i=0;i<n;i++)	
		scanf("%d",&prsz[i]);

	printf("Enter the Total Memory size ");
	scanf("%d",&m);

	int ans[n][2];
	int st=0;
	for(int i=0;i<n;i++)
	{
		ans[i][0]=st;
		ans[i][1]=st+prsz[i]-1;
		st=ans[i][1]+1;
	}
	printf("The Process ID Start Address and End Address\n");
	for(int i=0;i<n;i++)
	{	
		if(ans[i][1]>m)
		{
			ans[i][1]=-1;
			ans[i][0]=-1;
		}
		printf("%d %d %d\n",i,ans[i][0],ans[i][1]);

	}
	printf("The External Fragmentation %d",m-ans[n-1][1]-1);

}