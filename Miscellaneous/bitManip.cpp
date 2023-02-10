#include "bits/stdc++.h"
using namespace std;
#define endl '\n'


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	//Se representan bitmasks de 30 a 62 bits 
	//usando signed int y signed long long int 
	//para evitar problemas con el complemento de dos
	signed int a, b;
	//para multiplicar un numero por dos solo es necesario aplicar un 
	// shifteo de sus bits a la izquierda
	a = 1;
	a= a << 3;
	cout << a << endl;
	//para dividir un numero entre dos es necesario aplicar un
	//shifteo a la derecha
	a = 32;
	a = a >> 3;
	cout << a << endl;
	//para encender el bit n de a, solo hay que igualar a = a | pow(2,n-1) 
	//prende el tercer bit
	a = 1;
	b = 1 << 2; 
	a = a | b;
	cout << a << endl;
	//para apagar el bit n de a, solo hay que  a &= ~pow(2,n-1) 
	//prende el tercer bit
	a = 5;
	b = 1 << 2;
	a &= ~b;
	cout << a << endl;
	//para revisar si el bit n de a esta encendido
	//revisa si el tercer bit esta encendido
	a = 5;
	b = 1 << 2;
	a = a & b;
	cout << (a?"SI":"NO") << endl;
	//para volter el bit n de a, solo hay que igualar a = a ^ pow(2,n-1) 
	//apaga el tercer bit
	a = 5;
	b = 1 << 2;
	a = a ^ b;
	cout << a << endl;
	//para obtener el bit menos significativo que esta encendido a& -a
	a = 12;
	cout << log2(a & ((-1) * a))+1 << endl;
	//para prender todos los bits hasta n
	a = (1<<4)-1;
	cout << a << endl;
}
//--------------------EOSOLUTION---------------------------------
