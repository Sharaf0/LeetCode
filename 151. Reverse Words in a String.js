/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s
        .split(' ')
        .filter(w => w != '')
        .reduceRight((prev, curr) => prev + " " + curr, "")
        .trimStart();
};
