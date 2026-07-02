#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
#include<string>
using namespace std;

class Solution{
    public:
      bool isValid(string& segment) {
    if (segment.length() == 0 || segment.length() > 3)
        return false;
    if (segment.length() > 1 && segment[0] == '0')
        return false;
    if (stoi(segment) > 255)
        return false;
    return true;
}

       void backtrack(string& s, vector<string>& final, vector<string>& segment, int position){
        if(segment.size()==4 && position==s.length()){
            string ip = segment[0] + "." + segment[1] + "." + segment[2] + "." + segment[3];
              final.push_back(ip);
              return;
        }
       int remaining_chars = s.length() - position;
    int remaining_segments = 4 - segment.size();
              if(remaining_chars<remaining_segments)
              return;
              if(remaining_chars>remaining_segments*3){
              return;
              }

    for(int i=1;i<4;i++){
        string current= s.substr(position,i);
         if(isValid(current)){
         segment.push_back(current);
          backtrack(s, final, segment,position+i);
            segment.pop_back();
     }
   }
 }
       vector<string> restoreIpAddresses(string s) {
    vector<string> final;
    vector<string> segment;
    backtrack(s, final, segment, 0);
    return final;
}
};