#define ALPHABET_SIZE 255
struct nodeData{
    bool terminal;
    string word;
    vector<nodeData*> next;
    nodeData* outputLink;
    nodeData* fallBack;
    nodeData* parent;

    nodeData(bool protoTerminal, string protoWord){
        terminal = protoTerminal;
        if(terminal) word = protoWord;
        next.resize(ALPHABET_SIZE); next.assign(ALPHABET_SIZE,NULL);
        fallBack = NULL;
        outputLink = NULL;
        parent = NULL;
    }
};


class AhoCorasick{
    vector<string> dictionary;
    nodeData* root;

    void addWord(string word){
        //not sure what accomplishes tho
        assert(word.size() > 0);
        nodeData* curr = root;

        for(char letter: word){
            if(curr->next[letter] == NULL) curr->next[letter] = new nodeData(false,"");
            
            curr->next[letter]->parent = curr;
            curr = curr->next[letter];
        }

        curr->terminal = true;
        curr->word = word;
    }

    
    void buildFallBack(){
        
        //the suffix link an arbitrary node is the first suffix link that has an outgoing edge labeled as the edge that lead to the original node
        //node and the edge that lead to it
        queue<pair<nodeData*, char>> fringe;
        pair<nodeData*, char> value;
        fringe.push({root,'x'});


        nodeData* fallBack;
        nodeData* curr;
        char letter;
        while(fringe.size()>0){
            value = fringe.front(); fringe.pop();
            curr = value.first;
            letter = value.second;

            //ads its descendants into the fringe
            for(int l = 0; l<ALPHABET_SIZE; l++){
                if(curr->next[l] != NULL) fringe.push({curr->next[l],l});
            }

            
            //The root always falls back to itself
            if(curr == root){
                curr->fallBack = root;
                
                continue;
            }
            //Every direct child of the root has the root as their fallBack
            if(curr->parent == root){
                curr->fallBack = root;
                continue;
            }

            fallBack = curr->parent->fallBack;
            while(fallBack != root && fallBack->next[letter] == NULL){ 
                fallBack = fallBack->fallBack;
            }

            if(fallBack->next[letter]) fallBack = fallBack->next[letter];

            curr->fallBack = fallBack;
        }
    }

    void buildOutputLink(){
        queue<nodeData*> fringe;
        nodeData* curr;

        fringe.push(root);

        while(fringe.size()>0){
            curr = fringe.front(); fringe.pop();
            for(int l = 0; l<ALPHABET_SIZE; l++){
                if(curr->next[l] != NULL) fringe.push(curr->next[l]);
            }

            curr->outputLink = NULL;
            if(curr->fallBack->terminal){
                curr->outputLink = curr->fallBack;
            }else{
                curr->outputLink = curr->fallBack->outputLink;
            }
        }
    }
    public:
    AhoCorasick(vector<string> protoDictionary){
        dictionary = protoDictionary;
        root = new nodeData(false, "");

        for(string word: dictionary) addWord(word);

        buildFallBack();
        buildOutputLink();
    }


    void search(string text){
        nodeData* curr = root;
        nodeData* parallelMatch;
        for(char letter: text){
            //ensures that the current node has a next with label 'letter'
            do{
                if(curr->next[letter] != NULL) break;
                curr = curr->fallBack;
            }while(curr != root);

            if(curr->next[letter] != NULL) curr = curr->next[letter];


            
            if(curr->terminal){
                //cout<<curr->word<<endl;
            } 
            parallelMatch = curr->outputLink;
            while(parallelMatch != NULL){
                //cout<<parallelMatch->word<<endl;
                parallelMatch = parallelMatch->outputLink;
            }
        }
    }
      
};
/*
Huge shoutout to colin james, the best resource on this algorithm I've found thus far:
https://compiler.club/aho-corasick/
*/
