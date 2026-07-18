#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        vector<vector<string>> ans;
        vector<string> currPath;
        currPath.push_back(beginWord);
         for(int i=0;i<wordList.size();i++){
             st.insert(wordList[i]);
         }
         st.erase(beginWord);
        queue<vector<string>> q;      
          q.push({beginWord,1});
         
         while(!q.empty()){
          vector<string> currPath= q.front();
           q.pop();

           string frontword=currPath.first;

            if(frontword==endWord){
                ans.push_back(currPath);
            }
             for(int i=0;i<frontword.size();i++){
              char original=frontword[i];
                for (char chi = 'a'; chi <= 'z'; chi++) {
                      frontword[i] = chi;
                   if (st.find(frontword) != st.end()){
                    q.push({frontword,level+1});
                    ans.push_back(frontword);
                   }
               }
               frontword[i]=original;
          }
       }
       return ans;
    }
};