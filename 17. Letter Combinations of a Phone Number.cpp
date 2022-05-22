class Solution {
public:
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    void f(int index, const string& digits, string& result, vector<string>& results) {
        if(index == digits.size()) {
            if(result != "")
                results.push_back(result);
            return;
        }
        for(int i = 0; i < letters[digits[index] - '0'].size(); i ++) {
            result.push_back(letters[digits[index] - '0'][i]);
            f(index + 1, digits, result, results);
            result.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string result;
        vector<string> results;
        f(0, digits, result, results);
        return results;
    }
};
