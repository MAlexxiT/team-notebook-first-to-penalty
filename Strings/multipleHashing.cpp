struct multhash{
    unsigned long long int h1,h2;
    unsigned long long int alf[257];
    bool operator < (multhash b) const { 
		if (h1 != b.h1) return h1 < b.h1;
		return h2 < b.h2;
	}
	bool operator == (multhash b) const { return (h1== b.h1 && h2== b.h2);}
	bool operator != (multhash b) const { return !(h1== b.h1 && h2== b.h2);}
public: 
    string s;
    multhash(){
        h1 = 0; h2 = 0;s = "";
        for(char l = 'a'; l<='z'; l++) alf[l] = l-'a'+1;
    }
    void innit(){
        unsigned long long int inf,p,op;
        
        inf = 999727999;
        p = 325255434;op = 325255434;
        for(char l: s){
            h1+=(p*alf[l])%inf;
            p*=op;
            p%=inf;
        }

        inf = 1070777777;
        p = 10018302;op = 10018302;
        for(char l: s){
            h2+=(p*alf[l])%inf;
            p*=op;
            p%=inf;
        }
    }
};
//VALORES ALTERNATIVOS DE INF, LOG 17
//666666555557777777
//986143414027351997
//974383618913296759
//973006384792642181
//953947941937929919
//909090909090909091
//VALORES PARA P, USAR PRIMOS MAYORES A |Alfabeto|
//31,47,53,61,79
