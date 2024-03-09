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
        ListNode* iter;
        ListNode* temp;
        iter = head;
        if(head == nullptr)
            return head;
        
        while(head != nullptr && head->val == val)
            head = head->next;         

        while(iter->next != nullptr){
            if(iter->next->val == val)
                iter->next = iter->next->next;
            else
                iter = iter->next;
        }

        return head;
    }
};
