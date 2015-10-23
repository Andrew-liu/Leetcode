/**
 * Definition for singly-linked list.
*/
/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        if(head == NULL || head->next == NULL) {
            return head;
        }
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* end = cur->next;
        while(end->next != NULL) {
            while(cur->val != end->val && end != NULL) {  //找到两个节点的值相等则停止
                pre = cur;
                cur = end;
                end = end->next;
                if(end->next == NULL) {
                    break;
                }
            }

            if(cur->val == end->val) {
                cout << "ok" << endl;
                while(cur->val == end->val && end->next != NULL) {  //找到第一个与重复的节点
                    end = end->next;
                } 
                cout << "pre "  << pre->val << endl;
                pre->next = end;  //去掉所有重复的节点
                cur = end; //重新复制cur和end
                if(end == NULL) {
                    break;
                }
                end = end->next;
            }
        }
        //head = dummy->next;
        //delete dummy; //释放内存
        return dummy->next;
    }
};

int main(int argc, const char *argv[])
{
    ListNode first(1);
    ListNode second(2);
    ListNode third(2);
    //ListNode fout(2);
    //ListNode five(3);
    first.next = &second;
    second.next = &third;
    //third.next = &fout;
    //fout.next = &five;
    Solution s;
    s.deleteDuplicates(&first);
    return 0;
}
