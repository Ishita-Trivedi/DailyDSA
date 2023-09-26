class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0||divisor==0)return 0;
        bool positive=false;
        if((dividend<0&&divisor<0)||(dividend>0&&divisor>0))positive=true;
        dividend=abs(dividend);divisor=abs(divisor);
        long s=1,ans=0,end=(dividend),mid;
      
       if(divisor==1)
           ans=dividend;
       else{
        while(s<=end)
        {
             mid=(s+end)/2;
            if(mid*(divisor)==(dividend))
              {  ans=mid;break;}
            else if(mid*(divisor)>(dividend))
               end=mid-1;
            else//we take minimum of all
            {
                ans=mid;
                s=mid+1;
            }
        }
       }
       if(!positive)ans=-ans;//both negative then positive else -ve
                if(ans>INT_MAX)return INT_MAX;
        else if(ans<INT_MIN)return INT_MIN;
        return static_cast<int>(ans);
    }
};