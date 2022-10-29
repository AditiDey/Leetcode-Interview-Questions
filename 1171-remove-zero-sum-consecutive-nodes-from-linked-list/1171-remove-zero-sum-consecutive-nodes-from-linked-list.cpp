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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        int sum=0, flag=0;
        ListNode* new_head=head;
        ListNode* temp=head;
        while(temp!=NULL){
            sum+=temp->val;
            if(sum==0)
            { 
                new_head=temp->next;
                flag=1;
            }
            else if(mp.find(sum)==mp.end())
                mp[sum]=temp;
            else 
            {
                mp[sum]->next=temp->next; 
                flag=1;
            }
            temp=temp->next;
        }
        if(flag) 
            return removeZeroSumSublists(new_head);
        return new_head;
    }
};