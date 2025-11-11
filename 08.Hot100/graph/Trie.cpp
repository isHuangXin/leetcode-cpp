#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        // isEnd(false) 是什么意思？
        // isEnd(false) 是 TrieNode 结构体的构造函数中的一个成员初始化列表。
        // 它的作用是将 isEnd 成员变量初始化为 false，表示该节点初始时不是一个单词的结束节点。
        // 每次创建一个 TrieNode 对象时，isEnd 都会被设置为 false，直到有单词插入到 Trie 中并且该节点成为某个单词的结束节点时，isEnd 才会被设置为 true。
        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root = new TrieNode();

public:
    // Trie() {} 是构造函数吗？
    // 是的，Trie() {} 是 Trie 类的默认构造函数。
    // 构造函数是在创建类的对象时调用的特殊成员函数，用于初始化对象的成员变量或执行其他初始化任务。
    // 在这个例子中，Trie() {} 是一个空的构造函数，没有执行任何初始化操作。
    Trie() {
        
    }
    
    // 给我讲解 insert 函数的代码
    // insert 函数用于将一个单词插入到 Trie 数据结构中。以下是代码的详细解释：
    // 1. 函数接受一个字符串参数 word，表示要插入的单词。
    // 2. 定义一个指针 node，初始指向 Trie 的根节点 root。
    // 3. 遍历单词 word 的每个字符 c：
    //    - 计算字符 c 在 children 数组中的索引，通常通过 c - 'a' 来实现（假设输入的字符都是小写字母）。
    //    - 检查当前节点 node 的 children 数组中对应索引的位置是否为 nullptr：
    //      - 如果是 nullptr，表示该字符对应的子节点不存在，则创建一个新的 TrieNode 对象，并将其赋值给该位置。
    //    - 将指针 node 移动到对应的子节点，准备处理下一个字符。
    // 4. 遍历完成后，表示单词的所有字符都已插入到 Trie 中。将当前节点 node 的 isEnd 标志设置为 true，表示该节点是一个单词的结束节点。
    // 通过这种方式，insert 函数能够将单词逐字符地插入到 Trie 中，构建出一个树形结构，便于后续的搜索和前缀匹配操作。
    void insert(string word) {
        // 插入单词到 Trie 中的代码
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    // 给我讲解 search 函数的代码
    // search 函数用于在 Trie 数据结构中查找一个单词是否存在。以下是代码的详细解释：
    // 1. 函数接受一个字符串参数 word，表示要查找的单词。
    // 2. 定义一个指针 node，初始指向 Trie 的根节点 root。
    // 3. 遍历单词 word 的每个字符 c：
    //    - 计算字符 c 在 children 数组中的索引，通常通过 c - 'a' 来实现（假设输入的字符都是小写字母）。
    //    - 检查当前节点 node 的 children 数组中对应索引的位置是否为 nullptr：
    //      - 如果是 nullptr，表示该字符对应的子节点不存在，说明单词 word 不存在于 Trie 中，函数返回 false。
    //    - 如果子节点存在，将指针 node 移动到对应的子节点，准备处理下一个字符。
    // 4. 遍历完成后，表示单词的所有字符都已在 Trie 中找到。此时，检查当前节点 node 的 isEnd 标志：
    //    - 如果 isEnd 为 true，表示该节点是一个单词的结束节点，说明单词 word 存在于 Trie 中，函数返回 true。
    //    - 如果 isEnd 为 false，表示该节点不是一个单词的结束节点，说明单词 word 不 存在于 Trie 中，函数返回 false。
    // 通过这种方式，search 函数能够逐字符地在 Trie 中查找单词，判断其是否存在。
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }
    
    // 给我讲解 startsWith 函数的代码
    // startsWith 函数用于在 Trie 数据结构中检查是否存在以给定前缀开头的单词。以下是代码的详细解释：
    // 1. 函数接受一个字符串参数 prefix，表示要检查的前缀。
    // 2. 定义一个指针 node，初始指向 Trie 的根节点 root。
    // 3. 遍历前缀 prefix 的每个字符 c：
    //    - 计算字符 c 在 children 数组中的索引，通常通过 c - 'a' 来实现（假设输入的字符都是小写字母）。
    //    - 检查当前节点 node 的 children 数组中对应索引的位置是否为 nullptr：
    //      - 如果是 nullptr，表示该字符对应的子节点不存在，说明没有任何单词以该前缀开头，函数返回 false。
    //    - 如果子节点存在，将指针 node 移动到对应的子节点，准备处理下一个字符。
    // 4. 遍历完成后，表示前缀的所有字符都已在 Trie 中找到。此时，函数返回 true，表示存在以该前缀开头的单词。
    // 通过这种方式，startsWith 函数能够逐字符地在 Trie 中检查前缀，判断是否存在以该前缀开头的单词。
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
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

int main() {
    Trie* obj = new Trie();
    // 输入
    vector<string> operations = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<vector<string>> inputs = { {}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"} };
    // 输出
    vector<string> outputs = { "null", "null", "true", "false", "true", "null", "true" };
    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == "Trie") {
            cout << "null" << endl;
        } else if (operations[i] == "insert") {
            obj->insert(inputs[i][0]);
            cout << "null" << endl;
        } else if (operations[i] == "search") {
            bool result = obj->search(inputs[i][0]);
            cout << (result ? "true" : "false") << endl;
        } else if (operations[i] == "startsWith") {
            bool result = obj->startsWith(inputs[i][0]);
            cout << (result ? "true" : "false") << endl;
        }
    }
    return 0;
}