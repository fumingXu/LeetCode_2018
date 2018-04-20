/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */
#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //在两个链表中取加数位x和y,链表节点指针为空时为0，不为空时取其值；
        //x+y+carry为位加和结果sum，除以10后的整数结果为下一节点的值，余数为再下一个节点的进位值
        //返回加和链表的头结点
        ListNode* sumResult = new ListNode(0);
        ListNode* cur = sumResult;
        ListNode *l1Ptr=l1, *l2Ptr=l2;
        int carry = 0;
        
        while (l1Ptr || l2Ptr) {
            int x = (l1Ptr != NULL) ? l1Ptr->val : 0;
            int y = (l2Ptr != NULL) ? l2Ptr->val : 0;
            int sum = x + y + carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            if (l1Ptr)
                l1Ptr = l1Ptr->next;
            if (l2Ptr)
                l2Ptr = l2Ptr->next;
        }
        if (carry)
            cur->next = new ListNode(carry);
        return sumResult->next;
            
        
    }
};

int main()
{
    Solution solution;
    ListNode *l1 = new ListNode(2), *l2 = new ListNode(5);
    ListNode *l1Ptr = l1, *l2Ptr = l2;

    l1Ptr->next = new ListNode(4);
    l2Ptr->next = new ListNode(6);
    l1Ptr->next->next = new ListNode(3);
    l2Ptr->next->next = new ListNode(4);

    ListNode *result = solution.addTwoNumbers(l1Ptr, l2Ptr);
    for (ListNode *p = result; p != NULL; p = p->next)
        cout << p->val;
    cout << endl;
    return 0;
}
