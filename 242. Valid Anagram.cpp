class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> hashtable;
        for(int i = 0; i < s.size(); i ++) {
            hashtable[s[i]]++;
            hashtable[t[i]]--;
        }
        for(int i = 0; i < s.size(); i ++)
            if(hashtable[s[i]] != 0)
                return false;
        return true;
    }
};
