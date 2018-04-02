/*
* using two potiner.
* This is a useful and frequently used trick in linked list.
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num_step = 1;
        ListNode* curr = head;
        ListNode* target = new ListNode(0);
        ListNode* first = target;
        target->next = head;
        while(curr->next!=NULL){
            if(num_step < n){
                curr = curr->next;
            }
            else{
                curr = curr->next;
                target = target->next;
            }
            ++num_step;
        }
        // if(target->next==head)
        //     head = head->next; 
        // if(target->next!=NULL)
        target->next = target->next->next;
        return first->next;
    }
};