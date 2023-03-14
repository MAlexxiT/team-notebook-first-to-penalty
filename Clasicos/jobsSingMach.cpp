//cuando se tiene que encontrar un orden optimo 
//para trabajos con una funcion lineal de penalty, basta con hacer un sort en O(n log n)
struct trabajo{
    long long int penalty,tiempo;
    int ind;
};
bool comp(const trabajo a, const trabajo b){
    if (a.tiempo * b.penalty == a.penalty * b.tiempo) return a.ind<b.ind;
    return a.tiempo * b.penalty < a.penalty * b.tiempo;
}