#include <iostream>
#include <string.h>
#include <random>
#include <chrono>
using namespace std;
//args nombreDelEjecutable,seed, len
int main (int argc, char **argv) {
    // argv is an array of strings
    // atoi is a C function for converting a string into an int
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    srand(atoi(argv[1])); // srand sets the random seed
    int n = atoi(argv[2]);
    int d = rng()%n; d++;
    string test = "";  
    for (int i = 0; i < n; i++) {
        test+= 'a'+(rng()%26);
    }
    cout<<test<<" "<<d<<endl;
}