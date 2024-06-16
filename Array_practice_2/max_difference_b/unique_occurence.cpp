class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        for(int x:arr){
            frequency[x]++;
        }
        unordered_set<int> unique;
        for (auto x: frequency){
            unique.insert(x.second);
        }
        if(frequency.size()==unique.size()) return true;
        return false;
    }
}; 