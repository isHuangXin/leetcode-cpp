//
// Created by huangxin on 2023/8/17.
//

#include <iostream>
#include <unordered_map>

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    std::unordered_map<int, DLinkedNode*> cache_map;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache_map.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache_map[key];
        move_to_head(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache_map.count(key)) {
            // key不存在缓存中
            DLinkedNode* node = new DLinkedNode(key, value);
            cache_map[key] = node;
            add_to_head(node);
            ++size;
            if (size > capacity) {
                DLinkedNode* removed = remove_tail();
                cache_map.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            // key存在缓存中
            DLinkedNode* node = cache_map[key];
            node->value = value;
            move_to_head(node);
        }
    }

    void move_to_head(DLinkedNode* node) {
        remove_node(node);
        add_to_head(node);
    }

    void remove_node(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add_to_head(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;

      //  head->next->prev = node;
      //  node->next = head->next;
      //  head->next = node;
      //  node->prev = head;
    }

    DLinkedNode* remove_tail() {
        DLinkedNode* node = tail->prev;
        remove_node(node);
        return node;
    }
};