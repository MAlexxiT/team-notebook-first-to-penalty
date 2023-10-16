#include "bits/stdc++.h"
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ost;
using namespace std;
int main(){
    ost arbol;
    int n = 5;
    for(int id = 1; id<=n; id++)
        for(int val = 0; val<n; val++)
            arbol.insert({val,id});
    //te da el valor mas pequenio, en caso de empate te da el del id mas pequenio
    cout<<(*arbol.find_by_order(0)).first<<" "<<(*arbol.find_by_order(0)).second<<endl;
    //te da el indice (base 0) de la primera ocurrencia de .first
    cout<<arbol.order_of_key({1,-1})<<endl;;
}
