/*
f(n) = f(0) * f(n-1) + f(1)*f(n-1)+...+ f(n-2)*f(1)+f(n-1)*f(0);

*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n + 1, 0);  //从 0个节点到n个节点的树
        res[0] = 1;  //0个节点有1中树
        res[1] = 1;  //1个节点有1种树
        for(int i = 2; i <= n; ++i) {  //求i个节点的树的个数
            for(int j = 0; j < i; ++j) {
                res[i] += res[j] * res[i - j - 1];
            }
        }
        return res[n];
    }
};
