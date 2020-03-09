#include<stdio.h>
int main()
{
	int b,n;
	printf("Enter the number of processes ");
	scanf("%d",&n);
	printf("Enter the size of each processs\n");
	int prsz[n];
	for(int i=0;i<n;i++)	
		scanf("%d",&prsz[i]);

	printf("Enter the number of blocks ");
	scanf("%d",&b);
	printf("Enter the size of each block\n");
	int bsz[b];
	for(int i=0;i<b;i++)	
		scanf("%d",&bsz[i]);

	int ans[n];
	for(int i=0;i<n;i++)
		ans[i]=-1;
	int alloc[b];
	for(int i=0;i<b;i++)
		alloc[i]=0;
	int pos,max,j;
	//printf("HI\n");
	for(int i=0;i<n;i++)
	{
		max=0;
		pos=b;
		for(j=0;j<b;j++)
		{
			
			if((alloc[j]==0) && (bsz[j]>=prsz[i]) && (bsz[j]>max))
			{
				//alloc[j]=1;
				pos=j;
				max=bsz[j];
				ans[i]=j;
			}
			
		}
		//printf("%d %d\n",i,pos);
		alloc[pos]=1;
	}
	printf("The Process ID, Block Number and Internal Fragmentation\n");
	for(int i=0;i<n;i++)
		printf("%d %d %d\n",i,ans[i],bsz[ans[i]]-prsz[i]);
	//for(int i=0;i<b;i++)
		//printf("%d ",alloc[i]);

	int extfr=0;
	for(int i=0;i<b;i++)
		if(!alloc[i])
			extfr+=bsz[i];

	printf("External Fragmentation %d\n",extfr);

}