class Solution {
public:
    bool check(int num) {
        int64_t inv=0,total=0;//invalid are 0,1,8
        while (num) {
            int d = num % 10;
           if(d==3||d==4||d==7)return false;
           if(d==0||d==1||d==8)inv++;
           total++;
            num /= 10;
        }
        return (inv==total)?false:true;
        //false if made of only 0,1,8
    }

    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if(check(i))count++;
        }
        return count;
    }
};
