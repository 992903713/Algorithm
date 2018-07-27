#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    ListNode* reverse_per_k_number1(ListNode *head,int k){
        stack<ListNode*> node_stack;
        if(head == NULL ||head->next == NULL||k < 2){
            return head;
        }
        ListNode *resHead = NULL;//��ת�������ͷ���
        ListNode *header = NULL;//��ǰת����ͷ���
        ListNode *tail = NULL;//��ǰת����β�ڵ�
        ListNode *lastTail = NULL;//�ϴ�ת����β�ڵ�
        while(head){
            ListNode *nextNode = head->next;
            head->next = NULL;
            node_stack.push(head);
            if(node_stack.size() == k){

                header = tail = node_stack.top();
                node_stack.pop();
                while(node_stack.empty() == false){
                    tail->next = node_stack.top();
                    node_stack.pop();
                    tail = tail->next;
                }
                if(resHead == NULL){
                    resHead = header;
                    lastTail = tail;
                }else{
                    lastTail->next = header;
                    lastTail = tail;
                }
            }
            head = nextNode;
        }
        if(node_stack.empty() == false){
            //ͷ�巨����
            header = node_stack.top();
            header->next = NULL;
            node_stack.pop();
            while(node_stack.empty() == false){
                ListNode *temp = node_stack.top();
                node_stack.pop();
                temp->next = header;
                header = temp;
            }
            lastTail->next = header;
        }
        return resHead;

    }
    ListNode* reverse_per_k_number2(ListNode *head,int k){
        if(!head || !head->next || k < 2){
            return head;
        }
        ListNode *next = NULL;
        ListNode *resHead = NULL;//��ת��������ͷ���
        ListNode *header = NULL, *tail = NULL;//��¼ÿ�ν�ȡk��Ԫ�ع����е�ͷ����β���
        ListNode *lastTail = NULL;//��һ�η�ת�����е�β���
        bool flag = true;
        while(flag){
            header = NULL;
            tail = NULL;
            //ÿ���ó�k��Ԫ��
            for(int i = 0; i < k; i++){
                if(head == NULL){//��ʾ���һ�鲻����k��Ԫ��
                    flag = false;
                    break;
                }else{
                    next = head->next;
                    head->next = NULL;
                    if(i == 0){
                        header = head;
                        tail = head;
                    }else{
                        tail->next = head;
                        tail = head;
                    }
                    head = next;
                }
            }
            if(flag){//��ת��k��Ԫ��
                ListNode *tempListHeader = header;
                ListNode *temp = tempListHeader;
                tempListHeader = tempListHeader->next;
                temp->next = NULL;//ժȡ����
                while(tempListHeader != NULL){
                    next = tempListHeader->next;
                    tempListHeader->next = temp;
                    temp = tempListHeader;
                    tempListHeader = next;
                }
                if(resHead == NULL){
                    resHead = tail;
                    lastTail = header;
                }else{
                    lastTail->next = tail;
                    lastTail = header;
                }
            }else{//���һ�鲻����k��Ԫ��,ֱ�ӷŵ���ת����������
                lastTail->next = header;
            }
        }
        return resHead;
    }

};

int main(){
    return 0;
}
