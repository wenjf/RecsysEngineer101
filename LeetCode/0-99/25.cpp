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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        
        ListNode* pre = new ListNode(0);//head前面的一个 链表经典操作
        pre->next = head;
        ListNode* current = head;
        ListNode* new_end = pre;//总是每一组K个的原来顺序第1个。或者最后一组(可以不足K个)的第一个
        
        //当前组第K个,反转后的第1个
        ListNode* next_begin = pre;
        for(int i = 0; i<k; ++i){
            if(next_begin->next)
                next_begin = next_begin->next;
            else{
                return head;
            }
        }
        new_end->next = next_begin;//指向下一组K个的最后一个，即为反转后的第1个。
        
        //循环不变量，next_begin每次指向当前组的第K个，当不足K个时，next_begin = NULL,退出循环
        while(next_begin!=NULL){
            new_end->next = next_begin;//原来的结尾指向当前的第K个，也就是指向反转后的第1个
            new_end = current;//有K个一组的时候
            next_begin = next_begin->next;//更新下一组的第1个，or NULL(当前组最后一组)
                            
            //翻转一组K个，第一个的next指向下一组的第一个即为 next_begin
            ListNode* temp_next = current->next;
            current->next = next_begin;
            ListNode* previous = current;
            current = temp_next;
            //第2 - K个，指向前一个
            for(int i = 1; i < k ; ++i){
                ListNode* temp_next = current->next;
                current->next = previous;
                previous = current;
                current = temp_next;
            }

            //更新next_begin,移动到下一个K个
            for(int i = 0; i<k-1; ++i){
                if(next_begin&&next_begin->next)
                    next_begin = next_begin->next;
                else{
                    new_end->next = current;
                    next_begin = NULL;
                    break;
                }
            }
        }
        return pre->next;
    }
};