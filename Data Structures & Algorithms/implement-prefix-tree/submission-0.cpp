class Node{
    public:
        vector<Node*> children;
        bool isTerminal;
        Node(){
            this->isTerminal = false;
            this->children.resize(26);
            for(int i = 0;i<26;i++){
                children[i] = nullptr;
            }
        }
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        this->root = new Node();
    }
    
    void insert(string word) {
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
        Node* temp = root;
        for(char ch:word){
            int idx = ch-'a';
            if(temp->children[idx] == nullptr){
                return false;
            }
            temp = temp->children[idx];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch:prefix){
            int idx = ch-'a';
            if(temp->children[idx] == nullptr){
                return false;
            }
            temp = temp->children[idx];
        }
        return true;
    }
};
