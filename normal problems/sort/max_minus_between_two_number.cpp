/*
 *  �������������Ԫ�ص�����ֵ
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int max_minus(vector<int> &nums){
        //1.������������Сֵ
        int n = nums.size();
        int _max = nums[0];
        int _min = nums[0];
        for(int i=1; i<n; ++i){
            _max = max(_max,nums[i]);
            _min = min(_min,nums[i]);
        }
        //2.����n+1��Ͱ
        bool hasNum[n+1] = {false};
        int maxNum[n+1] = {-0x7fffffff};
        int minNum[n+1] = {0x7fffffff};
        float gap = (_max - _min) * 1.0f / n;
        //��ÿһ��Ԫ�ط���������Ͱ������Ͱ�������Сֵ
        for(int i=0; i<n; ++i){
            //Ԫ������Ͱ���
            int bucketNumber = (int)(nums[i] - _min ) / gap;
            if(hasNum[bucketNumber]){
                maxNum[bucketNumber] = max(nums[i],maxNum[bucketNumber]);
                minNum[bucketNumber] = min(nums[i],minNum[bucketNumber]);
            }else{
                maxNum[bucketNumber] = nums[i];
                minNum[bucketNumber] = nums[i];
                hasNum[bucketNumber] = true;
            }
        }
        int ans = 0;
        int lastMax = 0;
        //�ҵ���һ����Ԫ�ص�Ͱ
        int i=0;
        while(i <= n){
            if(hasNum[i++]){
                lastMax = maxNum[i-1];
                break;
            }
        }
        while(i <= n){
            if(hasNum[i]){
                ans = max(ans,minNum[i] - lastMax);
                lastMax = maxNum[i];
            }
            i++;
        }
        return ans;
    }


};

int main(){
    int arr[] = {4,7,0,1,9,10};
    vector<int> nums(arr,arr+6);
    Solution s;
    printf("%d\n",s.max_minus(nums));
    return 0;
}
