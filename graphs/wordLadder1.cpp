#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;

// Put all dictionary words into an unordered_set.
// Create a queue storing (word, level).
// Push (beginWord, 1).
// Remove beginWord from the set if it exists.
// While the queue is not empty:
// Pop the front word and its level.
// If it equals endWord, return the level.
// For each character position:
// Save the original character.
// Replace it with 'a' to 'z'.
// If the new word exists in the set:
// Push it with level + 1.
// Remove it from the set.
// Restore the original character.
// If endWord is never reached, return 0.

class Solution{
  public:
 int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> st;
         for(int i=0;i<wordList.size();i++){
             st.insert(wordList[i]);
         }
         st.erase(beginWord);
         queue<pair<string,int>> q;
         q.push({beginWord,1});
         

         while(!q.empty()){
          pair<string,int> p= q.front();
           q.pop();
           string frontword=p.first;
           int level=p.second;
            if(frontword==endWord){
                return level;
            }
             for(int i=0;i<frontword.size();i++){
              char original=frontword[i];
                for (char chi = 'a'; chi <= 'z'; chi++) {
                      frontword[i] = chi;
                   if (st.find(frontword) != st.end()){
                    q.push({frontword,level+1});
                    st.erase(frontword);
                   }
               }
               frontword[i]=original;
          }
       }
       return 0;
    }

};