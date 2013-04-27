// asd.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <math.h>
using namespace std;
int a,b,n;
long long  k[1000002];
bool isgood(char aa[])
{
	for (int i=0;i<strlen(aa);i++)
	{
		if ( (aa[i]-'0')!=a &&  ( (aa[i]-'0')!=b))
			return false;
	}
	return true;
}
int exgcd(int a,int b,long long &x,long long &y)
{
	if (!b) 
	{
		x=1,y=0;return a;
	}
	int ans=exgcd(b,a%b,x,y);
	long long z=x;x=y;y=z-(a/b)*y;
	return ans;
}

int exgcds(int d,int f)
{
	int x1=1,x2=0,x3=f;
	int y1=0,y2=1,y3=d;
	int t1,t2,t3;
	while (true)
	{
		if (!y3) return NULL;
		if (y3==1) return y2;
		int q=x3 / y3;
		t1=x1-q*y1;t2=x2-q*y2;t3=x3-q*y3;
		x1=y1;x2=y2;x3=y3;
		y1=t1;y2=t2;y3=t3;
	}
}

int r(int b,int d)
{
	long long x;
	//int a=exgcd(b,d,x,y);
	x=exgcds(b,d);
	//return ((-x)/F*F+F+x)%F;
	return (x+abs(x)/d*d+d)%d;
}

int main()
{	
	
	
	char s[100];
	cin>>a>>b>>n;
	int m=0;
	int kk=n-1;
	k[0]=1;
	k[1]=1;
	bool flag=true ;
	for (int i=2;i<=1000000;i++)
	{
		k[i]=(k[i-1]*i)%1000000007;
		
	}
	for (int i=0;i<=n;i++)
	{
		
		itoa(a*i+(n-i)*b,s, 10);
		if (isgood(s))
		{ 
		   m=(m+((((k[n]*r(k[i],1000000007))%1000000007)*r(k[n-i],1000000007))%1000000007))%1000000007;
		}
	}
	cout<<m<<endl;
	return 0;
	
}