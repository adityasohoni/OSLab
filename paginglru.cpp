#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,p;
	vector<int> ps(n+1);
	cout<<"Enter the length of the page string.\n";
	cin>>n;
	set<int> s;
	map<int,int> lut;
	cout<<"Enter the page frame size.\n";
	int pframe;
	cin>>pframe;
	int currsize=0;
	int phit=0,pfault=0;
	cout<<"Enter the page string.\n";
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		if(s.count(p))
			phit++;
		else
		{
			pfault++;
			if(s.size()==pframe)
			{
				int min=INT_MAX;
				int temp;
				for(set<int>::iterator x=s.begin();x!=s.end();x++)
					if(lut[*x]<min)
					{
						temp=*x;
						min=lut[*x];
					}
				s.erase(temp);
			}
			s.insert(p);
		}
		lut[p]=i;
	}
	cout<<"The number of page hits is "<<phit<<endl;
	cout<<"The number of page faults is "<<pfault<<endl;

}