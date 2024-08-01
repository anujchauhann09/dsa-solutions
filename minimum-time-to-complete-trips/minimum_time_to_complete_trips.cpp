// PROBLEM/QUESTION LINK - https://leetcode.com/problems/minimum-time-to-complete-trips/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canCompleteTrips(vector<int>& time, long long minTime, int totalTrips) {
        long long trips = 0;
        
        for(int i = 0; i < time.size(); i++) {
            trips += minTime / time[i];
            
            if(trips >= totalTrips) 
                return true;
        }
        
        return false; 
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long maxi = LLONG_MIN;

        for(int i = 0; i < time.size(); i++) {
            maxi = max(maxi, (long long)time[i]); 
        }

        long long start = 1;
        long long end = maxi * totalTrips; 

        long long answer = end; 

        while(start <= end) {
            long long mid = start + (end - start) / 2;

            if(canCompleteTrips(time, mid, totalTrips)) {
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
    vector<int> time = {1, 2, 3};
    int totalTrips = 5;

    long long answer = s.minimumTime(time, totalTrips);

    // ...

    return 0;
}