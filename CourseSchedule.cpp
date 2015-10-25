// 此题等价于判断有向图中是否有环, 有环的时候就无法修完全部的课程
// 提示中给出解法为DFS或者BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for(auto a: prerequisites) {
            graph[a.second].push_back(a.first);  
            ++in[a.first];  //计算每个节点的入度
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(in[i] == 0) {
                q.push(i); //将所有入度为0的节点放入队列q
            }
        }
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(auto a : graph[t]) {
                --in[a];
                if(in[a] == 0) {
                    q.push(a);
                }
            }
        }
        for(int i = 0; i < numCourses; ++i) {
            if(in[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
