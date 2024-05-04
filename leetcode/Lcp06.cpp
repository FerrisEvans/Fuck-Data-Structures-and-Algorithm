//
// Created by Ferris on 5/4/24.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int ret = 0;
        for (int i = 0; i < coins.size(); ++i) {
            ret += (coins[i] + 1) / 2;
        }
        return ret;
    }
};