class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int x;
        if(a==e||b==f){//e&q in same row or col
        //chek b in path of e&b
        if(a==e&&c==e){//same row
             x=(d-b)*(d-f);
            if(x<0)return 2;
        }
        else if(b==f&&d==f){//same col
             x=(c-a)*(c-e);
             if(x<0)return 2;
        }
            return 1;
        }
        //for bishop
        if(abs(c-e)==abs(d-f))//b&q on same diag
        {
            //if e in blw b&q
            if(abs(c-a)==abs(d-b))//b&e on same diag
            if((b-f)*(b-d)<0)//e in between b&q
            return 2;
            return 1;//as b&q on same diagonal
        }
        return 2;//e can in any case
    }
};