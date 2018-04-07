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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        ListNode* head_1 = head;
        ListNode* head_2 = head->next;
        ListNode* current = head;
        ListNode* pre = new ListNode(0);
        ListNode* new_end = pre;
        new_end->next = head_2!=NULL ? head_2 : head_1;//判断出现奇数的特殊情况
        while(head_2 != NULL){
            current = current->next->next;
            ListNode* third_node = head_2->next;
            new_end->next = head_2;
            head_2->next = head_1;
            head_1->next = third_node;
            new_end = head_1;
            head_1= current;
            if(current != NULL){
                head_2 = current->next;                
            }
            else
                head_2 = NULL;
        }
        return pre->next;
        
    }
};