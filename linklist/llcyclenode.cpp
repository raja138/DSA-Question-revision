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
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            //Cycle mile
//slow = head
//1 step dono
//jahan milen wahi start

            if (slow == fast) {   
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;     
            }
        }
        return NULL;              
    }
};
