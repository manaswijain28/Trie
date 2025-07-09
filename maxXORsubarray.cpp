//User function Template for C++

class Node{
    public:
    Node* children[2];
    Node(){
        for(int i=0;i<2;i++){
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
    
    void insert(int num){
        Node* curr = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(curr->children[bit] == NULL){
                curr->children[bit] = new Node();
                
            }
            
            curr = curr->children[bit];
        }
    }
    
    int Xor(int num){
        Node* curr = root;
        
        int xorval = 0;
        
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            int oppobit = bit^1;
            
            if(curr->children[oppobit] != NULL){
                xorval |= (1<<i);
                curr = curr->children[oppobit];
            }else{
                curr = curr->children[bit];
            }
        }
        
        return xorval;
    }
    
};
class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){
        vector<int> v;
        int ans = 0;
        
        Trie* obj = new Trie();
        obj->insert(0);
        for(int i=0;i<N;i++){
            ans ^= arr[i];
            obj->insert(ans);
            
            v.push_back(obj->Xor(ans));
            
        }
        
        sort(v.begin(),v.end());
        return v[v.size()-1];
        
        
    }
};
