



void insert(string s)
{
    node *temp=root;

    for(int i=0;s[i]<'/0';i++)
    {
        char ch=s[i];
        if(temp->h.count(ch))
        {
            temp=temp->h[ch];
        }
        else{
            temp->h[ch]=new node(ch);
            temp=temp->h[ch];
        }
        temp->isterminal=true;
    }
}