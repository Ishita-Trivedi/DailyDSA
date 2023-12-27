can use:
int e = *max_element(arr.begin(), arr.end());
​
==========================
k is bananas per hour, h is number of hours
For example 1: Given piles = [3,6,7,11], h = 8hrs, if k = 4 ban/hr
Since 3 is less than k, only (1hr) is added. The 0th pile took 1 hr;
Since 6 is greater than k, Koko can eat k from 6, leaving 6 - k = 2 bananas left and adding (1hr), since 2 is less than 4, add (1hr). The 1st pile took 2 hours.
Since 7 > k, 7 - k = 3, add (1hr), 3 < k, add (1hr). The 2nd pile took 2 hours.
Since 11 > k, 11 - k = 7, add (1hr), 7 - k = 3, add (1hr), 3 < k, add (1hr). The 3rd pile took 3 hours.
​
For a total of 1 + 2 + 2 + 3 = 8 hours == h
There's a faster way of doing the above that doesn't involve subtraction.
​
For example 2: Given piles = [30,11,23,4,20], h = 5, if k = 30 ban/hr.
Hours Spent = [1, 1, 1, 1, 1]
1 + 1 + 1 + 1 + 1 = 5 hours == h
​
For example 3: Given piles = [30,11,23,4,20], h = 6, if k = 23 ban/hr.
Hours Spent = [2,1,1,1,1]
For a total of 6 hours == h.