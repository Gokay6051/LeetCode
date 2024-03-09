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
// Faster Solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
            
        ListNode* iter;
        ListNode* flag;
        int val;

        iter = head;
        flag = iter;
        val = flag->val;
        while(iter->next != nullptr){
            if(iter->next->next == nullptr && iter->next->val == val){
                flag->next = nullptr;
                break;
            }
            else if(val == iter->next->val)
                iter = iter->next;
            else{
                flag->next = iter->next;
                iter = iter->next;
                flag = iter;
                val = flag->val;
            }
        }

        return head;
    }
};




// First Solution
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
/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
            
        ListNode* iter;
        ListNode* temp;

        iter = head;
        while(iter->next != nullptr){
            if(iter->val == iter->next->val)
                iter->next = iter->next->next;
            else
                iter = iter->next;
        }

        return head;
    }
};
*/
