<h2><a href="https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3097. Shortest Subarray With OR at Least K II</a></h2><h3>Medium</h3><hr><div><p>You are given an array <code>nums</code> of <strong>non-negative</strong> integers and an integer <code>k</code>.</p>

<p>An array is called <strong>special</strong> if the bitwise <code>OR</code> of all of its elements is <strong>at least</strong> <code>k</code>.</p>

<p>Return <em>the length of the <strong>shortest</strong> <strong>special</strong> <strong>non-empty</strong> <span data-keyword="subarray-nonempty">subarray</span> of</em> <code>nums</code>, <em>or return</em> <code>-1</code> <em>if no special subarray exists</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The subarray <code>[3]</code> has <code>OR</code> value of <code>3</code>. Hence, we return <code>1</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,1,8], k = 10</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The subarray <code>[2,1,8]</code> has <code>OR</code> value of <code>11</code>. Hence, we return <code>3</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2], k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The subarray <code>[1]</code> has <code>OR</code> value of <code>1</code>. Hence, we return <code>1</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>
</div>