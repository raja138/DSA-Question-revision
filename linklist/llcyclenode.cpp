class Solution {
public:


//Agar linked list mein cycle hai:
// us node ka address return karo
// jahan se cycle start hoti hai
// Agar cycle nahi hai:
// NULL return karo
// Tumhe:
// list modify nahi karni
// extra memory (like hash set) use nahi karni
     ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;


        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
};
