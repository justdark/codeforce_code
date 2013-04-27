// asd.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
#define N 100
#define M 100
double MAX(double a,double b)
{
	return (a>b) ? a: b;
}

int ans[N+1];
int p=0;
void reviews(int c[N+1][M+1],int a[],int b[],int i,int j)
	{
		if (i==0 || j==0)
			return;
		if (c[i][j]==(c[i-1][j-1]+1) && a[i-1]==b[j-1])
		{
			ans[p]=a[i-1];
			p++;
			reviews(c,a,b,i-1,j-1);
		} else
		{
			if (c[i][j]==c[i][j-1])
			{
				reviews(c,a,b,i,j-1);
			} else
				reviews(c,a,b,i-1,j);
		}
	}

void lcs(int a[],int lena,int b[],int lenb)
{
	int c[N+1][M+1];
	//注意这里编号有偏移 
	memset(c,0,sizeof(c));
	for (int i=1;i<=lena;i++)
		for (int j=1;j<=lenb;j++)
				if (a[i-1]==b[j-1]) //注意这里编号有偏移 
				{
					c[i][j]=c[i-1][j-1]+1;
				} else
				{
					c[i][j]=MAX(c[i][j-1],c[i-1][j]);
				}
	cout<<"the longist subsequence is "<<c[lena][lenb]<<endl;
	reviews(c,a,b,lena,lenb);
	for (int i=0;i<c[lena][lenb];i++)
		cout<<ans[i];
}
int main()
{
	int n,m;
	int a[100],b[100];
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	for (int i=0;i<m;i++)
		cin>>b[i];
	lcs(a,n,b,m);
	return 0;
}
