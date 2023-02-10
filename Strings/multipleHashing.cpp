struct multhash{
    unsigned long long int h1,h2,h3;
    unsigned long long int alf[257];
    bool operator < (multhash b) const { // override less than operator
		if (h1 != b.h1) return h1 < other.h1;
		if (h2 != b.h2) return h2 < other.h2;
		return h3 < b.h3;
	}
	bool operator == (multhash b) const { // override equal operator
		return (h1== b.h1 && h2== b.h2 && h3== b.h3)
	}
public: 
    string s;
    multhash(){
        h1 = 0; h2 = 0;h3 = 0; s = "";
        for(char l = 'a'; l<='z'; l++) alf[l] = l-'a'+1;
    }
    void innit(){
        unsigned long long int inf,p,op;
        
        inf = 666666555557777777;
        p = 47;op = 47;
        for(char l: s){
            h1+=(p*alf[l])%inf;
            p*=op;
            p%=inf;
        }

        inf = 986143414027351997;
        p = 53;op = 53;
        for(char l: s){
            h2+=(p*alf[l])%inf;
            p*=op;
            p%=inf;
        }

        inf = 909090909090909091;
        p = 79;op = 79;
        for(char l: s){
            h3+=(p*alf[l])%inf;
            p*=op;
            p%=inf;
        }
    }
};
//VALORES POSIBLES DE INF, MIENTRAS MAS CERCANOS A 10^17 MEJOR
//666666555557777777
//986143414027351997
//974383618913296759
//973006384792642181
//953947941937929919
//909090909090909091
//VALORES PARA P, USAR PRIMOS MAYORES A |Alfabeto|
//31,47,53,61,79