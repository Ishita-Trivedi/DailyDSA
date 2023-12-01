class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int>ans;
       int c1=0,c2=0,ele1=INT_MIN,ele2=INT_MIN,n=nums.size();
       for(int x:nums){
           if(c1==0&&ele2!=x){
               c1=1;ele1=x;
           }
           else if(c2==0&&ele1!=x){
               c2=1;ele2=x;
           }
           else if(ele1==x)c1++;
           else if(ele2==x)c2++;
           else{
               c1--;c2--;
           }
       } 
       c1=0;c2=0;
       for(int x:nums){
           if(x==ele1)c1++;
           else if(x==ele2)c2++;
       }
       int mini=(int)(n/3)+1;
       if(c1>=mini)ans.push_back(ele1);
       if(c2>=mini)ans.push_back(ele2);
       return ans;
    }
};