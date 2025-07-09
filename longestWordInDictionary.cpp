class Node{
    public:
    bool isSpecial;
    Node* children[26];
    Node(){
        isSpecial = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string s){
        Node* curr = root;
        for(int i=0;i<s.size();i++){
            if(curr->children[s[i]-'a'] == NULL){
                curr->children[s[i]-'a'] = new Node();
            }
            curr = curr->children[s[i]-'a'];
        }
        curr->isSpecial = true;
    }

    int search(string s){
        Node* curr = root;
        for(int i=0;i<s.size();i++){
            if(curr->children[s[i]-'a'] == NULL){
                return 0;
            }
            curr = curr->children[s[i]-'a'];
        }

        if(curr->isSpecial){
            return 1;
        }else{
            return 0;
        }

    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie obj = Trie();
        vector<string> v;
        for(int i=0;i<words.size();i++){
            obj.insert(words[i]);
        }
        for(int i=0;i<words.size();i++){
            int present = 1;
            for(int j=0;j<words[i].size();j++){
                string t = words[i].substr(0,j+1);
                present = present & obj.search(t);
                
            }

            if(present){
                v.push_back(words[i]);
            }

        }

        sort(v.begin(),v.end());
        if(v.size() == 0){
            return "";
        }

        int mx = 0;

        for(int i=0;i<v.size();i++){
            int sz = v[i].size();
            mx = max(mx,sz);
        }

        string ans;

        for(int i=0;i<v.size();i++){
            if(v[i].size() == mx){
                ans =  v[i];
                break;
            }
        }

        return ans;

        
    }
};
