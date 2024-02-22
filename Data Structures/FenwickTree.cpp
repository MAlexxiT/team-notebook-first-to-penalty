//Fenwick tree, solo jala si la funcion cumple con ser:
//una binary associative function over a set with identity element and inverse elements
// incluyendo pero no limitandose a range sum
//define neutro y llena arr
#define MAXN 500010
long long int neutro; 
vector<long long int> arr;
long long int fenwick[MAXN];

int get_low(int ind){return (ind&(ind+1));}
int get_upp(int ind){return (ind|(ind+1));}
long long int get_sum(int r){
    if(r<0) return neutro; 
    return fenwick[r]+get_sum(get_low(r)-1);
}
long long int get_sum(int l, int r){return get_sum(r)-get_sum(l-1);}
void build(){
    int size = arr.size();
    for(int i = 0; i<size; i++ ) fenwick[i] = neutro;
    for(int i = 0; i<size; i++){
        fenwick[i]+=arr[i];
        if(get_upp(i)<size)fenwick[get_upp(i)]+=fenwick[i];
    }   
}
void add(int ind, long long int d){
    for(;ind<arr.size(); ind = get_upp(ind)) fenwick[ind]+=d;
}
//no funciona con range queries
void range_add(int l, int r, int d){add (l,d); add(r+1,-d);}