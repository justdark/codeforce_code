
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <math.h>
using namespace std;
int n;
char a[1002];
int l,r;
int s,t;
int main()
{	

	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	l=1;
	while (a[l]=='.')
		l++;
	r=n;
	s=0;
	while (a[r]=='.')
		r--;
	char c=a[l];
	int t=l;
	while (a[t]==c && t<n)
		t++;
	if (t==n && a[t]!='.')
	{
		s=t;
		t=l-1;
	} else
	{
		if (a[t-1]=='R')
		{
			if (a[t]=='.')
				s=l; 
			else if (a[t]=='L')
				s=r;
		} else 
		if(a[t-1]=='L')
		{
			s=r;
			t=l-1;
		}
	}
	cout<<s<<" "<<t<<endl;
	return 0;
}