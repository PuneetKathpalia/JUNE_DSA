#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    unordered_map<int, int> keyToVal;
    unordered_map<int, list<int>::iterator> keyToNode;
    list<int> orderOfKeys;
    int cap;

    void evictAppropriately() {
        int culpritKey = orderOfKeys.front();

        orderOfKeys.pop_front();
        keyToVal.erase(culpritKey);
        keyToNode.erase(culpritKey);
    }

    void UpdateTimeToNow(int key) {
        // If present already, then delete it.
        if(keyToNode.count(key)) {
            auto it = keyToNode[key];
            orderOfKeys.erase(it);
        }

        // Add it to the back of the ll
        // & update keyToNode map.
        orderOfKeys.push_back(key);
        keyToNode[key] = --orderOfKeys.end();
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!keyToVal.count(key))
            return -1;
        UpdateTimeToNow(key);
        return keyToVal[key];
    }
    
    void put(int key, int value) {
        keyToVal[key] = value;
        UpdateTimeToNow(key);

        if(keyToVal.size() > cap)
            evictAppropriately();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
int main() {
	// your code goes here
	return 0;
}