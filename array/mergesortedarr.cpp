// Tumhe 2 sorted arrays diye gaye hain:
// 🔹 nums1
// Size = m + n
// Pehle m elements sorted aur valid
// Last n elements sirf khali space (0) hain
// 🔹 nums2
// Size = n
// Saare n elements sorted
// 🎯 Tumhara kaam kya hai?
// 👉 nums2 ke saare elements nums1 me daalne hain
// 👉 Final nums1 sorted rehna chahiye
// 👉 Extra array use nahi karna (in-place merge)
// //Example se samjho
// Input
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
// Matlab:
// nums1 ke sirf [1,2,3] important
// baaki 0 sirf jagah hai
// nums2 = [2,5,6]
// Output
// nums1 = [1,2,2,3,5,6]




class Solution {
private:
       void swapifGreater(vector<int>&a,vector<int>&b,int i,int j)
       {
        if(a[i]>b[j])
        {
            swap(a[i],b[j]);
        }
       }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int len=m+n;

       //niche wala formula gap method ka hai
       //Ye ceil(len / 2) nikalne ka tareeqa hai
//(matlab: len ka aadha, upar ki taraf round karke)
       int gap=(len/2)+(len%2);
//Gap = safe middle distance


       while(gap>0)
       {
        int left=0;
        int right=left+gap;
        while(right<len)
        {
            if(left<m && right>=m)
            {
                swapifGreater(nums1,nums2,left,right-m);
            }
            else if(left >=m)
            {
                 swapifGreater(nums2,nums2,left-m,right-m);
            }
            else
            {
                 swapifGreater(nums1,nums1,left,right);
            }
            left++;
            right++;

        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
       } 
       for(int i=0;i<n;i++){
        nums1[m+i]=nums2[i];
       }       
    }
};