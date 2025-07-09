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
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj = new Trie();
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            obj->insert(nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            int ans = obj->Xor(nums[i]);
            v.push_back(ans);
        }

        sort(v.begin(),v.end());
        return v[v.size()-1];
        
    }
};
