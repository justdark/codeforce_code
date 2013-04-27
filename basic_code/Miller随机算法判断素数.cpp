#include <iostream>
using namespace std;
int ModExp(int a,int b,int n){
	int t,y;
	t=1;y=a;
	while (b!=0)
	{
		if (b%2==1) t=(t*y)%n;
		y=(y*y)%n;
		b=b/2;
	}
	return(t);
}
int MillerPrime(int n){
	int l,m,b,i,k;
	if (n==1 || n==0) return(0);
	m=n-1;
	l=0;
	while (m%2==0)
	{
		l+=1;
		m/=2;
	}
		b=rand()%(n-1)+1;
		if (ModExp(b,m,n)==1) return(1);
		k=m;
		for (i=0;i<=l-1;i++)
		{
			if (ModExp(b,k,n)==n-1) return(1);
			k=k*2;
		}
	return(0);
}
int main(){
	int a;int ans;
	ans=0;
	for (a=1;a<=100;a++)
	{
		if (MillerPrime(a)==1&&MillerPrime(a)==1&&MillerPrime(a)==1) cout<<a<<endl;  //多次测试增加正确率

	}
	gduoceetchar();
	getchar();
}