class Node{
    public:
    bool isSpecial;
    int value;
    int totValue;
    Node* children[26];
    Node(){
        isSpecial = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        value = 0;
        totValue = 0;
    }
};

class MapSum {
public:

    Node* root;

    MapSum() {
        root = new Node();

        
    }

    void precomp(Node* curr){
        curr->totValue = curr->value;
        for(int i=0;i<26;i++){
            if(curr->children[i] != NULL){
                curr->totValue += curr->children[i]->totValue;
            }
        }

    }

    void addRec(string &s,Node* curr,int idx,int val){
        if(idx == s.size()){
            curr->value = val;
            precomp(curr);
            return;

        }

        if(curr->children[s[idx]-'a'] == NULL){
            curr->children[s[idx]-'a'] = new Node();
        }

        addRec(s,curr->children[s[idx]-'a'],idx+1,val);
        precomp(curr);
    }
    void insert(string key, int val) {
        addRec(key,root,0,val);
        
    }
    
    int sum(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.size();i++){
            if(curr->children[prefix[i]-'a'] != NULL){
                curr = curr->children[prefix[i]-'a'];
            }else{
                return 0;
            }
        }

        return curr->totValue;
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
