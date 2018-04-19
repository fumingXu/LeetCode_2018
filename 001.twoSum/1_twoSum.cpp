/*
 * 1. two sum
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
*/
#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;
//class Solution {
//    public:
//        vector<int> twoSum(vector<int>& nums, int target) {
//            vector<int> indexs;
//            for (unsigned int i = 0; i < nums.size() - 1; i++) {
//                for (unsigned int j = i+1; j < nums.size(); j++) {
//                    if ((nums[i] + nums[j]) == target) {
//                        indexs.push_back(i);
//                        indexs.push_back(j);
//                        return indexs;
//                    }
//                }
//            }
//        }
//};
//note: the solution above is brute force, but Time complexity : O(n^2)
//Next, another approach, and its time complexity is O(n)
class Solution{
    public:
        vector<int> twomSum(vector<int>& nums, int target) {
            unordered_map<int, int> hash;
            vector<int> result;
            for (unsigned int i = 0; i < nums.size(); i++) {
                int numToFind = target - nums[i];
                // if numToFind is found in map, return them
                if (hash.find(numToFind) != hash.end()) {
                    result.push_back(hash.find(numToFind)->second);
                    result.push_back(i);
                  //  for (unordered_map<int,int>::iterator it = hash.begin(); it != hash.end(); it++){
                  //      cout << "key value is: " << it->first << " and the mapped value is: " << it->second << endl;
                  //  }
                    return result;
                }
                //num isn't found, put it in the map
                hash[nums[i]] = i;
            }
            for (unordered_map<int,int>::iterator it = hash.begin(); it != hash.end(); it++){
                cout << "key value is: " << it->first << " and the mapped value is: " << it->second << endl;
            }
            return result;

        }
};

int main()
{
    vector<int> num;
    num.push_back(0);
    num.push_back(1);
    num.push_back(0);
    num.push_back(2);
    Solution solution;
    vector<int> result;
    result = solution.twomSum(num, 0);
    for(unsigned int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
