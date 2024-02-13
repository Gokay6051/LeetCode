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
        ListNode* iter;
        ListNode* temp;
        ListNode* temp2;

        iter = head;

        if(iter == NULL || iter->next == NULL)
            return head;
        
        iter = iter->next;
        temp = iter->next;
        iter->next = head;
        head->next = temp;
        head = iter;
        iter = iter->next;
        if(iter==NULL)
            return head;
        while(iter->next!=NULL && iter->next->next != NULL){
            temp=iter->next->next;
            iter->next->next = temp->next;
            temp->next = iter->next;
            iter->next = temp;
            iter = iter->next->next;
        }
        return head;
    }
};
