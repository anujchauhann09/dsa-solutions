// PROBLEM/QUESTION LINK - https://leetcode.com/problems/number-of-senior-citizens/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(int i = 0; i < details.size(); i++) { // 11, 12
            string str = details[i].substr(11, 2); 
            int age = stoi(str);

            if(age > 60)
                count++;
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};

    s.countSeniors(details);

    // ...

    return 0;
}