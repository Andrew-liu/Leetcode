#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//使用三指针法,

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        } //保证至少有两个有效节点
        ListNode* vhead = new ListNode(0); //构造一个虚拟的头结点
        cout <<"x" << flush;
        vhead->next = head;
        ListNode* pre = vhead;
        ListNode* cur = head;
        ListNode* end = head->next;
        cout << "x" << endl;
        while(cur!= NULL && cur->next != NULL) {  //保证至少已两个节点的循环判断
            cur->next = end->next;
            pre->next = end;
            end->next = cur; //节点完成交换
            cout << "e" << endl;
            if(cur->next == NULL) {
                break; //交换节点后, 如果只有一个节点则退出.
            }
            if(cur->next->next == NULL) {
                break;
            }
            cout << "cur" << endl;
            //指针后移
            pre = cur;
            cur = cur->next;
            end = cur->next;
        }
        head = vhead->next; //别忘了记录head的更改
        vhead->next = NULL;
        delete vhead;
        return head;
    }
};

int main(int argc, char** argv) {
    ListNode first(1);
    ListNode second(2);
    first.next = &second;
    Solution s;
    ListNode* head = s.swapPairs(&first);
    cout << head->val << endl;
}
