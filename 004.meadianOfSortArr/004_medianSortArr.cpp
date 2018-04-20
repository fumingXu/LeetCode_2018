/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        vector<int> mergeArr;
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            //两个数组均为空，则返回-1
            if (nums1.size() == 0 && nums2.size() == 0)
                return -1;
            //其中一个数组不为空，另一位空，则返回不为空的数组的中值
            else if(nums1.size() == 0 && nums2.size() != 0){
                if(nums2.size() % 2 != 0)
                    return (double)nums2[(int)nums2.size()/2];
                else
                    return (double)(nums2[nums2.size()/2] + nums2[nums2.size()/2 - 1])/2;
            }
            else if(nums1.size() != 0 && nums2.size() == 0){
                if(nums1.size() % 2 != 0)
                    return (double)nums1[(int)nums1.size()/2];
                else
                    return (double)(nums1[nums1.size()/2] + nums1[nums1.size()/2 - 1])/2;
            }
            //两个数组都不为空
            //其中一个数组的最后一个元素<=第二个元素的第一个元素，则连接两个数组，返回连接数组的中值
            if (nums1.back() <= nums2[0] || nums2.back() <= nums1[0]) {
                vector<int> tmp;
                if (nums1.back() <= nums2[0]){
                    tmp = nums1;
                    tmp.insert(tmp.end(),nums2.begin(),nums2.end());
                }
                //if (nums2.back() <= nums1[0]){
                else {
                    tmp = nums2;
                    tmp.insert(tmp.end(),nums1.begin(),nums1.end());
                }
                if(tmp.size() % 2 != 0)
                    return (double)tmp[(int)tmp.size()/2];
                else
                    return (double)(tmp[tmp.size()/2] + tmp[tmp.size()/2 - 1])/2;
            }
            //两个数组需要做交叠整合，则连接两个数组后进行归并排序
            mergeArr = nums1;
            mergeArr.insert(mergeArr.begin(),nums2.begin(),nums2.end());
            int left = 0, right = mergeArr.size() - 1;
            vector<int> tmpArr(mergeArr.size(),0);
            mergeSort(left, right, tmpArr);
            for (unsigned int i = 0; i < mergeArr.size(); i++) {
                cout << mergeArr[i] << " " ;
            }
            cout << endl;
            if(mergeArr.size() % 2 != 0)
                return (double)mergeArr[(int)mergeArr.size()/2];
            else
                return (double)(mergeArr[mergeArr.size()/2] + mergeArr[mergeArr.size()/2 - 1])/2;
        }
        void mergeSort(int left, int right, vector<int>& tmpArr) {
            if((right - left) <= 0 ) return;
            int mid = (left + right)/2;
            mergeSort(left, mid, tmpArr);
            mergeSort(mid+1, right, tmpArr);
            merge(left, mid, right, tmpArr);
        }

        void merge(int left, int mid, int right, vector<int>& tmpArr) {
            int i = left, j = mid + 1;
            int k = 0;
            while (i <= mid && j <= right) {
                if (mergeArr[i] < mergeArr[j])
                    tmpArr[k++] = mergeArr[i++];
                else
                    tmpArr[k++] = mergeArr[j++];
            }
            while (i <= mid)
                tmpArr[k++] = mergeArr[i++];
            while (j <= right)
                tmpArr[k++] = mergeArr[j++];
            for (i = 0; i < k; i++) {
                mergeArr[left+i] = tmpArr[i];
            }
            
        }
};

int main()
{
    Solution solution;
    //vector<int> nums1 = {1,2,3,4};
    //vector<int> nums2 = {2,5,6,7};
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {1,2};
    double median = solution.findMedianSortedArrays(nums1,nums2);
    cout << median << endl;
    return 0;
}
