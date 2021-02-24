#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;
typedef pair<int,int> pii;

int main()
{
	int q;
	while(scanf("%d",&q)==1)
	{

		int m,n;
		for(int i=0;i<q;i++)
		{
			priority_queue<int> seq;
			queue<pii> input;
			int p;
			scanf("%d%d",&m,&n);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&p);
				seq.push(p);
				input.push(make_pair(p,j));
			}
			int time=0;
			while(1)
			{
				while(input.front().first!=seq.top())
				{
					input.push(input.front());
					input.pop();
				}
				if(input.front().second==n)
				{
					time++;
					break;
				}
				else
				{
					//cout<<seq.top()<<" "<<input.front().second<<endl;
					input.pop();
					seq.pop();
					time++;
				}
			}
			cout<<time<<endl;
		}	
	}	
} 
