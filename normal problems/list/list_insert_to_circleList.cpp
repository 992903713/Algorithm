#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    /*
    * Ĭ����������������inputArrayΪ���뻷���������飬nextArray[i]����inputArray[i]����һ��λ��
    */
    ListNode* insert_to_circleList(vector<int> inputArray,vector<int> nextArray,int val){
        //������������
        //�����²���Ľڵ�
        ListNode *insertNode = new ListNode(val);
        if(inputArray == NULL || inputArray.size() == 0){
            return insertNode;
        }
        ListNode *head = new ListNode(inputArray[0]);
        ListNode *temp = head;
        for(int i=0; i<inputArray.size()-1; ++i){
            ListNode *tempNode = new ListNode(inputArray[nextArray[i]]);
            temp->next = tempNode;
            temp = temp->next;
        }
        //����ǰ����ֵС��ͷ���ֵ�������ͷ���֮ǰ
        if(val < head->data){
            temp->next = insertNode;
            insertNode->next = head;
            return insertNode;
        }
        //�����м�ĳλ��
        ListNode *prev = head;
        ListNode *cur = prev->next;
        while(cur){
            if(prev->data < val && cur->data > val){
                break;
            }
            prev = prev->next;
            cur = prev->next;
        }
        prev->next = insertNode;
        insertNode->next = cur;
        return head;

    }


};
