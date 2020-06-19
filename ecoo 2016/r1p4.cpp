#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
enum __party{DEM,REP};
struct __house
{
	int x;
	int y;
	__party party;
	__house()
	{
		this->x=0;
		this->y=0;
		this->party=REP;
	}
	__house(int x,int y,__party party)
	{
		this->x=x;
		this->y=y;
		this->party=party;
	}
};
istream&operator>>(istream&in,__house&house)
{
	string s="";
	in>>house.x;
	in>>house.y;
	in>>s;
	house.party=s=="D"?DEM:REP;
	return in;
}
__house houses[100];
char hmap[401][401];
int px,py;
unsigned int pt_house_dist(const __house&h,const int&x,const int&y)
{
	int xdist=h.x-x,ydist=h.y-y;
	return xdist*xdist+ydist*ydist;
}
bool _h_cmp(const __house&x,const __house&y)
{
	int xxdist=x.x-px,xydist=x.y-py;
	int yxdist=y.x-px,yydist=y.y-py;
	int xdist=xxdist*xxdist+xydist*xydist;
	int ydist=yxdist*yxdist+yydist*yydist;
	return xdist<ydist;
} 
int main(int argl,char**argv)
{
	cin.sync_with_stdio(false);
	int nx=0,ny=0;
	unsigned int dem=0,rep=0;
	unsigned int demtot=0,reptot=0;
	unsigned int dist3=0;
	for(unsigned int test=0;test<10;test++)
	{
		cin>>nx>>ny;
		for(unsigned int i=0;i<100;i++)
		{
			cin>>houses[i];
			hmap[houses[i].x+200][houses[i].y+200]=1;
		}
		demtot=0,reptot=0;
		for(int i=-50;i<=50;i++)
		{
			for(int j=-50;j<=50;j++)
			{
				if(hmap[nx+j+200][ny+i+200]==0&&i*i+j*j<=2500)
				{
					dem=0,rep=0;
					px=nx+j,py=ny+i;
					sort(houses,houses+100,_h_cmp);
					for(unsigned int u=0;u<3;u++)
					{
						if(houses[u].party==DEM)
						{
							++dem;
						}
						else
						{
							++rep;
						}
					}
					dist3=pt_house_dist(houses[2],px,py);
					for(unsigned int u=3;u<100&&pt_house_dist(houses[u],px,py)==dist3;u++)
					{
						if(houses[u].party==DEM)
						{
							++dem;
						}
						else
						{
							++rep;
						}
					}
					if(dem>=rep)
					{
						demtot++;
					}
					else
					{
						reptot++;
					}
				}
			}
		}
		printf("%.1f\n",demtot*100.0/(demtot+reptot));
	}
	return 0;
}