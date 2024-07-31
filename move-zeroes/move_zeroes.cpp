// PROBLEM/QUESTION LINK - https://leetcode.com/problems/move-zeroes/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int countZeroes = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                countZeroes++;
            if(nums[i] != 0)
                nums[index++] = nums[i]; 
        }

        int i = 0;
        while(countZeroes != 0) {
            nums[nums.size()-i-1] = 0;
            i++;
            countZeroes--;
        }

    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,0,3,12};

    s.moveZeroes(nums);

    for(int i = 0; i < nums.size(); i++) {
        cout<< nums[i]<< " ";
    } cout<< endl;

    return 0;
}
