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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num = 0;
        ListNode* l3 = new ListNode;
        ListNode* iter = new ListNode;
        
        iter = l3;
        
        while(l1 != NULL || l2 != NULL || num != 0){
        	if(l1==NULL && l2 != NULL){
        		num = l2->val + num;
                l2 = l2->next;
			}
			else if(l1!=NULL && l2==NULL){
				num = l1->val + num;
                l1 = l1->next;
			}
			else if(l1 != NULL && l2 != NULL){
				num = l1->val + l2->val + num;
                l2 = l2->next;
                l1 = l1->next;
			}
        	
        	iter->val = num % 10;
        	num /= 10;
        	if(l1 != NULL || l2 != NULL || num != 0){
                iter->next = new ListNode;
        	    iter = iter->next;
            }
		}
		iter = NULL;
		return l3;
    }
};
