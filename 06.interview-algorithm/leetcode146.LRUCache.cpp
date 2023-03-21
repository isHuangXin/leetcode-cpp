#include <iostream>
#include <unordered_map>

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {};
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头节点和伪尾节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(!cache.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if(!cache.count(key)) {
            // 如果不存在
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if(size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
