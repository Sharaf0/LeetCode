class Solution {
public:
    vector<string> res;
    string temp;
    int n;
    void f(int index, int left, int right) {
        if(index == 2 * n) {
            res.push_back(temp);
            return;
        }
        if(right < left) {
            temp.push_back(')');
            f(index + 1, left, right + 1);
            temp.pop_back();
        }
        if(left < n) {
            temp.push_back('(');
            f(index + 1, left + 1, right);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        f(0, 0, 0);
        return this->res;
    }
};
