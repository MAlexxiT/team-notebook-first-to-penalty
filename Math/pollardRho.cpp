long long int gcd(long long int a, long long int b){return a?gcd(b%a,a):b;}
long long int mulmod(long long int a, long long int b, long long int m) {
	long long int  r=a*b-(long long int)((long double)a*b/m+.5)*m;
	return (r<0?r+m:r);
}
long long int expmod(long long int b, long long int e, long long int m){
	if(!e)return 1;
	long long int q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return (e&1?mulmod(b,q,m):q);
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	long long int s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	long long int x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	for(int i = 0; i<s-1; i++){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(long long int n){ // true iff n is prime
	if(n==1)return false;
	int A[]={2,3,5,7,11,13,17,19,23};
    for(int a: A) if(!is_prime_prob(n,a))return false;
	return true;
}
long long int rho(long long int n){
    if(!(n&1))return 2;
    long long int x=2,y=2,d=1;
    long long int c=rand()%n+1;
    while(d==1){
        x=(mulmod(x,x,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        if(x>=y)d=gcd(x-y,n);
        else d=gcd(y-x,n);
    }
    return d==n?rho(n):d;
}
void fact(long long int n, map<long long int,int>& f){ //O (lg n)^3
	if(n==1)return;
	if(rabin(n)){f[n]++;return;}
	long long int q=rho(n);
	fact(q,f);fact(n/q,f);
}