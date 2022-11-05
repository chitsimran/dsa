class Node {
public:
    bool isWord;
    unordered_map<char, Node*> children;
    
    Node() {
        isWord = false;
    }
};

class Trie {
private:
    Node* root;
    
    Node* find(string &word) {
        Node* node = root;
        for (char c : word) {
            if (!node->children[c])
                return NULL;
        }
        return node;
    }
    
    bool remove(Node* node, string &word, int i) {
        if (i == word.size()) {
            node->isWord = false;
            return true;
        }
        Node* curNode = node->children[word[i]];
        bool removeChild = remove(curNode, word, i + 1);
        if (removeChild)
            curNode->children.erase(word[i + 1]);
        return curNode->children.empty();
    }
public:
    Trie() {
        root = new Node();
    }
    
    void add(string &word) {
        Node* node = root;
        for (char c : word) {
            if (!node->children[c])
                node->children[c] = new Node();
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    void remove(string &word) {
        remove(root, word, 0);
    }
    
    bool hasPrefix(string &word) {
        return find(word) != NULL;
    }
    
    bool hasWord(string &word) {
        Node* node = find(word);
        return node && node->isWord;
    }
    
    Node* getRoot() {
        return root;
    }
};
