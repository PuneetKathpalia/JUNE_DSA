class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string sum1;
        string sum2;
        for(int i=0;i<word1.size();i++){
                sum1+=word1[i];
            }
        for(int j=0;j<word2.size();j++){
            sum2+=word2[j];
        }
        return sum1==sum2;
    }
};