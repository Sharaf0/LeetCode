class Solution {
public:
    string normalize(string s) {
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
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
