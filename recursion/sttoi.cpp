//pehle space phr sign phr 0



class Solution {
public:
       long long solve(string &s,int i,long long num,int sign)
       {
     if(i>=s.size()||!isdigit(s[i]))
     {
        return num*sign;
     }

     int digit=s[i]-'0';
     num=num*10+digit;
     long long val=num*sign;
     if(val>INT_MAX) return INT_MAX;
     if(val<INT_MIN) return INT_MIN;
     return solve(s,i+1,num,sign);
       }
    int myAtoi(string s) {
     int i=0;
     int n=s.size();
     while(i<n && s[i]==' ') i++;
     int sign=1;
     if(i<n && (s[i]=='-'||s[i]=='+'))
     {

        if(s[i]=='-') sign=-1;
        i++;
     }
     while(i<n &&s[i]=='0') i++;
     long long ans=solve(s,i,0,sign);
     if(ans>INT_MAX) return INT_MAX;
     if(ans<INT_MIN) return INT_MIN;
     return ans;
    }
};