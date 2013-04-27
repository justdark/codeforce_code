#include <iostream>
using namespace std;
bool find(int x);
	int mm[201];
	bool used[201];
	bool kk[201];
	int a[201][201];
	bool line[201][201];
	bool tt;
	int m,n;
int main(){
	int i,j,k,ii,all,s;
    cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		j=0;
		while ( 1) {
			j+=1;
			cin>>a[i][j];
			if (a[i][j]>0) line[i][a[i][j]]=true;
			if (a[i][j]==0) {
		
				break;
			}
		}
	}
	all=0;
	for (i=1;i<=n;i++)
	{
		static bool used[201];
		if (find(i)==1) all+=1;
	}
	cout<<all<<endl;
	getchar();
	getchar();
}
bool find(int x){
	int kkk,i,j;
	for (j=1;j<=m;j++){
		if (line[x][j]==true&&used[j]==false)
		{
			used[j]=1;
			if (mm[j]==0 || find(mm[j])==true) {
				mm[j]=x;
				return(1);
			}
		}
	}
	return(0);
}