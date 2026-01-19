
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //这个问题是图的拓扑排序，要先建立图。
        //graph[i]存放修完i之后可以修哪些课
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& edge : prerequisites) {
            int course = edge[0];//0是当前课程
            int prereq = edge[1];//1是当前课程的前置课程

            graph[prereq].push_back(course);
            indegree[course]++;//indegree记录当前课程的前置课程数量
        }

        queue<int> q;
        for(int i=0; i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        //BFS
        int count=0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;

            for(int nextCourse : graph[curr]) {
                indegree[nextCourse]--;
                if(indegree[nextCourse]==0) {
                    q.push(nextCourse);
                }
            }
        }

        return count == numCourses;
        
    }
};