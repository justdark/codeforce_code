#include <iostream>
using namespace std;
int gcd(int a,int b){
	int ans;
	if (b==0) ans=a;
	else ans=gcd(b,a%b);
	return (ans);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
}