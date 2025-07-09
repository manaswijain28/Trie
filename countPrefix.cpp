//User function Template for C++

class Node{
    public:
    bool isSpecial;
    Node* children[26];
    int count = 0;
    
    Node(){
        isSpecial = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Trie{
    public:
    Node * root;
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
            curr->count++;
        }
        
        curr->isSpecial = true;
    }
    
    string work(string s){
        Node* curr = root;
        
        string t = "";
        
        for(int j=0;j<s.size();j++){
            if(curr->children[s[j]-'a'] != NULL){
                curr = curr->children[s[j]-'a'];
                
                t += s[j];
                if(curr->count == 1){
                    return t;
                }
            }
        }
        
        
        
    }
    
    
    
};
 
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        
        Trie obj = Trie();
        for(int i=0;i<n;i++){
            obj.insert(arr[i]);
        }
        
        vector<string> v;
        for(int i=0;i<n;i++){
            
            string temp = obj.work(arr[i]);
            v.push_back(temp);
        }
        
        return v;
        
        
    }
    
};
