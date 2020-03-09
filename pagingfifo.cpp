#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,p;
	vector<int> ps;
	cout<<"Enter the length of the page string.\n";
	cin>>n;
	set<int> s;
	queue<int> q;
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
			if(currsize==pframe)
			{
				s.erase(q.front());
				q.pop();
				currsize--;
			}
			q.push(p);
			s.insert(p);
			pfault++;
			currsize++;
		}
	}
	cout<<"The number of page hits is "<<phit<<endl;
	cout<<"The number of page faults is "<<pfault<<endl;

}