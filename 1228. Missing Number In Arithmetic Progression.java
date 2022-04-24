class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        int delta = (arr[n - 1] - arr[0]) / n;
        for(int i = 1; i < n; i ++) {
            int diff = arr[i] - arr[i - 1];
            if(diff != delta) return arr[i - 1] + delta;
        }
        return arr[0];
    }
}
