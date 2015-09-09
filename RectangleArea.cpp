class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area_one = (C - A) * (D - B);
        int area_two = (G - E) * (H - F);
        // 没有重叠区域时
        if(A >= G || B >= H || E >= C || F >= D) {
            return area_one + area_two;
        }
        //有公共区域, 则求公共区域面积, 覆盖
        int inter_section = (min(C, G) - max(A, E))*(min(H, D) - max(F, B));
        return (area_one + area_two - inter_section);
    }
};
