class LRUCache {
public:
    class node{
        public:
        node *next, *prev;
        int key, val;
        node(int key, int val){
            this->key=key;
            this->val=val;
            next=prev=NULL;
        }
    };
    
    node *head=new node(0, 0);
    node *tail=new node(0, 0);
    int cap;
    unordered_map<int, node*> m;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node *newnode){
        node *temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    
    void deletenode(node *temp){
        node *front = temp->next;
        node *back = temp->prev;
        back->next=front;
        front->prev=back;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *temp = m[key];
            int value=temp->val;
            m.erase(key);
            deletenode(temp);
            addnode(temp);
            m[key]=head->next;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *temp=m[key];
            m.erase(key);
            deletenode(temp);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key]=head->next;
    }
};




















