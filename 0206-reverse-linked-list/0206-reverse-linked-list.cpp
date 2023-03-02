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
    ListNode* reverseList(ListNode* head) {
        ListNode* h = new ListNode();
        h = head;
        ListNode* prev = new ListNode();
        prev = NULL;
        ListNode* next = new ListNode();
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        while(h!=NULL){
            next = h->next;
            h->next = prev;
            prev = h;
            h = next;
        }
        return prev;
    }
};