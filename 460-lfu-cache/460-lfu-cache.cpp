struct Node{
    int key, val, cnt;
    Node *next, *prev;
    Node(int key, int val){
        this->key=key;
        this->val=val;
        cnt=1;
        next=prev=NULL;
    }
};
struct List{
    int size;
    Node *head, *tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node *node){
        Node *temp=head->next;
        node->prev=head;
        node->next=temp;
        head->next=node;
        temp->prev=node;
        size++;
    }
    void removeNode(Node *node){
        Node *back=node->prev;
        Node *front=node->next;
        back->next=front;
        front->prev=back;
        size--;
    }
};
class LFUCache {
public:
    unordered_map<int, Node*> keynode;
    unordered_map<int, List*> freqlistmap;
    int maxsize, currsize, minfreq;
    LFUCache(int capacity) {
        maxsize=capacity;
        currsize=minfreq=0;
    }
    
    void updatefreqlistmap(Node *node){
        keynode.erase(node->key);
        freqlistmap[node->cnt]->removeNode(node);
        if(node->cnt==minfreq && freqlistmap[node->cnt]->size==0){
            minfreq++;
        }
        List *nexthigherfreqlist = new List();
        if(freqlistmap.find(node->cnt+1)!=freqlistmap.end()){
            nexthigherfreqlist =  freqlistmap[node->cnt+1];
        }
        node->cnt++;
        nexthigherfreqlist->addFront(node);
        freqlistmap[node->cnt]=nexthigherfreqlist;
        keynode[node->key]=node;
    }
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            Node *node=keynode[key];
            int val=node->val;
            updatefreqlistmap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize==0) return;
        if(keynode.find(key)!=keynode.end()){
            Node *node=keynode[key];
            node->val=value;
            updatefreqlistmap(node);
        }else{
            if(currsize==maxsize){
                List *list=freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq=1; // new element
            List *freqlist = new List();
            if(freqlistmap.find(minfreq)!=freqlistmap.end()){
                freqlist =  freqlistmap[minfreq];
            }
            Node *node=new Node(key, value);
            freqlist->addFront(node);
            keynode[key]=node;
            freqlistmap[minfreq]=freqlist;
        }
    }
};



































