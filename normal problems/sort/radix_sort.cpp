/*
 *  ��������
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void radix_sort(vector<int> &nums){
        if(nums.empty() || nums.size() < 2){
            return;
        }
        int bits = _get_bits(nums);
        _radix_sort(nums,bits);
    }
private:
    void _radix_sort(vector<int> &nums,int bits){
        vector<int> count(10,0);
        //���û���������ǰλ������ʼΪ��λ
        int radix = 1;
        for(int i=1; i<=bits; ++i){
            count.assign(10,0);
            for(int j=0; j<nums.size(); ++j){
                int indexNumber = (nums[j] / radix) % 10;
                count[indexNumber]++;
            }
            for(int j=1; j<10; ++j){
                count[j] = count[j] + count[j-1];
            }
            vector<int> tempArr(nums.size(),0);
            for(int j=nums.size()-1; j>=0; --j){
                int indexNumber = (nums[j] / radix) % 10;
                //�����ǰ������λ��
                int serialNumber = count[indexNumber] - 1;
                count[indexNumber]--;
                //��tempArr�а���λ�����ŵ�ǰԪ��
                tempArr[serialNumber] = nums[j];
            }
            //��nums����ΪtempArr
            for(int j=0; j<tempArr.size(); ++j){
                nums[j] = tempArr[j];
            }
            radix *= 10;
        }

    }
    int _get_bits(vector<int> &nums){
        //�����������Ԫ�ص�λ��
        int big = -0x7fffffff;
        for(int i=0; i<nums.size(); ++i){
            big = max(big,nums[i]);
        }
        int bits = 0;
        while(big){
            big/=10;
            bits++;
        }
        return bits;
    }

};
int main()
{
    int arr[] = {3,65,34,1,6,4,73};
    vector<int> nums(arr,arr+7);
    Solution s;
    s.radix_sort(nums);
    for(int i=0; i<nums.size(); ++i){
        printf("%d\n",nums[i]);
    }
    return 0;
}
