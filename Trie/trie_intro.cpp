#include <iostream>
using namespace std;
class Trienode
{
public:
    char ch;
    Trienode *children[26]; // this line creates 26 children of every node
    bool isTerminal;
    Trienode(char c)
    {
        ch = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    Trienode *root;
    Trie(){
        root=new Trienode('\0');
        // root=new Trienode(NULL);
    }
    void insertutil(Trienode *root, string word)
    {
        if (word.length() == 0) 
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        Trienode *child;
        if (root->children[index] != NULL) // means word is present     
        {
            child = root->children[index]; // move forward
        }
        else
        {
            // word not present create one
            child = new Trienode(word[0]);
            root->children[index] = child;
        }
        insertutil(child,word.substr(1));
    }
    void insert(string word)
    {
        insertutil(root, word);
    }
    bool searchutil(Trienode*root,string word)
    {
        if(word.length()==0) 
        {
                return root->isTerminal;
        }
        int index=word[0]-'a';
        Trienode*child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchutil(child,word.substr(1));
    }
    bool search(string word)
    {
        return searchutil(root, word);
    }
    void removeutil(Trienode *root, string word)
    {
        if(word.length() == 0)
        {
            if(root->isTerminal==true)
                root->isTerminal=false;
            return;
        }
        int index = word[0] - 'a';
        Trienode *child;
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            return;
        }
        removeutil(child, word.substr(1));
    }
    void remove(string word)
    {
        removeutil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("abcd");
    cout<<t->search("abcd"); 
    t->remove("abcd");
    cout<<t->search("abcd");   
    return 0;
}