class Trie {
public:

struct Node{
    Node* links[26];
    bool isEnd =false;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }

    void setEnd()
    {
        isEnd=true;
    }

    bool isEndWord()
    {
        return isEnd;
    }
};
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {   // example: "coders"

    Node* temp = root;       // traversal root se start hoga

    for(int i = 0; i < word.length(); i++) {

        char ch = word[i];   // current character

        // agar current character ka child exist nahi karta
        if(!temp->containsKey(ch)) {

            // naya node banao aur link karo
            temp->put(ch, new Node());
        }
        // next node pe move karo
        temp = temp->get(ch);
    }

    // poora word traverse ho gaya
    // last node ko mark karo as complete word
    temp->setEnd();
}
    
    bool search(string word) {
        Node* node=root;
        for(char ch:word)
        {
            if(!node->containsKey(ch))
            {
                return false;
            }
            node=node->get(ch);
        }
        return node->isEndWord();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(char ch:prefix)
        {

            if(!node->containsKey(ch))
            {
                return false;
            }
            node=node->get(ch);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */