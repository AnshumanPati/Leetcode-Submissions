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
struct mycomparator{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val; // MIN HEAP
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, mycomparator> pq;
        
        ListNode* head = nullptr; 
        ListNode* tail = nullptr;
        
        for(ListNode* list : lists){
            if(list)
                pq.push(list);
        }
        
        while(!pq.empty()){
            
            ListNode* x = pq.top();
            pq.pop();
            
            if(head == nullptr){
                tail = x;
                head  = x;
            }
            
            else{
                
                tail->next = x;
                tail = tail->next;
                
            }
            
            if(x->next){
                pq.push(x->next);
            }
            
            
        }
        
        return head;
        
    }
};