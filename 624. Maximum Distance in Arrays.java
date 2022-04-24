//Not that
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int most_min = arrays.get(0).get(0);
        int most_max = arrays.get(0).get(arrays.get(0).size() - 1);
        
        for(int i = 1; i < arrays.size(); i ++) {
            most_min = Math.min(most_min, arrays.get(i).get(0));
            most_max = Math.max(most_max, arrays.get(i).get(arrays.get(i).size() - 1));
        }
        
        
        return most_max - most_min;
    }
}
//[[1, 2, 3, 4, 5, 6], [4, 5]]

//But this
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int res = 0;
        int n = arrays.get(0).size();
        int min_val = arrays.get(0).get(0);
        int max_val = arrays.get(0).get(arrays.get(0).size() - 1);
        for (int i = 1; i < arrays.size(); i++) {
            List<Integer> currentArray = arrays.get(i);
            n = currentArray.size();
            int left = currentArray.get(0);
            int right = currentArray.get(n - 1);
            res = Math.max(res, Math.max(Math.abs(right - min_val), 
                                         Math.abs(max_val - left)));
            min_val = Math.min(min_val, left);
            max_val = Math.max(max_val, right);
        }
        return res;
    }
}
