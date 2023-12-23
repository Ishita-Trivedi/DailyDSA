<h2><a href="https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2968. Apply Operations to Maximize Frequency Score</a></h2><h3>Hard</h3><hr><div><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>You can perform the following operation on the array <strong>at most</strong> <code>k</code> times:</p>

<ul>
	<li>Choose any index <code>i</code> from the array and <strong>increase</strong> or <strong>decrease</strong> <code>nums[i]</code> by <code>1</code>.</li>
</ul>

<p>The score of the final array is the <strong>frequency</strong> of the most frequent element in the array.</p>

<p>Return <em>the <strong>maximum</strong> score you can achieve</em>.</p>

<p>The frequency of an element is the number of occurences of that element in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,6,4], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can do the following operations on the array:
- Choose i = 0, and increase the value of nums[0] by 1. The resulting array is [2,2,6,4].
- Choose i = 3, and decrease the value of nums[3] by 1. The resulting array is [2,2,6,3].
- Choose i = 3, and decrease the value of nums[3] by 1. The resulting array is [2,2,6,2].
The element 2 is the most frequent in the final array so our score is 3.
It can be shown that we cannot achieve a better score.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,4,2,4], k = 0
<strong>Output:</strong> 3
<strong>Explanation:</strong> We cannot apply any operations so our score will be the frequency of the most frequent element in the original array, which is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>14</sup></code></li>
</ul>
</div>