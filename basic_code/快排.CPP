#include <iostream>
#include <fstream>
using namespace std;
int n,i,j,k;
int a[1000];
void qsort(int a[],int lx,int rx)
{
   int i,j,t,x;
   i=lx; j=rx;
   x=a[rand()%(j-i+1)+i];
   do{
	   while (a[i]<x) i+=1;
	   while (a[j]>x) j-=1;
	   if (i<=j)
	   {
		   t=a[i];a[i]=a[j];a[j]=t;
		   i+=1;j-=1;
	   }
   }
   while (i<=j);
   if (lx<j) qsort(a,lx,j);
   if (i<rx) qsort(a,i,rx);
}
int main()
{ 
  ifstream cin("test.in");
  ofstream cout("test.out");

  cin>>n;
  for (i=1;i<=n;i++) cin>>a[i];
  qsort(a,1,n);
  for (i=1;i<=n;i++) cout<<" "<<a[i];

  cin.close();
  cout.close();
  return 0; 
}
