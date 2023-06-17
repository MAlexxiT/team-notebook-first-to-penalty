typedef vector<vector<long long int>> Matrix;
long long int inf = 1000000007;
Matrix ones(int n) {
	Matrix r(n,vector<long long int>(n));
	for(int i= 0; i<n; i++){
        r[i][i]=1;   
    }
	return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
	int n=a.size(),m=b[0].size(),z=a[0].size();
	Matrix r(n,vector<long long int>(m));
	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0;k<z; k++){
                r[i][j]+=((a[i][k]%inf)*(b[k][j]%inf))%inf;
                r[i][j]%=inf;}}}
	return r;
}
Matrix be(Matrix b, long long int e) {
	Matrix r=ones(b.size());
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
	return r;
}

//Matrix mat(n,vector<long long int>(n));
