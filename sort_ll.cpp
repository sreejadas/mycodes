/** Problem Statement
Sort a linked list in O(n log n) time using constant space complexity

**/


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
    ListNode *sortList(ListNode *head) {
        
        ListNode *first= NULL, *second = NULL, *final = NULL;
        if(head == NULL|| head->next ==NULL)
            return head;
        SplitinTwo(head,first,second);
        first = sortList(first);
        second = sortList(second);
        final = Merge(first,second);
        
        return final;
    }
    void SplitinTwo(ListNode *head, ListNode* &first, ListNode* &second) {
        
        first = head;
        if(head ==NULL ||head->next == NULL) {
            first = head;
            second = NULL;
        } else  {
            ListNode *slow = NULL, *fast = NULL;
            slow = head;
            fast = head->next;
            while(fast!=NULL) {
                fast = fast->next;
                if(fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            first = head;
            second = slow->next;
            slow->next = NULL;
        }
    }
    ListNode *Merge(ListNode *first, ListNode *second) {
        ListNode *final=NULL;
        if(!first)
            return second;
        if(!second)
            return first;
        if(first->val <= second->val) {
            final = first;
            final->next = Merge(first->next,second);
        } else {
            final = second;
            final->next = Merge(first, second->next);
        }
        return final;
    }
};
