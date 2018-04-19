/*
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 *]
*/

#include <iostream>
#include <vector>
#include <tr1/unordered_map>
#include <algorithm>

using namespace std;
using namespace std::tr1;
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector< vector<int> > result;
        for (unsigned int i = 0; i < nums.size()-2; i++) {
           
            if(nums[i] > 0)
                break;
            int target = 0 - nums[i];
            //if(nums.size() - (i+1) >= 2){
                //vector<int> numsCopy；
                //numsCopy.assign(nums.begin()+i+1,nums.end());
                unordered_map<int, int> hash;
                for (unsigned int j = i+1; j < nums.size(); j++) {
                    int numToFind = target - nums[j];
                    if(hash.find(numToFind) != hash.end()){
                        vector<int> tmp {nums[i],nums[j],nums[hash.find(numToFind)->second]};
                        //tmp.push_back(nums[i]);
                        //tmp.push_back(nums[j]);
                        //tmp.push_back(nums[hash.find(numToFind)->second]);
                        sort(tmp.begin(),tmp.end());
                        result.push_back(tmp);
                    } else{
                        hash[nums[j]] = j;
                    }
                    
                }
            //}

        }
        if (result.size() < 2)
            return result;
        vector< vector<int> > resultCopy;
        resultCopy = result;
        for (unsigned int i = 0; i < resultCopy.size()-1; i++){
            for (unsigned int j = i+1; j < resultCopy.size(); j++) {
                if (result[i] == result[j])
                    result[i].clear();
            }
        }
        vector< vector<int> > resultFinal;
        for (unsigned int i = 0; i < result.size(); i++) {
            if (!result[i].empty())
                resultFinal.push_back(result[i]);
        }
        return resultFinal;
    }
};

int main()
{

    Solution solution;
    //int a[9] = {0,-1, 0, 1, 2, 0, -1, -4, 0};
    vector<int> numArray = {82597,-9243,62390,83030,-97960,-26521,-61011,83390,-38677,12333,75987,46091,83794,19355,-71037,-6242,-28801,324,1202,-90885,-2989,-95597,-34333,35528,5680,89093,-90606,50360,-29393,-27012,53313,65213,99818,-82405,-41661,-3333,-51952,72135,-1523,26377,74685,96992,92263,15929,5467,-99555,-43348,-41689,-60383,-3990,32165,65265,-72973,-58372,12741,-48568,-46596,72419,-1859,34153,62937,81310,-61823,-96770,-54944,8845,-91184,24208,-29078,31495,65258,14198,85395,70506,-40908,56740,-12228,-40072,32429,93001,68445,-73927,25731,-91859,-24150,10093,-60271,-81683,-18126,51055,48189,-6468,25057,81194,-58628,74042,66158,-14452,-49851,-43667,11092,39189,-17025,-79173,13606,83172,92647,-59741,19343,-26644,-57607,82908,-20655,1637,80060,98994,39331,-31274,-61523,91225,-72953,13211,-75116,-98421,-41571,-69074,99587,39345,42151,-2460,98236,15690,-52507,-95803,-48935,-46492,-45606,-79254,-99851,52533,73486,39948,-7240,71815,-585,-96252,90990,-93815,93340,-71848,58733,-14859,-83082,-75794,-82082,-24871,-15206,91207,-56469,-93618,67131,-8682,75719,87429,-98757,-7535,-24890,-94160,85003,33928,75538,97456,-66424,-60074,-8527,-28697,-22308,2246,-70134,-82319,-10184,87081,-34949,-28645,-47352,-83966,-60418,-15293,-53067,-25921,55172,75064,95859,48049,34311,-86931,-38586,33686,-36714,96922,76713,-22165,-80585,-34503,-44516,39217,-28457,47227,-94036,43457,24626,-87359,26898,-70819,30528,-32397,-69486,84912,-1187,-98986,-32958,4280,-79129,-65604,9344,58964,50584,71128,-55480,24986,15086,-62360,-42977,-49482,-77256,-36895,-74818,20,3063,-49426,28152,-97329,6086,86035,-88743,35241,44249,19927,-10660,89404,24179,-26621,-6511,57745,-28750,96340,-97160,-97822,-49979,52307,79462,94273,-24808,77104,9255,-83057,77655,21361,55956,-9096,48599,-40490,-55107,2689,29608,20497,66834,-34678,23553,-81400,-66630,-96321,-34499,-12957,-20564,25610,-4322,-58462,20801,53700,71527,24669,-54534,57879,-3221,33636,3900,97832,-27688,-98715,5992,24520,-55401,-57613,-69926,57377,-77610,20123,52174,860,60429,-91994,-62403,-6218,-90610,-37263,-15052,62069,-96465,44254,8};
    vector< vector<int> > result;
    result = solution.threeSum(numArray);
    for (unsigned int i = 0; i < result.size(); i++){
        for (unsigned int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

