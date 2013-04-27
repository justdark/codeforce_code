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
#include <queue>
using namespace std;
int p[10000];
int kmp(char *a,char *b)
{
	int len_a=0;
	int len_b=0;
	while (a[len_a]!='\0')
		len_a++;
	while (b[len_b]!='\0')
		len_b++;
	memset(p,0,sizeof(p));
	p[0]=0; int j=-1;
	for (int i=1;i<len_b;i++)
	{
		while (j>-1 && b[j+1]!=b[i])
			j=p[j];
		if (b[j+1]==b[i]) 
			j++;
		p[i]=j;
	}

	j=-1;
	for (int i=0;i<len_a;i++)
	{
		while (j>-1 && b[j+1]!=a[i])
			j=p[j];
		if (b[j+1]==a[i]) 
			j++;
		if (j==len_b-1)
		{
			cout<<"find match at  "<<i-len_b+1<<endl;
			j=p[j];
		}
	}
	return 0;
}
int main()
{	
	kmp("asdasd","as");
	return 0;
}