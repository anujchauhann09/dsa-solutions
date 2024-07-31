// PROBLEM/QUESTION LINK - https://leetcode.com/problems/word-pattern/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> sMap; 
        unordered_map<string, char> pMap; 
        stringstream ss(s);
        vector<string> words;
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (words.size() != pattern.size()) {
            return false;
        }
        
        for (int i = 0; i < pattern.size(); ++i) {
            char p = pattern[i];
            string w = words[i];

            if (sMap.count(p)) {
                if (sMap[p] != w) {
                    return false;
                }
            } else {
                sMap[p] = w;
            }

            if (pMap.count(w)) {
                if (pMap[w] != p) {
                    return false;
                }
            } else {
                pMap[w] = p;
            }
        }
        
        return true;
    }
};

int main() {
    Solution s;
    bool answer = s.wordPattern("abba", "dog cat cat dog");

    // ...

    return 0;
}
