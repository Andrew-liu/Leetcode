class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_map<string, int> m;
        queue<string> q;
        m[beginWord] = 1;
        q.push(beginWord);
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            for(int i = 0; i < word.size(); ++i) { //对每个word进行替换
                string new_word = word;
                for(char ch = 'a'; ch <= 'z'; ++ch) { // 使用26个字母替换每一位
                    new_word[i] = ch;
                    if(new_word == endWord) {
                        return m[word] + 1;
                    }
                    if(wordList.find(new_word) != wordList.end() && m.find(new_word) == m.end()) { //在转换表中有该单词, 并且在映射表m中没有这个单词
                        q.push(new_word);
                        m[new_word] = m[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};
