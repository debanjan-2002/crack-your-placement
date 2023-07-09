// Write an efficient program to print all the duplicates and their counts in the input string 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printDuplicatesAndCount(string &s) {
        vector<int> hash(26);
        for(char c : s) hash[c - 'a']++;

        for(int i = 0; i < 26; i++) {
            if(hash[i] > 1) {
                cout << (char)('a' + i) << " - " << hash[i] << "\n"; 
            }
        }
    }
};

int main() {
    Solution s;
    string t = "geeksforgeeks";
    s.printDuplicatesAndCount(t);
}