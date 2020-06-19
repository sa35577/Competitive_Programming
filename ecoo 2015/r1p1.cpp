#include<iostream>
#include<sstream>
#include<string>
char cbuf[100000];
char dummy[12];
using namespace std;
ostream&printWordSegs(ostream&out,const string&s,const unsigned int&size)
{
	unsigned int x=0;
	while(x<s.size())
	{
		if(x+size>s.size())
		{
			out<<s.substr(x)<<endl;
		}
		else
		{
			out<<s.substr(x,size)<<endl;
		}
		x+=size;
	}
	return out;
}
int main(int argl,char**argv)
{
	unsigned int window=0;
	string s="",word="";
	istringstream sin=istringstream();
	ostringstream sout=ostringstream();
	unsigned long long sz=0;
	for(unsigned int test=0;test<10;test++)
	{
		cin>>window;
		cin.getline(dummy,2);
		cin.getline(cbuf,100000);
		s=string(cbuf,cbuf+cin.gcount());
		sin=istringstream(s);
		sout.str(string());
		sz=0;
		while(!sin.eof())
		{
			sin>>word;
			if(word.size()>window)
			{
				if(sz)
				{
					cout<<sout.str()<<endl;
					sout.str(string());
					sz=0;
				}
				printWordSegs(cout,word,window);
			}
			else
			{
				if(sz+word.size()+(sz>0?1:0)>window)
				{
					cout<<sout.str()<<endl;
					sout.str(string());
					sz=0;
				}
				if(sz)
				{
					sout<<" ";
				}
				sout<<word;
			}
			sz=sout.str().size();
		}
		if(sz)
		{
			cout<<sout.str()<<endl;
		}
		cout<<"=====\n";
	}
	return 0;
}