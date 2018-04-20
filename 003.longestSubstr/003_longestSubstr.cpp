/*
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxLen = 0;
            string longestSubstr = "";
            int startIdx = 0,  endIdx = 0;
            for (unsigned int i = 0; i < s.length(); i++) {
                //查找当前字符在最长子串中的位置，没找到返回-1，否则返回在字串中的位置（要注意并不是在整个输入字串中的位置，它在原始字串中的位置是pos+startIdx）
                int pos = longestSubstr.find(s[i]);
                endIdx += 1;
                cout << "pos: " << pos << endl;
                if (pos == -1) {
               //     cout << s.substr(i,1) << endl;
                    longestSubstr.append(s.substr(i,1));
                    //endIdx += 1;
                    if (endIdx - startIdx > maxLen)
                        maxLen = endIdx - startIdx;
                } else {
                    //最长字串中存在当前字符,则从原最长字串中重复当前字符的位置的下一个字符开始截取到当前字符位置的字串作为最长字串
                    //容易犯错的地方是：最长字串赋值为从当前字符开始，这没有考虑到像“dvdf”这样的两个重复字符不是紧邻着的情况
                    longestSubstr = s.substr(startIdx+pos+1, i-startIdx-pos);
                    startIdx += pos + 1;
                    //endIdx = i+1;
                }
            }
            return maxLen;

        }
};

int main()
{
    Solution solution;
    //string s = "pwwkew";
    string s = "dvdf";
//    string s = "";
    int maxLen;
    maxLen = solution.lengthOfLongestSubstring(s);
    cout << maxLen << endl;
    return 0;
}
