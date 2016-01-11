class WordDictionary {
public:

    WordDictionary () {
        root = newNode ();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        insert (word , root);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs (root , word , 0);
    }

private:
    struct Trie {
        Trie *next[26];
        bool isWord;
    }*root;
    
    Trie *newNode () {
        Trie *p = new Trie ();
        memset (p -> next , NULL , sizeof (p -> next));
        p -> isWord = false;
        return p;
    }
    
    void insert (string s , Trie *root) {
        for (char ch : s) {
            if (root -> next[ch - 'a'] == NULL) root -> next[ch - 'a'] = newNode ();
            root = root -> next[ch - 'a'];
        }
        root -> isWord = true;
    }
    
    bool dfs (Trie *root , string &word , int idx) {
        if (root == NULL) return false;
        if (idx == (int)word.size ()) {
            return root -> isWord;
        }
        if (word[idx] == '.') {
            for (int i = 0 ; i < 26 ; i ++) {
                if (dfs (root -> next[i] , word , idx + 1))
                    return true;
            }
            return false;
        }
        else return dfs (root -> next[word[idx] - 'a'] , word , idx + 1);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
