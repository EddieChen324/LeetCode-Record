/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_A = 0;
        int length_B = 0;
        ListNode* index_A = headA;
        ListNode* index_B = headB;
        ////������������ĳ���
        while(index_A) {
            length_A++;
            index_A = index_A->next;
        }
        while(index_B) {
            length_B++;
            index_B = index_B->next;
        }
        index_A = headA;
        index_B = headB;    //��ָ�뻹ԭ����ָ����Ե�ͷ�ڵ�
        ////���A�ĳ��ȸ�С�ͽ�����B�Ե�
        if (length_A < length_B) {
            swap (length_A, length_B);
            swap (index_A, index_B);
        }
        int gap_length = length_A - length_B;
        ////��A��Bָ�����
        while (gap_length--) {
            index_A = index_A->next;
        }
        while (index_A) {
            if (index_A == index_B) {
                return index_A;
            }
            index_A = index_A->next;
            index_B = index_B->next;
        }
        return NULL;
    }
};