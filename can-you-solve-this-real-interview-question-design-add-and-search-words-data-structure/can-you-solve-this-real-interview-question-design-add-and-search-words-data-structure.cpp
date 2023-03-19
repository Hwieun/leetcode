class Node {
public:
    bool isEndNode;
    Node* next[26];
    Node() {
        isEndNode = false;
        for(int i = 0; i <26; i++)
            next[i] = nullptr;
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;

        for(char c : word) {
            if(cur->next[c - 'a'] == nullptr) cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
        }

        cur->isEndNode = true;
    }
    
    bool search(string word) {
       return _search(root, word, 0);
    }
private:
    bool _search(Node* cur, string word, int i) {
        if(word.length() == i) return cur->isEndNode;

        if(word[i] == '.') {
            for(int j = 0; j < 26; j++) {
                if(cur->next[j] != nullptr && _search(cur->next[j], word, i+1)) return true;
            }
        }
        else if(cur->next[word[i] - 'a'] != nullptr && _search(cur->next[word[i] - 'a'], word, i+1)) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */