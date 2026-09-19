class Node{
    public:
        vector<Node*> children;
        bool isTerminal;
        Node(){
            this->children.resize(27);
            for(int i = 0;i<27;i++){
                this->children[i] = nullptr;
            }
            this->isTerminal = false;
        }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        this->root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(char ch:word){
            int idx = ch-'a';
            if(temp->children[idx] == nullptr){
                temp->children[idx] = new Node();
            }
            temp = temp->children[idx];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        queue<Node*> q;
        Node* temp = root;
        q.push(temp);
        for(char ch:word){
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                Node* fr = q.front();
                q.pop();
                if(ch == '.'){
                    for(int idx = 0;idx<26;idx++){
                        if(fr->children[idx] != nullptr){
                            q.push(fr->children[idx]);
                        }
                    }
                }
                else{
                    int idx = ch-'a';
                    if(fr->children[idx] != nullptr){
                        q.push(fr->children[idx]);
                    }
                }
            }
        }
     
        while(!q.empty()){
            if(q.front()->isTerminal) return true;
            q.pop(); 
        }
        return false;
    }
};
