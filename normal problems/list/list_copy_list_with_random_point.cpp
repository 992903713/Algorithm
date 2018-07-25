#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode *next;
    ListNode *random;
    ListNode(int x):data(x),next(NULL),random(NULL){}
};
//1.�������ӷ�
class Solution1{
public:
    ListNode* copyListWithRandomPoint(ListNode *head){
             if(head == NULL){
            return head;
        }
        //1.��һ������������½ڵ㵽��ǰ�ڵ�֮��
        ListNode *list = head;
        while(list != NULL){
            ListNode *copyNode = new ListNode(list->data);
            copyNode->next = list->next;
            list->next = copyNode;
            list = list->next->next;
        }
        //2.�ڶ�������������½ڵ��randomָ��
        list = head;
        while(list){
            ListNode *copyNode = list->next;
            if(list->random){
                copyNode->random = list->random->next;
            }else{
                copyNode->random = NULL;//�˲����Ǳ��룬��ʼ��ʱ��ΪNULL
            }
            list = list->next->next;
        }
        //3.�����α�������ԭԭʼ������ȡ��������
        list = head;
        ListNode *newHead = head->next;
        while(list){
            ListNode *temp = list->next;
            list->next = temp->next;
            if(temp->next){
                temp->next = temp->next->next;
            }
            list = list->next;
        }
        return newHead;
    }
};
//2.hash��
class Solution{
public:
    ListNode* copyListWithRandomPoint(ListNode *head){
        if(head == NULL){
            return head;
        }
        vector<ListNode*> node_vec;
        map<ListNode*,int> node_map;
        int index = 0;
        ListNode *ptr = head;
        while(ptr){
            node_vec.push_back(new ListNode(ptr->data));
            node_map[ptr] = index;
            index++;
            ptr = ptr->next;
        }
        node_vec.push_back(0);
        index = 0;
        ptr = head;
        while(ptr){
            node_vec[index]->next = node_vec[index+1];
            if(ptr->random){
                int id = node_map[ptr->random];
                node_vec[index]->random = node_vec[id];
            }
            ptr = ptr->next;
            index++;
        }
        return node_vec[0];
    }
};
int main(){
    return 0;
}
