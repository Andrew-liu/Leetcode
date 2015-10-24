/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

//广度优先遍历的思想
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> ht;
        queue<UndirectedGraphNode*> q;        
        q.push(node);
        ht[node] = p2;
        while(!q.empty()) {
            p1 = q.front();
            p2 = ht[p1];
            q.pop();
            for(int i=0; i<p1->neighbors.size(); i++) {  //遍历节点所有邻节点
                UndirectedGraphNode *nb = p1->neighbors[i];
                if(ht.count(nb)) {
                    p2->neighbors.push_back(ht[nb]);
                }
                else { 
                    UndirectedGraphNode *temp = new UndirectedGraphNode(nb->label);
                    p2->neighbors.push_back(temp);
                    ht[nb] = temp;
                    q.push(nb);
                }
            }
        }
        return ht[node];
    }
};
