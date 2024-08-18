class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;

        unordered_set<long> seen;  // Set to avoid duplicates
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        seen.insert(1);

        vector<long> primes = {2, 3, 5};

        while (n--) {
            long val = pq.top(); pq.pop();

            // When n reaches 0, the current val is the nth ugly number
            if (n == 0) return val;

            for (long prime : primes) {
                long nextVal = val * prime;
                
                // If the next value hasn't been seen, add it to the heap and set
                if (seen.find(nextVal) == seen.end()) {
                    pq.push(nextVal);
                    seen.insert(nextVal);
                }
            }
        }

        return -1;  // This line should never be reached
    }
};
