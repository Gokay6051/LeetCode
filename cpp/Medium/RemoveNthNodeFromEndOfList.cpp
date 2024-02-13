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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i;
        ListNode* iter;
        ListNode* temp;
        iter = head;

        //finding out how many nodes there are
        for(i=0; iter!=NULL; ++i){
            iter = iter->next;
            //cout << i << endl;
        }

        if(i==n){
            if(head != NULL){
                head = head ->next;
                return head;
            }
            return NULL;
        }

        n = i-n;
        iter = head;
        //cout << n << endl;
        for(i=0; i<n-1; ++i){
            iter = iter->next;
            //cout << i << endl;
        }
        if(iter != NULL){
            if(iter->next != NULL)    
                iter->next = iter->next->next;
        }

        return head;
    }
};
