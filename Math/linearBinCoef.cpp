//Usar esto es O(k)
long long int bincoef(long long int n, long long int k){
    if(k == 0 || k==n) return 1;
    if(2LL*k > n) return bincoef(n,n-k);
    return ((n * bincoef(n-1,k-1))%inf *modinverse(k))%inf;
}   