#include <bits/stdc++.h>
using namespace std;

class Trie{
public:
    class node{
    public:
        bool end;
        node* next[26];
        node(){
            end = false;
            for(int i=0;i<26;i++){
                next[i] = NULL;                    
            }
        }
    };
    node* trie;
    Trie(){
        trie = new node();
    }

    int insert(string word){
        int i = 0;
        node* it = trie;       
        while(i < word.size()){
            if(it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new node();
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
        return 1;
    }
    
    bool search(string word){
        int i=0;
        node* it = trie;
        while(i < word.size()){
            if(it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};

int main(){

    Trie *myTrie = new Trie();
    cout<<"AAA1"<<endl;
    vector<string> words = {"chintan","sutariya"};
    for(auto w: words){
        int x = myTrie->insert(w);
    }
    cout<<"AAA3"<<endl;
    if(myTrie->search("abcd")){
        cout << "abcd found"<<endl;
    }else{
        cout << "abcd not found"<<endl;
    }

    if(myTrie->search("chintan")){
        cout << "chintan found"<<endl;
    }else{
        cout << "chintan not found"<<endl;
    }

    return 0;
}