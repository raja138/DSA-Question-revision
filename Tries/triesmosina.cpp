#include<iostream>
#include <unordered_map>
using namespace std;

// //(root)
//    |
//    c
//    |
//    a
//    |
//    t

class node{
public:
	char ch;//character store krta hi hai
	bool isterminal;//ye pta krne k liye ki us string ka last node hai
	unordered_map<char,node*> h;//map hai ye 
//niche hai cat aur car ka example 
    //root
//  |
//  h = { 'c' → node_c }

// node_c
//  |
//  h = { 'a' → node_a }

// node_a
//  |
//  h = { 
//         'r' → node_r,
//         't' → node_t
//       }

// node_r (isterminal = true)
// node_t (isterminal = true)



	node(char c){//ye constructor hai
		ch=c;
		isterminal=false;
	}

};

class trie{
	node*root;
public:
	trie(){
		root=new node('\0');
	}
	// insert

    //Root se start karo
// 👉 String ke har character ke liye:
// Agar child already exist karta hai → us par move karo
// Agar exist nahi karta → new node create karo
// 👉 Last character pe isterminal = true
	void insert(string s){//coders
		node*temp=root;//Temp pointer bana jo traversal ke liye use hoga.
//Root actual tree ka starting point hai.
//Temp move karta rahega.
		for(int i=0;s[i]!='\0';i++){//string. char pe iterate kro
			char ch=s[i];//Current character nikala.
			if(temp->h.count(ch)){//count(ch) kya karta hai?
// Agar map me key exist karti hai → return 1
// Nahi karti → return 0
// Matlab:
// 👉 Kya current node ke paas is character ka child already hai?
				temp=temp->h[ch];//agar exist krta hai to next pe move kr jao
                //jaise tree me krte the
			}
			else{
                //agar exist nhi hai to new node create kiya
				temp->h[ch]=new node(ch);
			temp=temp->h[ch];
//             New node create kiya
// Map me store kiya
// Temp ko us node pe shift kiya
			}
		}
		temp->isterminal=true;// jb word complete hua to isterminal false kr diya
	}
	// ?search
	bool search(string s){//coder
		node*temp=root;
		for(int i=0;s[i]!='\0';i++){
			char ch=s[i];//r
		if(temp->h.count(ch)){
			temp=temp->h[ch];
		}
		else{
			return false;
		}

		}

		return temp->isterminal;
	}

};



int main(){
	trie t;
	t.insert("code");
	t.insert("coders");
	if(t.search("coder")==true){
		cout<<"key is present"<<endl;
	}
	else{
		cout<<"key is not present"<<endl;
	}
	return 0;
}