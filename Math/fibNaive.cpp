//en caso de ser usados mod un m pequeno
//recordar que los numeros de fibonacci se repiten por lo menos cada m^2
//O(n)
unsigned long long int fib(int n){
	unsigned long long int a = 1,b = 1,aux;
	if(n<=2){
		return 1;
	}
	for(int i = 3; i<=n; i++){
		aux = a+b;
		a = b;
		b = aux;
	}
	return b;
}