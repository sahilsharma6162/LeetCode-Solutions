#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// course schedule II:

class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adjLs, vector<int>& color, vector<int>& result) {

        color[node] = 1;
        for (auto neighbour : adjLs[node]) {
            if (color[neighbour] == 0) {

                if (dfs(neighbour, adjLs, color, result))
                    return true;
            }
            else if (color[neighbour] == 1) {
                return true;
            }
        }
        color[node] = 2;
        result.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjLs(numCourses);

        for (auto &it : prerequisites) {

            int course = it[0];
            int prereq = it[1];

            adjLs[prereq].push_back(course);
        }

        vector<int> color(numCourses, 0);
        vector<int> result;
        for (int i = 0; i < numCourses; i++) {

            if (color[i] == 0) {

                if (dfs(i, adjLs, color, result))
                    return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};