class Solution {
    public String reverseWords(String s) {
        var words = Arrays.asList(s.trim().split("\\s+"));
        Collections.reverse(words);
        return String.join(" ", words);
    }
}
