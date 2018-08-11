/*
 * ˼·����j��i������¼�������ڼ�¼��ǰ��������Ԫ�ط�Χ����j����ָ��Ԫ�ز��ڼ����У�������뼯�ϣ���������󳤶ȣ��Ҳ�+1�����򻬶��������+1��
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> char_set;
        int ans = 0;
        int i=0;
        int j=0;
        while(i < s.size() && j < s.size()){
            if(char_set.find(s[j]) == char_set.end()){
                char_set.insert(s[j]);
                ans = max(ans,j-i+1);
                j++;
            }else{
                char_set.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
