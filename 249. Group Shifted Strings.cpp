class Solution {
public:
    string normalize(string s) {
        int delta = s[0] - 'a';
        for(int i = 0; i < s.size(); i ++) {
            int newCharInt = s[i] - delta;
            if(newCharInt < 'a')
                newCharInt += 26;
            s[i] = (char)(newCharInt);
        }
        return s;
    }
    vector<vector<string>> groupStrings(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        for(int i = 0; i < strs.size(); i ++) {
            anagrams[normalize(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> ret(anagrams.size());
        int index = 0;
        for(map<string, vector<string>>::iterator it = anagrams.begin(); it != anagrams.end(); it ++) {
            auto strings = it->second;
            for(int i = 0; i < strings.size(); i ++)
                ret[index].push_back(strings[i]);
            index ++;
        }
        return ret;
    }
};
