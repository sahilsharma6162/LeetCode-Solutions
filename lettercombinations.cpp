#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
#include<string>
using namespace std;

class Solution{
    public:

unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
int index=0;

     void backtrack(string digits,unordered_map<char, string>& mp, string current, vector<string>& final, int index ){
         if(index== digits.length()){
            final.push_back(current);
            return;
         }
         string letters= mp[digits[index]];
        for(int i=0; i<letters.length();i++){
            current.push_back(letters[i]);
             backtrack(digits, mp, current, final, index+1);
             current.pop_back();

        }
     }

     vector<string> findCombinations(int index, string digits){
        string current;
        vector<string> final;
        backtrack(digits, mp, current, final, index);
        return final;
     }
};