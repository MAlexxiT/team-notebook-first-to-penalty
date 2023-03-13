struct triver {
    char alphabet;
    vector<triver*> child;
    triver(char a): alphabet(a) { child.assign(26, NULL); }
};
class trie{
private:                                         
    triver* root;
public:
    trie() { root = new triver('!');}
    void insert(string s){
        triver* curr = root;
        for(char l: s){
            if(curr->child[l-'A'] == NULL) curr->child[l-'A'] =  new triver(l);
            curr = curr->child[l-'A'];
        }
    }
    bool search(string s){
        triver* curr = root;
        for(char l: s){
            if(curr == NULL) break;
            curr = curr->child[l-'A'];
        }
        return !(curr == NULL);
    }
};