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
#define NN 100
int a[100];
double MAX(double a,double b)
{
	return (a>b) ? a: b;
}

int binary(int a[],int l,int r,int b)
{
	int p=(r+l)/2;
	if (l==r)
		return l;
	if (a[p]>b)
	{
		return binary(a,l,p,b);
	}
	return binary(a,p+1,r,b);
}

int lis_length(int a[],int len)  //NLOGN算法，只能得到长度
{
	int que[NN];
	memset(que,0,sizeof(que));
	int p=0;
	for (int i=0;i<len;i++)
	{
		if (p==0 || que[p-1]<a[i])   //最长上升？最长不下降？
		{
			que[p]=a[i];
			p++;
		} else
		{
			int j=binary(que,0,p-1,a[i]);
			que[j]=a[i];
		}
	}
	return p;
}


void lis(int a[],int len)  //N^2的算法，但是能得到序列
{
	int f[NN];
	int p[NN];
	memset(f,0,sizeof(f));
	memset(p,0,sizeof(p));
	f[0]=1;
	p[0]=-1;
	for (int i=1;i<len;i++)
	{
		for (int j=0;j<i;j++)
		if (a[j]<a[i] && f[j]+1>f[i])     //最长上升？最长不下降？
		{
			f[i]=f[j]+1;
			p[i]=j;
		}
		if (!f[i])
		{
			f[i]=1;
			p[i]=-1;
		}
	}
	int maxlen=0;
	int dp=0;
	for (int i=0;i<len;i++)
	{
		if (f[i]>maxlen)
		{
			maxlen=f[i];
			dp=i;
		}
	}
	while (dp!=-1)
	{
		cout<<a[dp];      //Output Subsequence
		dp=p[dp];
	}
}

int main()
{	
	
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	lis(a,n);  //N^2

	cout<<" the length is "<<lis_length(a,n)<<endl; //NLOGN
	return 0;
	
}