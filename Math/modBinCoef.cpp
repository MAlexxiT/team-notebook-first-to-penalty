long long int inf = 1000000007;
//cat[n] = bincoef(2*n,n)/(n+1), cat[0] = 1 
class binCoef{
    long long int lim;
    long long int* fact;
public:
    binCoef(long long int l){ 
        lim = l; fact = new long long int[l+1];fact[0]= 1;
        for(long long int i = 1; i<=l; i++) fact[i] = (fact[i-1]*i)%inf;    
    }
    //perm = (fact[n] * modinverse(fac[n-k],inf)%inf;
    long long int query(long long int n, long long int k){ 
        if(n<k) return 0;
        return (fact[n] * modinverse((fac[n-k]*fact[k])%inf,inf))%inf;
    } 
};