// Link : https://leetcode.com/problems/search-suggestions-system/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int prefCount;
    int endCount;
    unordered_map<char, Node*> child;
    Node() {
        prefCount = 0;
        endCount = 0;
    }
};

class Trie {
    Node* root;

    private:
    void DFS(Node* curNode, string &curString, vector<string> &ans) {
        if(ans.size() == 3)
            return;
        
        if(curNode->endCount > 0)
            ans.push_back(curString);
        
        // Let's go in increasing order of characters
        for(char ch = 'a'; ch <= 'z'; ++ch) {
            if(!curNode->child.count(ch))
                continue;
            curString += ch;
            DFS(curNode->child[ch], curString, ans);
            curString.pop_back();
        }
    }

    public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) { // Time = O(length of word)
        Node* cur = root;

        for(char ch : word) {
            
            cur->prefCount += 1;

            if(!cur->child.count(ch))
                cur->child[ch] = new Node();
            
            cur = cur->child[ch];
        }

        // Reached the node corresponding to the last character.
        cur->prefCount += 1;
        cur->endCount += 1;
    }

    vector<string> getTop3Words(string w) {
        // Let's go to the node corresponding to w first.
        Node* cur = root;
        for(char ch : w) {
            if(!cur->child.count(ch))
                return vector<string>{}; // Return empty list
            cur = cur->child[ch];
        }

        // Now, we're at the node corresponding to the prefix.
        // Notice, that pre-order traversal will be in lexicographical
        // order => curNode -> child['a'] -> child['b'] .... child['z']
        vector<string> ans;
        DFS(cur, w, ans);
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        
        for(string product : products)
            t.insert(product);
        
        vector<vector<string>> ans;
        for(int l = 1; l <= searchWord.length(); ++l)
            ans.push_back(t.getTop3Words(searchWord.substr(0, l)));
        
        return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}
