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


 class Compare{
  public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val ;
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode* , vector<ListNode*>, Compare>pq;

        for(auto list:lists){ 
            if(list!=NULL)             // Push all the heads of each list to the heap
                pq.push(list);
        }

ListNode* dummy = new ListNode(0);            //Create a merged list
ListNode* tail = dummy;

while(!pq.empty()){
    ListNode* smallest = pq.top();            //Since the PQ is min heap , the smallest element is always at the front
    pq.pop();
  
    tail->next = smallest;                          //Merge the smallest node to the tail 
    tail = tail->next;

    if(smallest->next!=NULL){                              // Push the next element of the smallest node to the PQ
        pq.push(smallest->next);
    }
}
        
   return dummy->next;     
            }
};