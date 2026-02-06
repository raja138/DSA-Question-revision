/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Tumhe do singly linked lists diye gaye hain:
//headA aur headB
// Agar dono linked lists kisi ek node se same ho jaati hain
//(matlab same memory node, sirf value same hona kaafi nahi)
// to wo pehla common node return karo
//Agar koi common node nahi hai
// NULL return karo



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //are bhai agar heada null hai ya headb null hai to kya hi chaiye
        //null return kr do
        if(headA ==NULL || headB ==NULL)
        {
            return NULL;
        }

        //nya bnaya d1 and d2 taaking headA headB neeche use ho ske 
        ListNode *d1=headA;
        ListNode *d2=headB;

        //jb tk d1 and d2 barabr na ho
        while(d1!=d2)
        {
            //bhai ye vo  formulae hai ki agar ek list traverse ho jaaye to dusri pe chale jao
            //aur a ko dusri b aur b ko dusri a aur end me common mil jayega
            d1=(d1==NULL)?headB:d1->next;
            d2=(d2==NULL)?headA:d2->next;
        }
        return d1;//bhai yha kuch bhi return krskte hai d1 ya d2

        return d1;
    }
};