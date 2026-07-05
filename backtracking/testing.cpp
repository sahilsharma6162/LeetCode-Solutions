#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
#include<string>
using namespace std;
class Solution{
    public:
bool backtrack(string& num, int index, vector<int>& ans) {

    if (index == num.size()) {
        return ans.size() >= 3;
    }

    long long curr = 0;

    for (int i = index; i < num.size(); i++) {

        if (i > index && num[index] == '0')
            break;

        curr = curr * 10 + (num[i] - '0');

        if (curr > INT_MAX)
            break;

        if (ans.size() >= 2) {

            long long sum = (long long)ans[ans.size() - 1] + ans[ans.size() - 2];

            if (curr < sum)
                continue;

            if (curr > sum)
                break;
        }

        ans.push_back((int)curr);

        if (backtrack(num, i + 1, ans))
            return true;

        ans.pop_back();
    }

    return false;
}
};