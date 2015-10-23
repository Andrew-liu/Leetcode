/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(){
        isWord = false;
        for(int i = 0; i < 26; ++i) {
            child[i] = NULL;  //初始化
        }
    }
    TrieNode* child[26]; //每个节点有26个子节点, 表示26个字母
    bool isWord; //表示该节点是否存储了字母
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if(cur->child[index] == NULL) {
                cur->child[index] = new TrieNode();
            }
            cur = cur->child[index];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }
    bool searchWord(string& word, TrieNode* cur, int i) {
        if(i == word.size()) {
            return cur->isWord;
        }
        if(word[i] == '.') {
            for(int i = 0; i < 26; ++i) {
                if(cur->child[i] && searchWord(word, cur->child[i], i + 1)) { //如果节点不为空, 则递归的调用
                    return true;
                }
            }
            return false;
        } else {
            int index = word[i] - 'a';
            if(cur->child[index]) {
                return searchWord(word, cur->child[index], i + 1);
            } else {
                return false;
            }
        }
    }
private:
    TrieNode* root;
};

int main(int argc, const char *argv[])
{
    WordDictionary word;
    word.addWord("word");
    cout << word.search("pattern") << endl;
    cout << word.search("word") << endl;
    return 0;
}
