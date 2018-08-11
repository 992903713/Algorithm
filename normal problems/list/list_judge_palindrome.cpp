/*
 *  �жϻ��ĵ�����
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode *next;
    int data;
};

class Solution{
public:
    bool isPalindrome1(ListNode *head){
        //����1������ջ�����α���
        if(head == NULL){
            return false;
        }
        stack<ListNode *> support;
        ListNode* temp = head;
        while(temp){
            support.push(temp);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            ListNode *stackElement = support.top();
            if(temp->data != stackElement->data){
                return false;
            }
            support.pop();
            temp = temp->next;
        }
        return true;
    }
    bool isPalindrome2(ListNode *head){
        //����2������ջ��һ�α���
        if(head == NULL){
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        stack<ListNode*> support;
        int nodeCount = 0;
        //�����õ�ǰһ������
        while(fast){
            if(fast->next == NULL){//�ڵ���Ϊ����
                slow = slow->next;
                break;
            }
            support.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        //��һ����ǰһ�����ݶԱ�
        while(slow){
            ListNode *temp = support.top();
            if(slow->data != temp->data){
                return false;
            }
            support.pop();
            slow = slow->next;
        }
        return true;
    }
    bool isPalindrome3(ListNode *pHead){
        //����3.������ջ����ת��벿������
        if(pHead == NULL){
            return false;
        }
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        ListNode *lastHead = NULL;
        while(fast->next != NULL && fast->next->next != NULL){//Ѱ�ҵ���ָ��ָ����е�
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next != NULL){//��ʾ����ڵ�����Ϊż��
            lastHead = slow->next;
        }else{
            lastHead = slow;
        }
        ListNode *head = lastHead;//ָ��ת���ͷ���
        lastHead = lastHead->next;
        ListNode *next = NULL;
        head->next = NULL;
        while(lastHead){//��ת����
            next = lastHead->next;
            lastHead->next = head;
            head = lastHead;
            lastHead = next;
        }
        bool res = true;
        ListNode *tempList = head;
        while(tempList != NULL && pHead != NULL){
            if(tempList->data != pHead->data){
                res = false;
                break;
            }
            tempList = tempList->next;
            pHead = pHead->next;
        }
        //�ٰѺ��淴ת������ת����
        ListNode *head2 = head;
        head = head->next;
        head2->next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = head2;
            head2 = head;
            head = next;
        }
        slow->next = head2;
        return res;

    }

};
int main(){
    return 0;
}
