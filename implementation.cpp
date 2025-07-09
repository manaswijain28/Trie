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
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();

        
    }
    
    void insert(string word) {
        Node * curr = root;
        for(int i=0;i<word.size();i++){
            if(curr->children[word[i]-'a'] == NULL){
                curr->children[word[i]-'a'] = new Node();
            }
            curr = curr->children[word[i]-'a'];
        }

        curr->isSpecial = true;
        
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(curr->children[word[i]-'a'] == NULL){
                return false;
            }
            curr = curr->children[word[i]-'a'];

        }
        return curr->isSpecial;
        
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.size();i++){
            if(curr->children[prefix[i]-'a'] == NULL){
                return false;
            }
            curr = curr->children[prefix[i]-'a'];
            
            
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
