/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Input: "cbbd"
 * Output: "bb"
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            //首先，注意到回文的特点是两边对称的，奇数长度则是以一个字母为中心的，偶数长度则是以两个相同的字母为中心的；
            //所以，可以以一个字符和两个字符的情况作为中心向两边扩展，搜索符合回文的子串情况
            int startIdx = 0, endIdx = 0;
            int maxLen = 0;
            for (int i = 0; i < s.length(); i++){
                //1.寻找奇数长度的回文子串
                int lenOdd = expandFromCenter(s, i, i);
                int lenEven = expandFromCenter(s, i, i+1);

                int len = max(lenOdd, lenEven);
                cout << "current len: " << len << " max len: " << maxLen << endl;
                //如果此时找的回文子串的长度大于当前的最长回文长度，则替换
                if (len > maxLen) {
                    startIdx = i - (len-1)/2;
                    endIdx = i + len/2;
                    maxLen = len; 
                }
            }
            cout << "start: " << startIdx << " end: " << endIdx << endl;
            return s.substr(startIdx, endIdx - startIdx + 1);

        }

        int expandFromCenter(string s, int left, int right) {
            //从中心向两边扩展，寻找符合回文条件的子串，返回其长度
            int L = left, R = right;
            while (L >= 0 && R < s.length() && s[L] == s[R]) {
                L--;
                R++;
            }
            return (R - L - 1);
        }
};

int main()
{
    Solution solution;
    string s = "babad";
    //string s = "abacdfgdcaba";
   // string s = "abbc";
    string longestPalin = solution.longestPalindrome(s);
    cout << longestPalin << endl;
    return 0;
}
