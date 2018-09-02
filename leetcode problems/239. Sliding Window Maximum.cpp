class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            while(!Q.empty() && nums[Q.back()] <= nums[i]){
                Q.pop_back();
            }
            Q.push_back(i);
            //��ͷ����
            if(Q.front() + k == i){
                Q.pop_front();
            }
            //��k-1λ�ÿ�ʼ�����������ֵ
            if(i >= k - 1){
                res.push_back(nums[Q.front()]);
            }
        }
        return res;
    }
};
