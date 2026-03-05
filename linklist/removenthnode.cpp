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

 //question hai
 //List ke end se n-th node ko delete karna hai
//aur updated list ka head return karna hai
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //two pointer--tortoise and hair 
        ListNode* fast=head;
        ListNode* slow=head;
        //jo nth node remove krni hai
        //fast ko fast k next pe daalo 
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        //List: 1 → 2 → 3
// n = 3
//  Initial
// head → 1
// slow = 1
// fast = 1
//  Step 1: fast ko n steps aage le jao
// i = 0
// fast = 2
// i = 1
// fast = 3
// i = 2
// fast = NULL
//  Loop khatam
//  Ab condition check hogi:
// if (fast == NULL)
//  TRUE
//  Ab iska matlab kya hai?
// fast ko n steps chalaya
// Agar fast == NULL ho gaya
//  List ki length = n
//  End se n-th node kaun hota hai jab length = n?
// 1 → 2 → 3
// ↑
// HEAD
//  HEAD hi delete karna ha

        if(fast==NULL) return head->next;

        //fast ko end tak le ja rahe hain aur slow ko uske saath chala rahe hain,
         //taaki slow delete hone wali node se just pehle aa jaaye
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        //kuki delete krne wala slow ka next hai hum upr dekho just pehele aaye
        ListNode* delNode=slow->next;

        //slow ka next jo hai vo slow ka next ka next hai
        slow->next=slow->next->next;
        
        //delete kr do delNode ko
        delete delNode;
        
        //return kr do node ko
        return head;
    }
};