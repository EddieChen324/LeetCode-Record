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
            DummyHead->next = head;  //��dummyheeadָ��ͷ�ڵ�
            ListNode* cur = DummyHead;
            while (cur->next != nullptr && cur->next->next != nullptr) {
                // ��¼��һ����������Ԫ�ص�λ��
                ListNode* tmp = cur->next;
                ListNode* tmp2 = cur->next->next->next;
                cur->next = cur->next->next;  //�ı�����ͷ�ڵ��ָ��
                cur->next->next = tmp;    //�Ե�λ��
                cur->next->next->next = tmp2;
                // cur����ƶ���λ
                cur = cur->next->next;
            } 
            return DummyHead->next;
    }
};