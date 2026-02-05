/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //question hai linklist me cycle detect karni hai
    //
public:
    bool hasCycle(ListNode *head) {
        //0 ya 1 node wali list mein cycle ho hi nahi sakti,
//isliye direct false return kar dete hain
        if(head==NULL || head->next==NULL)
        {
            return false;
        }

//two pinter algo lag rhi hai to ho jayega
        ListNode* slow =head;
        ListNode* fast=head;



//fast is liye check kr rhe hai kuki slow to vaise bhi piche rhega
//Agar fast->next->next NULL ho to?
// Example:
// 1 → 2 → NULL
// fast = 1
// fast->next = 2 (safe)
// fast->next->next = NULL
// Ye perfectly valid hai
// Aur assignment:
// fast = NULL;
// Ho jaata hai — koi crash nahi 👍
// ❌ Agar hum ye check karne lage:
// fast->next->next != NULL
// Toh kya hoga?
// 2-node list:
// 1 → 2 → NULL
// Is case mein:
// fast->next->next == NULL
// loop hi enter nahi karega
// ❌ unnecessary restriction
        while(fast!=NULL && fast->next!=NULL)
        {
            //slow pointer slow chlega
            slow=slow->next;
            //fast ek fast chlega
            fast=fast->next->next;
            //agr slow aur fast kbhi brabr hua to loop hai return true
            if(slow==fast)
            {
                return true;
            }
        }
        //poora ll traverse aur hme loop nhi mila
        return false;
    }
};