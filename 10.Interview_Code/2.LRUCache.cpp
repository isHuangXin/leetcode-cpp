//
// Created by huangxin on 2023/9/25.
//

#include <vector>
#include <unordered_map>
#include <vector>

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {};
    DLinkedNode() : key(), value(), prev(nullptr), next(nullptr) {};
};


class LRUCache {
private:
    int size = 0;
    int capacity = 100;
    DLinkedNode* head;
    DLinkedNode* tail;
    unordered_map<int, DLinkedNode*> cache_map;

public:
    LRUCache() {
        DLinkedNode* head = new DLinkedNode;
        DLinkedNode* tail = new DLinkedNode;
        head->next = tail;
        tail->prev = head;
    }

    void put(int key, int value) {
        if (!cache_map.count(key)) {
            // 双链表中不存在这个节点
            DLinkedNode* new_node = new DLinkedNode(key, value);
            cache_map[key] = new_node;
            size++;
            if (size > capacity) {
                // 删除尾元素
                DLinkedNode* tail_node = remove_tail();
                cache_map.erase(tail_node->value);
                size--;
                delete tail_node;
                add_to_head(new_node);
            }
        } else {
            // 双链表中存在这个接待您
            DLinkedNode* node = cache_map[key];
            node->value = value;
            move_to_head(node);
        }
    }

    int get(int key) {
        if(!cache_map.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache_map[key];
        move_to_head(node);
        return node->value;
    }

    void move_to_head(DLinkedNode* node) {
        remove_tail();
        add_to_head(node);
    }

    void add_to_head(DLinkedNode* node) {
        head->next->prev = node;
        node->next = head->next;
        head->prev = head;
        head->next = node;
    }


    void remove_node(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    DLinkedNode* remove_tail() {
        DLinkedNode* taiL_node = tail->prev;
        remove_node(taiL_node);
        return taiL_node;
    }
};