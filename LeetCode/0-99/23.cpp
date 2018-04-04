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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)  return NULL;
        auto cmp = [](ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap_(cmp);
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]!=NULL){
                heap_.push(lists[i]);
            }
        }
        ListNode* pre = new ListNode(0);
        ListNode* curr = pre;
        while(heap_.size()>0){
            ListNode* top = heap_.top();        
            heap_.pop();
            curr->next = top;
            curr = curr->next;
            if(top->next!=NULL)
                heap_.push(top->next);
        }
        return pre->next;
    }
};