#include <iostream>
using namespace std;
int IsPrime(int n){
	int i;
	if (n==1) return (0);
	for (i=2;i<=n/2;i++)
	{
		if (n%i==0) return(0);
	}
	return(1);
}
int main(){
	int a;
	for (a=1;a<=100;a++)
	{
		if (IsPrime(a)==1) cout<<a<<endl;
	}
	getchar();
	getchar();
}