int gcd(int a,int b){
	cout<<a<<" "<<b<<endl;
	return b==0?a:gcd(b,a%b);
}
