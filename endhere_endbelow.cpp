class Node{
    public:
    bool isSpecial;
    Node* children[26];
    int endhere;
    int endbelow;
    Node(){
        isSpecial = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        endhere = 0;
        endbelow = 0;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }


    void precomp(Node* curr){
        curr->endbelow = curr->endhere;
        for(int i=0;i<26;i++){
            if(curr->children[i] != NULL){
                curr->endbelow += curr->children[i]->endbelow;
            }
        }
    }


    void addrec(string &s,Node* curr,int idx){
        if(idx == s.size()){
            curr->isSpecial = true;
            curr->endhere++;
            precomp(curr);
            return;

        }

        if(curr->children[s[idx]-'a'] == NULL){
            curr->children[s[idx]-'a'] = new Node();
        }

        addrec(s,curr->children[s[idx]-'a'],idx+1);
        precomp(curr);
    }

    void insert(string s){
        addrec(s,root,0);
    }

    int search(string &s){
        Node* curr = root;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if(curr->children[s[i]-'a'] == NULL){
                return 0;
            }

            curr = curr->children[s[i]-'a'];
            sum += curr->endbelow;
        }

        return sum;
    }


};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        Trie* obj = new Trie();
        for(int i=0;i<words.size();i++){
            obj->insert(words[i]);
        }

        vector<int> v;
        for(int i=0;i<words.size();i++){
            v.push_back(obj->search(words[i]));
        }

        return v;
        
    }
};
