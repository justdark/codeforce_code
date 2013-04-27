int ModExp(int a,b,n){
	int t,y;
	t=1;y=a;
	while (b!=0)
	{
		if (b%2=1) t=t*y%n;
		y=y*y%n;
		b=b/2;
	}
	return(t);
}