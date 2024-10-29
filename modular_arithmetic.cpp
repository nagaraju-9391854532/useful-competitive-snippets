int mod_add(int a,int b,int m){
	return (a%m+b%m)%m;
}
int mod_sub(int a,int b,int m){
	return (a%m-b%m+m)%m;
}
int mod_mul(int a,int b,int m){
	return ((a%m)*(b%m))%m;
}
int mod_expo(int a,int b,int m){
	if(b==0) return 1;
	int res=mod_expo(a,b/2,m);
	res=mod_mul(res,res,m);
	if(b&1) res=mod_mul(res,a,m);
	return res;
}
int mod_inv(int a,int m){
	return mod_expo(a,m-2,m);
}
//MODULO MULTIPLICATIVE INVERSE 
//USING FERMAT'S LITTLE THEOREM
int mod_div(int a,int b,int m){
	return mod_mul(a,mod_inv(b,m),m);
}
