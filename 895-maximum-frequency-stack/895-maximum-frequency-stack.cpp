class FreqStack {
public:
    FreqStack() {
        
    }
    
    unordered_map<int, stack<int>> st;
    unordered_map<int, int> fmap;
    int maxfreq=0;
    
    void push(int val) {
        fmap[val]++;
        int freq=fmap[val];
        st[freq].push(val);
        maxfreq=max(freq, maxfreq);
    }
    
    int pop() {
        int val = st[maxfreq].top();
        st[maxfreq].pop();
        fmap[val]--;
        if(st[maxfreq].size()==0) maxfreq--;
        return val;
    }
};

