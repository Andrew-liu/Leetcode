// 必须要gas[i] >= cost[i] 汽油车才能继续走下
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, start = 0, total = 0; //记录总的剩余汽油亮
        for(int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i]; //total缓存路线上总的剩余油量
            if(sum < 0) {  //说明之前路径到现在已经不能继续往下走了(没法开到终点了)
                start = i + 1;  //前面的任何一段路径, 加起来的汽油都不够, 所有需要选择下一个节点为新起点
                sum = 0;  //剩余的gas变为0
            }
        }
        return total < 0 ? -1 : start;
    }
};
