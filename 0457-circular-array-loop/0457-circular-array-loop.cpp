class Solution {
public:
    int cal(int curr, int steps, int s) {
        int ans;
        ans = (curr + steps) % s;
        if (ans < 0) {
            ans += s;
        }
        return ans;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int s = nums.size();
        for (int i = 0; i < s; i++) {
            if (nums[i] == 0) {
                continue; // Skip elements with value 0
            }

            int slow = i;
            int fast = cal(i, nums[i], s);

            // Check loop direction
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[cal(fast, nums[fast], s)] > 0) {
                if (slow == fast) {
                    if (slow != cal(slow, nums[slow], s)) {
                        return true;
                    } else {
                        break;
                    }
                }
                slow = cal(slow, nums[slow], s);
                fast = cal(fast, nums[fast], s);
                fast = cal(fast, nums[fast], s); // Move fast pointer twice
            }

            // Mark the loop elements as visited (set value to 0)
            int curr = i;
            while (nums[curr] * nums[cal(curr, nums[curr], s)] > 0) {
                int temp = cal(curr, nums[curr], s);
                nums[curr] = 0;
                curr = temp;
            }
        }

        return false;
    }
};
