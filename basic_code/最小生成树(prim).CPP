#include <iostream>
#include <fstream>
using namespace std;
int i,j,k,m,n,min,zong;
int map[101][101];
int f[101];
int main()
{ 
  ifstream cin("test.in");
  ofstream cout("test.out");
  cin>>n;
  for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	  {
		  cin>>map[i][j];
		  map[j][i]=map[i][j];
	  }
  for (i=2;i<=n;i++) f[i]=map[1][i];
  for (i=1;i<=n-1;i++)
  {
	  m=1000000;
	  for (j=1;j<=n;j++) if (f[j]<=m&&f[j]!=0)
	  {
		  m=f[j];
		  k=j;
	  }
	  f[k]=0;
	  zong=zong+m;
	  for (j=1;j<=n;j++) 
		  if (f[j]>map[j][k])
					 f[j]=map[j][k];

  }
  cout<<zong<<endl;

  cin.close();
  cout.close();
  return 0; 
}
