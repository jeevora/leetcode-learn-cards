/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
    // DP bottom-UP tabulation
    int bottomUP(vector<int> coins, int amount){
        
        int n = coins.size();

        int dp[n+1][amount+1];

        for (int row = 0; row <= n; row++)
            dp[row][0] = 0;

        for (int col = 1; col <= n; col++)
            dp[0][1] = 1e55; 

        for
        
        

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
    }
};
// @lc code=end

int main(){

    vector<int> coins = {1,2,5};
    int amount = 11;

    Solution sl;
    return sl.coinChange(coins, amount);
}

