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
    bool isPalindrome(ListNode* head) {
        stack<int>s;
        ListNode* dummy = head;
        while(dummy!=NULL){
            s.push(dummy->val);
            dummy=dummy->next;
        }
        ListNode* tail = head;
        while(!s.empty()){
            if(s.top() != tail->val){
                return false;
            }
            s.pop();
            tail = tail->next;
        }
        return true;
    }
};