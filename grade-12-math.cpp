#include<bits/stdc++.h>
using namespace std;
int opinions[500000];
int query(unordered_map<int,int>*bit, int n, int p,int c) {
	int ans=0;
	while(p>0)
	{
		ans+=bit[p-1].find(c)==bit[p-1].end()?0:bit[p-1][c];
		p-=p&-p;
	}
	return ans;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,q,qt,x,y,z;
	cin>>n>>q;
	unordered_map<int,int>*bit=new unordered_map<int,int>[n];
	for(int i=0;i<n;i++)
	{
		bit[i][0]=i+1&(-i-1);
	}
	for(int i=0;i<q;i++)
	{
		cin>>qt;
		if(qt==1)
		{
			cin>>x;
			opinions[--x]++;
			z=x+1;
			for(;z<=n;z+=z&(-z))
			{
				if(bit[z-1][opinions[x]-1]==1)
				{
					bit[z-1].erase(opinions[x]-1);
				}
				else
				{
					bit[z-1][opinions[x]-1]--;
				}
				bit[z-1][opinions[x]]++;
			}
		}
		else if(qt==2)
		{
			cin>>y;
			opinions[--y]--;
			z=y+1;
			for(; z <= n; z += z&(-z))
			{
				if(bit[z-1][opinions[y]+1]==1)
				{
					bit[z-1].erase(opinions[y]+1);
				}
				else
				{
					bit[z-1][opinions[y]+1]--;
				}
				bit[z-1][opinions[y]]++;
			}
		}
		else
		{
			cin>>x>>y>>z;
			cout<<query(bit,n,y,z)-query(bit,n,--x,z)<<endl;
		}
	}
	return 0;
}