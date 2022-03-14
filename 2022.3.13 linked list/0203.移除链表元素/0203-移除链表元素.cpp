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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* DummyHead = new ListNode(0);    //����һ������ͷ�ڵ�
        DummyHead -> next = head;    //������ͷ�ڵ�ָ��ͷ�ڵ�
        ListNode* tmp = DummyHead;    //ѭ�������ָ��
        //ѭ������ֱ��β��
        while(tmp -> next != nullptr) {
            //����ҵ�target���ȱ���target��λ�ã��ٽ�target��ǰһ�����ָ��target��һ���ڵ�
            if (tmp -> next -> val == val) {
                ListNode* target = tmp -> next;    //ע���Ⱥ�˳����һ��Ҫ��д
                tmp -> next = tmp ->next -> next;
                delete target;    //ɾ��target�ڵ�
            }
            //û�ҵ���ָ����һ���ڵ�
            else {
                tmp = tmp -> next;
            }
        }
        head = DummyHead -> next;    //����ͷ�ڵ�ĺ�һ�������µ�ͷ�ڵ�
        delete DummyHead;    //ɾ������ͷ�ڵ�
        return head;
    }
};