class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int res = 0;
        int ml = 0, mr = 0;
        while(l<=r) {
            if(height[l]<=height[r]) {
                if(height[l]>=ml) ml = height[l];
                else res += ml - height[l];
                l++;
            }
            else {
                if(height[r]>=mr) mr = height[r];
                else res += mr - height[r];
                r--;
            }
        }
        return res;
    }
};
