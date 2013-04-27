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
#define NN 1000
int map[NN][NN];
bool h[NN];
int f[NN];
int queue[NN*30]; //队列大小attention
int s,t; // start,target.
int n,m;
void input()
{
	cin>>n>>m;
	int a,b,c;
	for (int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		map[a][b]=c;
		map[b][a]=c;
	}
	cin>>s>>t;
}
void spfa()
{
	memset(map,0,sizeof(map));
	memset(h,0,sizeof(h));
	memset(f,0x70,sizeof(f));
	input();
	int l,r;
	l=0;r=1;
	h[s]=true;
	queue[1]=s;f[s]=0;
	while (l<r)
	{
		l++;
		int now=queue[l];
		h[now]=false;
		for (int i=0;i<n;i++)
		{
			if (i!=now && map[i][now]!=0 && f[i]>f[now]+map[i][now])
			{
				f[i]=f[now]+map[i][now];
				if (!h[i])
				{
					r++;
					queue[r]=i;
					h[i]=true;
				}
			}
		}
	}
	if (f[t]<10000000)
	{
		cout<<"the shortest length is  "<<f[t]<<endl;
	} else
	cout<<"can't find the way"<<endl;
}
int main()
{	
	spfa();
	return 0;
}