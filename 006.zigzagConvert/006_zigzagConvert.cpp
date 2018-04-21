/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string s, int numRows);
 *Example:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
    public:
        string convert(string s, int numRows) {
            //如果字符串为空，或要划分的行数大于等于字符串长度，或只需划分一行，则字符串顺序不变，原样返回
            if (s.length() == 0 || s.length() <= numRows || numRows <= 1)
                return s;
            //简单想法：创建一个string类型的vector，将原字符串的字符按zigzag排放顺序放进vector中，再从vector读出到要返回的string中
            int row = 0, step = 0;
            vector<string> zigZagArr(numRows,"");
            string zigZagStr = "";
            for (int i = 0; i < s.length(); i++) {
                zigZagArr[row].push_back(s[i]);

                //如果到达第一行，则顺序往下一行一行填充
                if (row == 0)
                    step = 1;
                //如果到达最后一行，则之后是逆序往上一行一行填充
                else if (row == numRows - 1)
                    step = -1;

                row += step;

            }

            for(int i = 0; i < numRows; i++){
                zigZagStr.append(zigZagArr[i]);
            }
            return zigZagStr;
            
        }
};

int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    string zigZagArr = solution.convert(s, 4);
    cout << zigZagArr << endl;
    return 0;
}
