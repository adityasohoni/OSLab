#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	
	cout<<"Enter the length of the page string.\n";
	cin>>n;
	int p[n+1];
	set<int> s;
	//map<int,int> lp;
	cout<<"Enter the page frame size.\n";
	int pframe;
	cin>>pframe;
	int currsize=0;
	int phit=0,pfault=0;
	
	cout<<"Enter the page string.\n";
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		if(s.count(p[i]))
			phit++;
		else
		{
			pfault++;
			if(s.size()==pframe)
			{				
				int ans;
				int maxm=0;
				int val=*(s.begin());
				int finalval=*(s.begin());
				for(set<int>::iterator x=s.begin();x!=s.end();x++)
				{
					ans=INT_MAX;
					val=*x;
					for(int j=i+1;j<=n;j++)
					{
						if(p[j]==*x)
						{
							ans=j;
							val=*x;
							break;
						}
					}
					if(ans>maxm)
					{
						maxm=ans;
						finalval=val;
					}
				}
				s.erase(finalval);
				cout<<finalval<<" was erased\n";
			}
			s.insert(p[i]);
		}
	}
	cout<<"The number of page hits is "<<phit<<endl;
	cout<<"The number of page faults is "<<pfault<<endl;

}