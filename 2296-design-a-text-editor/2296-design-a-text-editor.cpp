class TextEditor {
public:
    TextEditor() {
        
    }
    
    string s=" ";
    int i=0;
    void addText(string text) {
        s.insert(i, text);
        i+=text.size();
    }
    
    int deleteText(int k) {
        int c=i-k;
        if(c<0) c=0;
        s.erase(s.begin()+c, s.begin()+i);
        int ans=i-c;
        i=c;
        return ans;
    }
    
    string cursorLeft(int k) {
        i-=k;
        if(i<0) {
            i=0; return "";
        }
        int c=min(10,i);
        return s.substr(i-c, c); 
    }
    
    string cursorRight(int k) {
        i+=k;
        if(i>=s.size()) i=s.size()-1;
        int c=min(10,i);
        return s.substr(i-c, c); 
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

