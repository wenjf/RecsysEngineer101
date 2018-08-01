/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
维护一个tail指针；总是已经排好序的最后一个；
每次从pre的next开始比较，找到应该插入的位置；
难点在于指针操作
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* tail = head;
        while(tail&&tail->next){
            ListNode* selected = tail->next;
            if(selected->val >= tail->val){
                tail = selected;
                continue;
            }
            tail->next = selected->next;
            ListNode* current = pre;
            while(current != selected){
                if(selected->val < current->next->val){
                    selected->next = current->next;
                    current->next = selected;
                    break;
                }
                current = current->next;
            }
        }
        return pre->next;
        
    }
};