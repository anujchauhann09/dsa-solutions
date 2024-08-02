// PROBLEM/QUESTION LINK - https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findMax(vector<int>& bloomDay) {
        int maxi = INT_MIN;
        
        for(int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
        }

        return maxi;
    }

    bool canFillBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int countPairs = 0;
            int count = 0;

            for(int i = 0; i < bloomDay.size(); i++) {
                if (day >= bloomDay[i]) {
                    count++; 
                    if (count >= k) {
                        countPairs++; 
                        count = 0; 
                    }
                } else {
                    count = 0; 
                }
            }

            if(countPairs >= m)
                return true;

        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int answer = -1;
        int start = 1;
        int end = findMax(bloomDay);

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(canFillBouquets(bloomDay, m, k, mid)) {
                answer = mid;
                end = mid - 1;
            }
            else 
                start = mid + 1;
        }

        return answer;
    }
};

int main() {
    Solution s;
    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;

    s.minDays(bloomDay, m, k);

    // ...

    return 0;
}