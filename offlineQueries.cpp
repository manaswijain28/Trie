
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
            if(curr->children[(num>>i)&1] == NULL){
                curr->children[(num>>i)&1] = new Node();
            }
            
            curr = curr->children[(num>>i)&1];
        }
    }
    
    long long Xor(int num){
        Node* curr = root;
        long long xorval = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            int oppobit = (bit)^1;
            
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
    vector<long long> maximumXor(int N, int Q, vector<int> &arr,
                                 vector<vector<int>> &queries) {
        vector<vector<int>> v;
        for(int i=0;i<Q;i++){
            v.push_back({queries[i][1],queries[i][0],i});
        }
        sort(v.begin(),v.end());
        
        sort(arr.begin(),arr.end());
        
        int mn = arr[0];
        
        Trie * obj = new Trie();
        int j = 0;
        vector<long long> temp(Q);
        
        for(int i=0;i<Q;i++){
            while(j<N && arr[j]<=v[i][0]){
                obj->insert(arr[j]);
                j++;
            }
            
            if(j == 0){
                temp[v[i][2]] = -1;
                
            }else{
                long long ans = obj->Xor(v[i][1]);
                temp[v[i][2]] = ans;
            }
            
            
        }
        
        return temp;
        
        
        
        return temp;
    }
};
