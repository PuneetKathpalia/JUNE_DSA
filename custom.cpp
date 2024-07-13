#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
    const int INITIAL_SIZE = 1;
    const double MAX_LOAD_FACTOR = 0.75;
    vector<list<pair<int,int> > > arr;
    int curSize, curBuckets;

    int hash(int key) {
       return key % curBuckets; // [0, curBuckets - 1] 
    }

    void rehash() {
        vector<list<pair<int,int> > > arr2(2*curBuckets);
        curBuckets *= 2;

        // Go to all the elements in the old Array & add to new Array
        for(auto &ll : arr) {
            for(auto curPair : ll) {
                int newId = hash(curPair.first);
                arr2[newId].push_front(curPair);
            }
        }

        arr = arr2; // Update the arr;
    }

    double curLoadFactor() {
        return curSize/(double)curBuckets;
    }

    list<pair<int,int> >::iterator get(list<pair<int,int> > &ll, int key) {
        auto it = ll.begin();
        while(it != ll.end()) {
            if(it->first == key)
                return it;
            it++;
        }
        return ll.end();
    }

public:
    MyHashMap() {
        curSize = 0;
        curBuckets = INITIAL_SIZE;
        arr.resize(INITIAL_SIZE);
    }
    
    void put(int key, int value) {
        int i = hash(key);
        auto it = get(arr[i], key);

        if(it != arr[i].end()) {
            it->second = value;
        }
        else {
            arr[i].push_front(make_pair(key, value));
            curSize++;
        }

        if(curLoadFactor() > MAX_LOAD_FACTOR)
            rehash();
    }
    
    int get(int key) {
        int i = hash(key);
        for(auto curPair : arr[i]) {
            if(curPair.first == key)
                return curPair.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int i = hash(key);
        auto it = get(arr[i], key);

        if(it != arr[i].end()) {
            arr[i].erase(it);
            curSize--;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


int main() {
	return 0;
}