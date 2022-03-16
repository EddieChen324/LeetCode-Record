/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            ListNode* pre = nullptr;
            ListNode* cur = head;
            ////调用默认的构造函数
            ListNode* tmp;
            while (cur != nullptr){
            tmp = cur->next;
            cur->next = pre;    //翻转操作
            pre = cur;
            cur = tmp;    //更新pre和cur
            }
            return pre;
    }
};