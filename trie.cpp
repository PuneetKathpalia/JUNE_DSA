#include <bits/stdc++.h>
using namespace std;

class TrieNode {
	public:
	vector<TrieNode*> children;
	// map<char, TrieNode*> m;
	int endCount = 0;
	TrieNode() {
		children.resize(26, NULL);
	}
};

class Trie {
	TrieNode* root;
	public:

	Trie() {
		root = new TrieNode;
	}

	void insert(string word) {
		TrieNode * node = root;
		for(int i = 0; i < word.size(); i++) {
			if(node->children[word[i] - 'a']) {
				node = node->children[word[i] - 'a'];
			} else {
				node->children[word[i] - 'a'] = new TrieNode;
				node = node->children[word[i] - 'a'];
			}
		}
		node->endCount++;
	}
	bool search(string word) {
		TrieNode * node = root;
		for(int i=0 ; i<word.size() ; i++){
			if(node->children[word[i] - 'a']){
				node = node->children[word[i] - 'a'];
			}
			else{
				return false;
			}
		}
		return node->endCount;
	}

    bool startsWith(string prefix) {
        TrieNode * node = root;
		for(int i=0 ; i<prefix.size() ; i++){
			if(node->children[prefix[i] - 'a']){
				node = node->children[prefix[i] - 'a'];
			}
			else{
				return false;
			}
		}
		return true;
    }

	bool remove(string word) {
		if(!search(word)) return false;
		TrieNode * node = root;
		for(int i=0 ; i<word.size() ; i++){
			node = node->children[word[i] - 'a'];
		}
		node->endCount--;
	}
};

int main() {
	Trie t;
	t.insert("hello");
	t.insert("car");
	t.insert("java");
	t.insert("table");
	t.insert("home");
	t.insert("learn");
	t.insert("learnyard");
	t.insert("carpet");
	t.insert("javascript");
	t.insert("car");
	t.insert("cars");

	cout<<t.search("car")<<endl;
	cout<<t.search("cars")<<endl;
	cout<<t.search("hell")<<endl;
	cout<<t.search("hello")<<endl;
	return 0;
}