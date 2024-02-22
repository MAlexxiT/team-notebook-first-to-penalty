long long mult(long long a, long long b, long long mod) {
    long long result = 0;
    while (b) {
        if (b & 1) result = (result + a) % mod;
        a = (a + a) % mod;b >>= 1;
    }
    return result;
}
long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}
 
long long brent(long long n, long long x0=2, long long c=1) {
    long long x = x0, g = 1, q = 1;
    long long xs, y;
 
    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++) x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = mult(q, abs(y - x), n);
            }
            g = __gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);g = __gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}