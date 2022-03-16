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
    ListNode* swapPairs(ListNode* head) {
            ListNode* DummyHead = new ListNode(0);
            DummyHead->next = head;  //让dummyheead指向头节点
            ListNode* cur = DummyHead;
            while (cur->next != nullptr && cur->next->next != nullptr) {
                // 记录第一个，第三个元素的位置
                ListNode* tmp = cur->next;
                ListNode* tmp2 = cur->next->next->next;
                cur->next = cur->next->next;  //改变虚拟头节点的指向
                cur->next->next = tmp;    //对调位置
                cur->next->next->next = tmp2;
                // cur向后移动两位
                cur = cur->next->next;
            } 
            return DummyHead->next;
    }
};