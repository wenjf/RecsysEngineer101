/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
使用slow fast two pointer
难点在于K比链表长度大时的情况，需要取余数。
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int length = 0;
        ListNode* pre = new ListNode(0);
        ListNode* current = head;
        while(current){
            current = current->next;
            ++length;
        }
        k = k%length;
        if(k == 0) return head;
        current = head;
        ListNode* later = head;
        for(int i = 0; i< k ; i++){
            if(current->next)
                current = current->next;
            else
                return head;
        }
        while(current->next){
            current = current->next;
            later = later->next;
        }
        pre->next = later->next;
        later->next = NULL;
        current->next = head;
        return pre->next;

        
        
    }
};