/*
 *  ������������ֵ
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> move_window(vector<int> &arr,int w){
        if(arr.size() == 0 || w < 1 || arr.size() < w){
            return {};
        }
        //�����ݼ�˫�˶��У�ͷԪ����󣬴�Ŷ�Ӧ�����±�
        deque<int> qmax;
        vector<int> res;
        for(int i=0; i<arr.size(); ++i){
            int val = arr[i];
            if(qmax.empty()){
                qmax.push_back(i);
            }else if(arr[qmax.back()] > val){
                qmax.push_back(i);
            }else if(arr[qmax.back()] <= val){
                while(qmax.empty() == false && arr[qmax.back()] <= val){
                    qmax.pop_back();
                }
                qmax.push_back(i);
            }
            if(qmax.front() == i - w){
                qmax.pop_front();
            }
            if(i >= w-1){
                res.push_back(arr[qmax.front()]);
            }
        }
        return res;
    }

};
int main(){
    //int num[8] = {4,3,5,4,3,3,6,7};
    int num[100] = {8,7,12,5,16,9,17,2,4,6};

    vector<int> arr(num,num+10);
    Solution s;
    vector<int> res = s.move_window(arr,3);
    for(int i=0; i<res.size(); ++i){
        printf("%d\n",res[i]);
    }
    return 0;
}
