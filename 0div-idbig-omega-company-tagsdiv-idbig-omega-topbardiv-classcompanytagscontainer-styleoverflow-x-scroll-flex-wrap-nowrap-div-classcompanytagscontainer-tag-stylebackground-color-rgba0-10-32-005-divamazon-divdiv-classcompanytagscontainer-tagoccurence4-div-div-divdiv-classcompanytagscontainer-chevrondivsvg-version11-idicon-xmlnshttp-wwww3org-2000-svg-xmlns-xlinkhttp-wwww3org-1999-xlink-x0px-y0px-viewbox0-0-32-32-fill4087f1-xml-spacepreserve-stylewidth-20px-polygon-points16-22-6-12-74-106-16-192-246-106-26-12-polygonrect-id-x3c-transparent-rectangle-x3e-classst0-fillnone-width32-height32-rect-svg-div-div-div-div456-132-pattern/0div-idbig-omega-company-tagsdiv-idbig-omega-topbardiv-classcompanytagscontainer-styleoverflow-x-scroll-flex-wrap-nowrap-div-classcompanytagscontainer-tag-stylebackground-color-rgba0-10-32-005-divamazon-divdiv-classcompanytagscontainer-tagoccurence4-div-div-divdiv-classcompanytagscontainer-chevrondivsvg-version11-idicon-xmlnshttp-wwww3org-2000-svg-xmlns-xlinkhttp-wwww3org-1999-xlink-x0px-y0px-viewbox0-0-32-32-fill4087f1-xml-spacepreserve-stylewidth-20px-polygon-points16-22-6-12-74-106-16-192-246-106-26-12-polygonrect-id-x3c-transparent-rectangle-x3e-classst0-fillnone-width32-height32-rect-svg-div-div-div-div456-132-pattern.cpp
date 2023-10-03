class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int c=INT_MIN;
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            int curr=nums[i];
            if(curr<c)return true;
            while(!st.empty()&&st.top()<curr){
                c=st.top();
                st.pop();
            }
            st.push(curr);
        }
        return false;
    }
};