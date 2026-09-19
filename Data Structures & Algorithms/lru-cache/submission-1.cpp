class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            this->key = _key;
            this->val = _val;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    Node* front;
    Node* back;
    int cap;
    int sz;
    LRUCache(int capacity) {
        this->cap = capacity;
        this->sz = 0;
        this->back = new Node(-1,-1);
        this->front = new Node(-1,-1);
        front->next = back;
        back->prev = front;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            Node* p = temp->prev;
            Node* nxt = temp->next;
            p->next = nxt;
            nxt->prev = p;
            temp->prev = nullptr;
            temp->next = nullptr;
            back->prev->next = temp;
            temp->prev = back->prev;
            temp->next = back;
            back->prev = temp;
            mp[key] = temp;
            return temp->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            int val = get(key);
            mp[key]->val = value;
        }
        else{
            Node* curr = new Node(key,value);
            Node* t = back->prev;
            t->next = curr;
            curr->prev = t;
            curr->next = back;
            back->prev = curr;
            mp[key] = curr;
            sz++;
            if(sz > cap){
                Node* temp = front->next;
                front->next = temp->next;
                temp->next->prev = front;
                temp->next = nullptr;
                temp->prev = nullptr;
                mp.erase(temp->key);
                delete temp;
                sz--;
            }
        }
        
    }
};
