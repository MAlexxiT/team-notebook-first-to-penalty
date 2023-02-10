#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")

//no usar con visual c++
//solo con g++ like compilers
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	signed long long int a, b, n;
	//Obtain the remainder (modulo) of a when it is divided by n (n is a power of 2)
	a = 15; n = 8-1;
	a &= n;
	cout << "a%n, a = 15, n = 2^3" << endl;
	cout << a << endl;
	//Apaga el bit menos significativo de a
	a = 14;
	b = (a & ((-1) * a));
	a &= ~b;
	cout << a << endl;
	//enciende el ultimo cero de a
	a = 9;
	b = ~a;
	b = (b & ((-1) * b));
	a = a | b;
	cout << a<<endl;
	//contar bits encendidos en a
	cout << __builtin_popcount(a)<<endl;
	//checar la paridad de a
	cout << (__builtin_parity(a) ? "IMPAR" : "PAR") << endl;
	//contar leading zeroes en a
	cout << __builtin_clz(a)<<endl;
	//contar 9,trailling zeroes en a
	cout << __builtin_ctz(a)<<endl;
}
//--------------------EOSOLUTION---------------------------------
