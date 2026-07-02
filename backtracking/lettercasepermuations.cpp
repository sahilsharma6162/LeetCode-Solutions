#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
#include<string>
using namespace std;

class Solution{
    public:

     void backtrack(const string& given, string& current,
               vector<string>& final, int index) {

    if (index == given.size()) {
        final.push_back(current);
        return;
    }

    char ch = given[index];

    if (isdigit(ch)) {
        current.push_back(ch);
        backtrack(given, current, final, index + 1);
        current.pop_back();
    }
    else {
        current.push_back(tolower(ch));
        backtrack(given, current, final, index + 1);
        current.pop_back();

        current.push_back(toupper(ch));
        backtrack(given, current, final, index + 1);
        current.pop_back();
    }
}

vector<string> letterCasePermutation(string s) {
           vector<string> ans;
        string current;
        backtrack(s, current, ans, 0);

        return ans;
     }
};