class Solution {
public:
    int strStr(string a, string b) {
        auto pos=a.find(b);
        return (pos==string::npos)?-1:pos;
    }
};