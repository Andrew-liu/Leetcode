#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : isWord(false) {
        for(int i = 0; i < 26; ++i) {
            child[i] = NULL;  //初始化
        }
    }
    TrieNode* child[26]; //每个节点有26个子节点, 表示26个字母
    bool isWord; //表示该节点是否存储了字母
};

class Trie {
public:
    Trie() {
        root = new TrieNode();  //创建根节点, 字典树中的根节点为空
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if(node->child[index] == NULL) {
                node->child[index] = new TrieNode(); //分配空间
            }
            node = node->child[index];  //循环的下放节点
        }
        node->isWord = true;  //节点表示单词的终点为true
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if(node->child[index] == NULL) {
                return false;
            }
            node = node->child[index]; //相当于 node = node->next;
        }
        return node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.size(); ++i) {
            int index = prefix[index] - 'a';  //类似于上边的search
            if(node->child[index] == NULL) {
                return false;
            }
            node = node->child[index];
        }
        return true;
    }

private:
    TrieNode* root;
};
int main(int argc, const char *argv[])
{
    Trie t;
    t.insert("ab");
    cout << t.search("a") << endl;
    cout << t.search("ab") << endl;
    cout << t.startsWith("a") << endl;
    cout << t.startsWith("ab") << endl;
    return 0;
}
