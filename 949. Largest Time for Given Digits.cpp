class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        auto maxTime = make_pair(-1, -1);
        sort(arr.begin(), arr.end());
        do {
            int hs = arr[0] * 10 + arr[1];
            int ms = arr[2] * 10 + arr[3];
            if(hs > 23 || ms > 59) continue;
            auto newPair = make_pair(hs, ms);
            if(newPair > maxTime) maxTime = newPair;
        }while(next_permutation(arr.begin(), arr.end()));
        string a = to_string(maxTime.first);
        string b = to_string(maxTime.second);
        if(maxTime.first == -1) return "";
        if(a.size() < 2) a = "0" + a;
        if(b.size() < 2) b = "0" + b;
        return a + ":" + b;
    }
};
