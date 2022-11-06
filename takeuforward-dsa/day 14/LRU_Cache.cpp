#include<bits/stdc++.h>

using namespace std;

class LRUCache{
    public:
    int capacity;
    class DLListNode{
        public:
        DLListNode* prev;
        int key;
        int value;
        DLListNode* nxt;

        DLListNode(int key, int value):key(key), value(value),prev(nullptr),nxt(nullptr){};
    };
    DLListNode* head;
    DLListNode* tail;
    unordered_map<int, DLListNode*> map;

    LRUCache(int cap):capacity(cap){
        head = new DLListNode(-1, -1);
        tail = new DLListNode(-1, -1);
        head->nxt = tail;
        tail->prev = head;
    }

    void put(int key, int value){
        if(map.find(key)!=map.end()){
            deletion(map[key]);
        }
        if(map.size()==capacity){
            deletion(tail->prev);
        }
        map[key] = new DLListNode(key, value);
        insertion(map[key]);
    }

    int get(int key){
        if(map.find(key)!=map.end()){
            int value = map[key]->value;

            deletion(map[key]);
            map[key] = new DLListNode(key, value);

            insertion(map[key]);
            return value;
        }
        else{
            return -1;
        }
    }

    void insertion(DLListNode* node){
        node->nxt = head->nxt;
        node->prev = head;
        head->nxt->prev = node;
        head->nxt = node;
    }

    void deletion(DLListNode* tmp){
        map.erase(map.find(tmp->key));
        tmp->prev->nxt = tmp->nxt;
        tmp->nxt->prev = tmp->prev;
        delete tmp;
    }

    ~LRUCache(){
        DLListNode* tmp = head;
        while(head!=nullptr){
            head = head->nxt;
            delete tmp;
            tmp = head;
        }
    }
};

int main(){
    LRUCache lru(2);

    cout << lru.get(2) << " ";
    lru.put(2,6);
    cout << lru.get(1) << " ";
    lru.put(1,5);
    lru.put(1,2);
    cout << lru.get(1)<< " ";
    cout << lru.get(2)<< " ";
    lru.put(4,4);
    cout << lru.get(4)<< " ";

    return 0;
}