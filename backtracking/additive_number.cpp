#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
#include<string>
using namespace std;

class Solution{
    public:

bool backtrack(string& num, int position, string first, string second){
            if(position==num.length()){
                return true;
            }
           int next= stoi(first)+stoi(second);
            string nextStr = to_string(next);

            if(num.substr(position,nextStr.length())== nextStr){
                return backtrack(num, position + nextStr.length(), first, nextStr);

            }
            else return false;

}           

      bool isAdditive(string num){
        int n=num.length();
       string first;
       string second;
        for(int i=1;i<n;i++){
            for(int j=1; i+j<n;j++){

                if(i+j>=n){
                    continue;
                }
                first = num.substr(0, i);
            second = num.substr(i, j);

                if (first[0] == '0' || second[0]=='0')
             continue;
           if (backtrack(num,i+j,first,second)){
       return true;
           }
            }
        }
        return false;

      }
};