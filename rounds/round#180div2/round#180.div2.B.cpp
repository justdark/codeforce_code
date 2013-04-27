#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <math.h>
using namespace std;
int n;
int sx,sy,tx,ty;
int nn,ne,ns,nw;
char c[100002];
int main()
{	
	cin>>n>>sx>>sy>>tx>>ty;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	nn=0;
	ne=0;
	ns=0;
	nw=0;
	if (tx-sx>=0) ne=tx-sx;
	else nw=sx-tx;
	if (ty-sy>=0) nn=ty-sy;
	else ns=sy-ty;
	bool flag=true;
	for (int i=1;i<=n;i++)
	{
		if (c[i]=='W')
		{
			if (nw>0)
				nw--;
		}
		if (c[i]=='S')
		{
			if (ns>0)
				ns--;
		}
		if (c[i]=='E')
		{
			if (ne>0)
				ne--;
		}
		if (c[i]=='N')
		{
			if (nn>0)
				nn--;
		}
		if (nn==0 && ne==0 && ns==0 && nw==0)
		{
			cout<<i<<endl;
			flag=false;
			break;
		}
	}
	if (flag)
		cout<<-1<<endl;
	
	return 0;
}