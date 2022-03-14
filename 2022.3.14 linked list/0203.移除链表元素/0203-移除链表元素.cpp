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
        ListNode* DummyHead = new ListNode(0);    //设置一个虚拟头节点
        DummyHead -> next = head;    //让虚拟头节点指向头节点
        ListNode* tmp = DummyHead;    //循环链表的指针
        //循环链表直到尾端
        while(tmp -> next != nullptr) {
            //如果找到target，先保存target的位置，再将target的前一个结点指向target下一个节点
            if (tmp -> next -> val == val) {
                ListNode* target = tmp -> next;    //注意先后顺序，这一句要先写
                tmp -> next = tmp ->next -> next;
                delete target;    //删除target节点
            }
            //没找到就指向下一个节点
            else {
                tmp = tmp -> next;
            }
        }
        head = DummyHead -> next;    //虚拟头节点的后一个就是新的头节点
        delete DummyHead;    //删除虚拟头节点
        return head;
    }
};