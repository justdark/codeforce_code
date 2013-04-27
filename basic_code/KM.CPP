#include <iostream>
#include <cstring>
#include <fstream>


#define maxn 20
using namespace std;
int w[21][21];
int m[21];
int lx[21];
int ly[21];
bool vx[21];bool vy[21];
int n,i,j,k,d,ans;

bool find(int x){
	int y;bool bo;
	bo=false;
	vx[x]=true;
	for (y=1;y<=n;y++) if ((! vy[y])&&lx[x]+ly[y]==w[x][y])
	{
		vy[y]=true;
		if (m[y]==0 || find(m[y])==true)
		{
			m[y]=x;
			bo=true;
			return(bo);

		}
	}
	return(false);
}
int main()
{ 
  ifstream cin("test.in");
  ofstream cout("test.out");
  cin>>n;
 
	   for (i=1;i<=n;i++)
		   for (j=1;j<=n;j++)
		   {
			   cin>>w[i][j];
			   if (w[i][j]>lx[i]) lx[i]=w[i][j];
		   }
	   for (k=1;k<=n;k++)
		   do
	   {
		   memset(vx,0,sizeof(vx));
		   memset(vy,0,sizeof(vy));
		   if (find(k)) break;
		   d=455445;
		   for (i=1;i<=n;i++) if (vx[i])
			   for (j=1;j<=n;j++) if (! vy[i])
		          if (lx[i]+ly[j]-w[i][j]<d) d=lx[i]+ly[j]-w[i][j];
           for (i=1;i<=n;i++)
		   {
			    if (vx[i]) lx[i]=lx[i]-d;
				if (vy[i]) ly[i]=ly[i]+d;
		   }
	   } while (true);
	   ans=0;
	  for (i=1;i<=n;i++)
	   ans+=w[m[i]][i];
	   cout<<ans<<endl;
 
  cin.close();
 cout.close();
  return 0; 
}
