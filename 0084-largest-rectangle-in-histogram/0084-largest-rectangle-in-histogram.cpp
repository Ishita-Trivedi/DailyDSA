class Solution {//brute force
public:
    vector<int> left(vector<int>& heights){
       vector<int>ans;
       stack<int>st;
       for(int i=0;i<heights.size();i++){
           while(!st.empty()&&heights[st.top()]>=heights[i])
           st.pop();
           if(st.empty())ans.push_back(-1);//extreme end is -1
           else
           ans.push_back(st.top());
           st.push(i);
       }
        return ans;
    }
    vector<int> right(vector<int>& heights){
       vector<int>ans;
       stack<int>st;
       for(int i=heights.size()-1;i>=0;i--){
           while(!st.empty()&&heights[st.top()]>=heights[i])
           st.pop();
           if(st.empty())ans.push_back(heights.size());//extreme end is size
           else
           ans.push_back(st.top());
           st.push(i);
       }
       reverse(ans.begin(),ans.end());//as values enterd from last push_back
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        vector<int>lhs=left(heights);
        vector<int>rhs=right(heights);
        for(int i=0;i<heights.size();i++){
            int width=rhs[i]-lhs[i]-1;
            int area=heights[i]*width;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};