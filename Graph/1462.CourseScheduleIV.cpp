#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
    }
};

int main()
{
    //edge as adjMatrix
    vector<vector<int>> prerequisites = { 
        {1,0}
    };

    vector<vector<int>> queries = { 
        {1,0}
    };
    int numCourses = 4, k = 2;
    
    Solution sl;
    cout << sl.checkIfPrerequisite(numCourses, prerequisites, queries);
}