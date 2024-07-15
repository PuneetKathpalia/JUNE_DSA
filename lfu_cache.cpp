#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    unordered_map<int,int> keyToVal;
    unordered_map<int,int> keyToFreq;
    unordered_map<int,list<int>::iterator> keyToNode;
    map<int,list<int> > freqToKeys;
    int cap;

    void evictAppropriately() {
        int minFreq = freqToKeys.begin()->first;
        int culpritKey = freqToKeys[minFreq].front();

        keyToVal.erase(culpritKey);
        keyToFreq.erase(culpritKey);
        keyToNode.erase(culpritKey);
        freqToKeys[minFreq].pop_front();
        if(freqToKeys[minFreq].empty())
            freqToKeys.erase(minFreq);
    }

    void transferFreq(int key) {

        // Getting rid of the old node.
        int oldFreq = keyToFreq[key];
        auto nodeToDel = keyToNode[key];
        freqToKeys[oldFreq].erase(nodeToDel);
        if(freqToKeys[oldFreq].empty())
            freqToKeys.erase(oldFreq);

        // Correcting stuff.
        keyToFreq[key] = oldFreq + 1;
        freqToKeys[oldFreq + 1].push_back(key);
        keyToNode[key] = --freqToKeys[oldFreq + 1].end();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!keyToVal.count(key))
            return -1;
        
        /*
            1. Remove it from old freq list.
            2. Add to the back of the new freq list.
            3. Update the keyToFreq & keyToNode etc.
        */
        transferFreq(key);

        return keyToVal[key];
    }
    
    void put(int key, int value) {
        if(keyToVal.count(key)) {
            transferFreq(key);
            keyToVal[key] = value;
            return;
        }
        // Definitely a new key.
        if(keyToVal.size() == cap) {
            evictAppropriately();
        }

        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_back(key);
        keyToNode[key] = --freqToKeys[1].end();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
int main() {
	// your code goes here
	return 0;
}