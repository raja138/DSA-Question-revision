// Tumhe ek array nums diya hai jo numbers ki ek permutation hai
// (permutation = same elements ka koi order).
// Tumhara kaam hai next lexicographically greater permutation banana

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();//array ki length chahiye
        //kuki piche se start krna hai
        int idx = -1;//idx = break point
                     //Default -1 ka matlab:
//“Array already largest permutation hai”


//Why right se left?
//Right side sabse fast change hoti hai
//Lexicographical next permutation rightmost change se banti hai
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            //Why?
//Agar idx == -1
// Array fully decreasing hai
// Already last permutation
            for (int i = n - 1; i > idx; i--) {//Why end se?
//Hume nums[idx] se just greater element chahiye
//Right part already decreasing hota hai
                if (nums[i] > nums[idx]) {//Swap karna hai smallest possible bigger number se
//Taaki permutation minimum next ho
                    swap(nums[i], nums[idx]);//Why break?
//First greater element hi best hota hai
//Aage dekhne ki zarurat nahi
                    break;
                }
            }
        }
//Why reverse?
//Right part abhi descending order me hota hai
//Reverse karne se:
//Right part smallest possible ho jaata hai
        reverse(nums.begin() + idx + 1, nums.end());
    }
};

//We find the first index from the right
//  where the sequence stops increasing. 
// Then we swap it with the smallest
//  element greater than it on the right side. 
// Finally, we reverse the remaining suffix to 
// obtain the next lexicographically smallest permutation.”
