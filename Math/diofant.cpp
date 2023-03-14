long long int gcd(long long int a, long long int b, long long int& x, long long int& y) {
	x = 1, y = 0;
	long long int x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}
long long int d;
bool findAnySol(long long int a, long long int& x, long long int b, long long int& y, long long int c) {
	long long int g = gcd(abs(a), abs(b), x, y);
	if (c % g != 0) return false;
	x *= c;
	y *= c;
	x /= g;
	y /= g;
	d = c / g;
	if (a < 0) x = -x;
	
	if (b < 0) y = -y;
	return true;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	long long int m, a, k, n;
	long long int f, h,res;
	//estira en n, y despues cada m
	//estira en k+a, y despues cada a
	cin >> n >> m >> a >> k;
	while (n != 0 && m != 0 && a != 0 && k != 0) {
		m = -m;
		if (!findAnySol(m, f, a, h, k + a - n)) {
			cout << "Impossible" << endl;
		}else {
			res = f * m+n;
			while (res > 0) res -= m * d;
			while (res < 0) res += m * d;
			
			cout << res << endl;
		}
		cin >> n >> m >> a >> k;
	}

}
//--------------------EOSOLUTION---------------------------------