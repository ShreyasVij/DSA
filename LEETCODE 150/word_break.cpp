#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
class solution{
    public:
        bool wordBreak(string s, vector<string>& wordDict){
            int n = s.size();
            unodered_set<string>dict(wordDict.begin(), wordDict.end());
            vector<bool>dp(n+1, false);
            dp[0]=true; 
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < i ; j++){
                    string word = s.substr(j, i-j);
                    if(dp[j] && dict.count(word)){
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[n];
        }
};