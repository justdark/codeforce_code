#include <iostream>
using namespace std;
int gcd(int a,int b){
	int ans;
	if (b==0) ans=a;
	else ans=gcd(b,a%b);
	return (ans);
}
int lcm(int a,int b){
    int ans;
	if (a*b==0) ans=0;
	else ans=a*b/gcd(a,b);
	return(ans);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	cout<<lcm(a,b)<<endl;
	getchar();
	getchar();
}