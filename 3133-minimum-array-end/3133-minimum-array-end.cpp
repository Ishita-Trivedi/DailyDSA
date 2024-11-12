class Solution {
typedef long long ll;
public:
    long long minEnd(int n, int x) {
      ll finalnum = 0,val = n - 1,xx = 1LL * x;  // Convert x to long long
        
        // Iterate over 64 bits
        for (ll i = 0; i < 64; i++) {
            if ((xx & (1LL << i)) != 0) {
                finalnum += (1LL << i); 
            } else {
                if (val &1) {
                    finalnum += (1LL << i);  
                }
                  val=val>>1;
            }
        }
        
        return finalnum;
    }
};