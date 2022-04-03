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
    ListNode *detectCycle(ListNode *head) {
        ////找到快慢指针的交点
        ListNode* fast = head;
        ListNode* slow = head;
        if (head == NULL) return NULL;
        if (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        else return NULL;
        if (fast->next != NULL) {
            fast = fast->next;
        }
        else return NULL;
        while (fast != slow) {
            fast = fast->next;
            if (fast == NULL) return NULL;
            fast = fast->next;
            slow = slow->next;
            if (fast == NULL) return NULL;
        }
        slow = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};