//Solo usar con n<=20
//cat[n] = bincoef(2*n,n)/(n+1), cat[0] = 1 
unsigned long long int bincoef(unsigned long long int n, unsigned long long int k){
    if(n<k) return 0;
    unsigned long long int num  = 1, den= 1;
    for(unsigned long long int i = (n-k)+1; i<=n; i++) num*=i;
    for(unsigned long long int i = 2; i<=k; i++) den*=i;
    //perm = return num;
    return num/den;
}