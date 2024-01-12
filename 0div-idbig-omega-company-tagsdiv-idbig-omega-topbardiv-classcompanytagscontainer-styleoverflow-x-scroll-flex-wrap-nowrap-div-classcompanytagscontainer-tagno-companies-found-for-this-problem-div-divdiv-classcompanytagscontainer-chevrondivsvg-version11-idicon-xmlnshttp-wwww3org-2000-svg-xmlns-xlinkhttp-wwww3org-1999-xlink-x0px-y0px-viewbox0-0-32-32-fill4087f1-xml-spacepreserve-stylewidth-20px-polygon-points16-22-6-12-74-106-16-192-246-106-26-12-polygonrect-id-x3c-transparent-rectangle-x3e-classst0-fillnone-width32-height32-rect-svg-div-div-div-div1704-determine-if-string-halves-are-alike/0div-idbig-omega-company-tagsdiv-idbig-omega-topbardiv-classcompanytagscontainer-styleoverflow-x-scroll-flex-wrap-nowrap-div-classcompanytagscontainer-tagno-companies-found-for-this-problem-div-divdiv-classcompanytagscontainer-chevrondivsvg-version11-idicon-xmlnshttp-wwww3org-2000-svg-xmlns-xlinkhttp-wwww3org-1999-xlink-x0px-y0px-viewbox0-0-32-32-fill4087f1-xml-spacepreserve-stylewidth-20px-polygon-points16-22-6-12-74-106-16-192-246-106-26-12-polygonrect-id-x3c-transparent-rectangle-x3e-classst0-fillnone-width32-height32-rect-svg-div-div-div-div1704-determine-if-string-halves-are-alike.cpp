class Solution {
private:
    int count(string s) {
        int c = 0;
        for (char ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')  // Correct the condition
                c++;
        }
        return c;
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        // Convert the string to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // Correct the typo in the substr function call
        return count(s.substr(0, n / 2)) == count(s.substr(n / 2, n / 2));
    }
};
