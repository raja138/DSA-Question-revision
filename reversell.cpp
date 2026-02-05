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
 //Time → O(n)

//Space → O(1) (iterative), O(n) (recursive stack)
//Tumhe kya karna hai?
// Linked list ko reverse karna hai
//Naya node banana allowed nahi
//Sirf links (next pointers) change karne hain
//Order ulta hona chahiye, values same rahengi
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //Ye recursion ka BASE CASE hai, taaki:
        //recursion infinite na chale
        //aur reversal ka sahi starting point mile

        //agar head null hai to kya reverse kroge?
        //aur agar srf ek hi node hai to reverse kise kroge
        //isliye head reverse kr do

        if(head==NULL || head->next ==NULL)
        {
            return head;
        }

        //head = [1,2,3,4,5]

        ListNode* newHead= reverseList(head->next);//recursion
        //reverseList(1)(initial function call  hmne head paas kiya na )
                  //reverseList(2)(ab ye  ListNode* newHead= reverseList(head->next).reverseList(2) call krega  )

                  //Call 1
//reverseList(1)
// └── reverseList(2)

//Call 2
//reverseList(2)
 //└── reverseList(3)

//Call 3 (BASE CASE)
//reverseList(3)
//Check:
//head->next == NULL


// head = 2
// newHead = 3
        
        //ye waali line dekh lena ku kr rhe h
        head->next->next=head;//isko aise smjho do to
        //  to base case me hai head->next->next me head 
        //niche head->next me NULL daal do
        head->next=NULL; //head->1->2->3->NULL ye hai ab kya hoga  
        // NULL<-3<-head
        //NULL<-2<-3<-head
        //NULL<-1<-2<-3<-head
        return newHead;
    }

//     Example se samjho (BEST WAY)

// Linked list:

// 1 → 2 → 3 → NULL


// Tum call karte ho:

// reverseList(1)

// Call stack banega:
// reverseList(1)
//  └── reverseList(2)
//       └── reverseList(3)

// 🔹 Base case pe kya hota hai?

// Jab:

// head = 3
// head->next = NULL


// Base case:

// return head;   // return 3


// 👉 Matlab:

// newHead = 3

// 🔁 Ab recursion wapas aata hai (IMPORTANT PART)
// Ab hum 2 pe hain:
// head = 2
// newHead = 3


// List ab logically:

// 3 → NULL
// 2 → 3


// Ab next lines ka kaam:

// head->next->next = head;   // 3->next = 2
// head->next = NULL;        // 2->next = NULL


// Result:

// 3 → 2 → NULL

// Ab hum 1 pe aate hain:
// head = 1
// newHead = 3


// Again:

// head->next->next = head;   // 2->next = 1
// head->next = NULL;        // 1->next = NULL


// Final:

// 3 → 2 → 1 → NULL
};