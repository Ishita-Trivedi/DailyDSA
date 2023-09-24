class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        //here we maintain the smallest till date and its till date sum 
        int n=maxHeights.size();
        stack<int>st,st2;
        vector<long long>lhs(n,0),rhs(n,0);
        long long ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&maxHeights[i]<maxHeights[st.top()])
            st.pop();
            if(i==0)
            lhs[i]=maxHeights[i];
            else if(st.empty())
            lhs[i]=1LL*maxHeights[i]*(i+1);
            else
            lhs[i]=1LL*maxHeights[i]*(i-st.top())+lhs[st.top()];
            st.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st2.empty()&&maxHeights[i]<maxHeights[st2.top()])
            st2.pop();
            if(i==n-1)
            rhs[i]=maxHeights[i];
            else if(st2.empty())
            rhs[i]=1LL*maxHeights[i]*(n-i);
            else
            rhs[i]=1LL*maxHeights[i]*(st2.top()-i)+rhs[st2.top()];
            st2.push(i);
        }
        for(int i=0;i<n;i++){
            long long value  = lhs[i] + rhs[i] - maxHeights[i];
            ans=max(ans,value);
        }
        return ans;
    }
};