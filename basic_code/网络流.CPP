#include <iostream>
#include <cstring>
using namespace std;
int i,j,k,m,n,l,r,s1,s2,s3,zong;
bool o;
int c[1001][1001];
int cur[1001];
int biao[1001];
int dui[1001];
bool build()
{
	int l,r,i,j,k;
    memset(dui,0,sizeof(dui));
	memset(biao,255,sizeof(biao));
	l=0;r=1;biao[1]=0;dui[1]=1;
	do
	{
		l+=1;
		i=dui[l];
		for (j=1;j<=n;j++)
		{
			if (biao[j]==-1&&c[i][j]>0) 
			{
				biao[j]=biao[i]+1;
				if (j==n) return(true);
				r+=1;
				dui[r]=j;
			}
		}
	}
	while (l<=r);
	return(false);

}

int find(int a,int b)
{
	int i,j,k;
	if (a==n) return(b);
	for (i=cur[a];i<=n;i++)
	{
		cur[a]=i;
		if (c[a][i]>0&&biao[i]==biao[a]+1)
		{
			if (c[a][i]<b) b=c[a][i];
			k=find(i,b);
			c[i][a]+=k;
			c[a][i]-=k;
			if (k>0) return(k);
		}
	}
	return(0);
}
int main(){
	cin>>m>>n;
	for (i=1;i<=m;i++)
	{
		cin>>s1>>s2>>s3;
		c[s1][s2]=s3;
	}
	zong=0;
	if (build())
	{
		do 
		{
		memset(cur,0,sizeof(cur));
		do
		{
			k=find(1,5000);
			zong+=k;
		}
		while(k!=0);
		}
		while (build());
	}
	cout<<zong<<endl;
	getchar();
	getchar();
}
