class Solution {
    private boolean isPalindrome(String s, int left, int right) {
        while(left < right && s.charAt(left) == s.charAt(right)) {
            left ++;
            right --;
        }
        return s.charAt(left) == s.charAt(right);
    }
    public boolean validPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right && s.charAt(left) == s.charAt(right)) {
            left ++;
            right --;
        }
        if(left >= right) return true;
        return isPalindrome(s, left, right - 1) || isPalindrome(s, left + 1, right);
    }
}
