class Solution1 {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int left = 0;
        int right = citations.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(citations[mid] == len - mid) return len-mid;
            else if(citations[mid] > len - mid) right = mid-1;
            else left = mid + 1;
        }
        return len - left;
    }
};
class Solution2 {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int right = citations.size()-1;
        int len = citations.size();
        int h = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(citations[mid] >= len - mid){
                h = len - mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return h;
    }
};
