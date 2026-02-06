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
//Linked List ka beech wala (middle) node delete karna hai.
//Agar list me:
//1 node hai → delete karke NULL
//even nodes hai → second middle delete karna hai

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        //1 node hai to return NULL
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }

       //slow and fast hai yha pe tortoise or hair
        ListNode* slow=head;
        ListNode* fast=head;
        fast=head->next->next;
       //Aisa kyu kiya?
       //Taaki slow pointer middle se pehle ruk jaaye
       //Hum middle node delete karna chahte hain
       //Isliye slow ko middle pe nahi,
       //middle se ek pehle chahiye
         
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

//Middle node delete karna
// Delete karne ke liye:
// hume middle node ka previous (pehle wala) chahiye

// 🧠 Trick kya hai?

// slow → 1 step chalta

// fast → 2 step chalta

// Soch lo:

// fast = double speed bike
// slow = normal cycle

// Jab fast finish line (end of list) pe pahunchta hai
// ➡ slow aadhe raaste pe hota hai

        slow->next=slow->next->next;//yha skip kr do
        //leetcode me memeory free ka koi concept nhi hota
        return head;
    }
};