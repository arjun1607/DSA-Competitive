class Solution {
public:
    static int helper(vector<string> words, vector<int> farr, vector<int> &score, int idx){
        if(idx==words.size()) return 0;
        
        int score_no=helper(words, farr, score, idx+1);
        
        string word=words[idx];
        int sword=0;
        bool flag=true;
        for(char ch:word){
            if(farr[ch-'a']==0) flag=false;
            farr[ch-'a']--;
            sword+=score[ch-'a'];
        }
        int score_yes=0;
        if(flag){
            score_yes=sword+helper(words, farr, score, idx+1);
        }
        for(char ch:word){
            farr[ch-'a']++;
        }
        
        
        return max(score_yes, score_no);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> farr(26,0); for(char ch:letters) farr[ch-'a']++;
        return helper(words, farr, score, 0);
    }
};