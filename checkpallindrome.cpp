class Solution {
    //1 2 2 1   → palindrome
//1 2 3 1   → palindrome nahi
// Tumhe exactly kya karna hai?
// Check karo ki linked list palindrome hai ya nahi
//Agar haan → true
//Agar nahi → false

//Important constraints (hidden)
//Singly linked list hai
//→ peeche traverse nahi kar sakte
//Extra space ideally use nahi karni
//→ O(1) space expected
//List modify nahi honi chahiye
//→ agar karo to wapas restore karo

public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //0 ya 1 node wali linked list hamesha palindrome hoti hai. neeche wala code is liye hai
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* slow = head;//two pointer tortoise 
        ListNode* fast = head;//
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //poora two pointer chla lo upr wala 


        //hum poora linklist nhi iterate isliye kr rhe hai kuki half ko reverse krke verify kr lenge
        //
        // hm ye slow->next reverse isliye kr rhe hai
        //kuki jb two pointer chlega tb hm 
        //slow middle pe hoga
        //vha se reverse kr lo
        //phr compare kr lo
        ListNode* newHead =reverseLinkedList(slow->next);

         
         //Do pointers bana rahe hain comparison ke liye
         //first → first half of linked list (start se)
        //second → reversed second half of linked list
        ListNode* first = head;
        ListNode* second = newHead;


        while (second != NULL) {
         //if (first->val != second->val)
         // Agar kahin bhi value mismatch:
         // palindrome nahi hai ❌
         // list ko wapas original bana dete hain
         // false return
            if (first->val != second->val) {
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;//first half mein aage badho
            second = second->next;//second half mein aage badho
        }
        reverseLinkedList(newHead);//--good practice k liye ye kr rhe hai// 
        return true;
    }
};