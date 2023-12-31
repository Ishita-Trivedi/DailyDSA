<h2><a href="https://leetcode.com/problems/random-flip-matrix/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>519. Random Flip Matrix</a></h2><h3>Medium</h3><hr><div><p>There is an <code>m x n</code> binary grid <code>matrix</code> with all the values set <code>0</code> initially. Design an algorithm to randomly pick an index <code>(i, j)</code> where <code>matrix[i][j] == 0</code> and flips it to <code>1</code>. All the indices <code>(i, j)</code> where <code>matrix[i][j] == 0</code> should be equally likely to be returned.</p>

<p>Optimize your algorithm to minimize the number of calls made to the <strong>built-in</strong> random function of your language and optimize the time and space complexity.</p>

<p>Implement the <code>Solution</code> class:</p>

<ul>
	<li><code>Solution(int m, int n)</code> Initializes the object with the size of the binary matrix <code>m</code> and <code>n</code>.</li>
	<li><code>int[] flip()</code> Returns a random index <code>[i, j]</code> of the matrix where <code>matrix[i][j] == 0</code> and flips it to <code>1</code>.</li>
	<li><code>void reset()</code> Resets all the values of the matrix to be <code>0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["Solution", "flip", "flip", "flip", "reset", "flip"]
[[3, 1], [], [], [], [], []]
<strong>Output</strong>
[null, [1, 0], [2, 0], [0, 0], null, [2, 0]]

<strong>Explanation</strong>
Solution solution = new Solution(3, 1);
solution.flip();  // return [1, 0], [0,0], [1,0], and [2,0] should be equally likely to be returned.
solution.flip();  // return [2, 0], Since [1,0] was returned, [2,0] and [0,0]
solution.flip();  // return [0, 0], Based on the previously returned indices, only [0,0] can be returned.
solution.reset(); // All the values are reset to 0 and can be returned.
solution.flip();  // return [2, 0], [0,0], [1,0], and [2,0] should be equally likely to be returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li>There will be at least one free cell for each call to <code>flip</code>.</li>
	<li>At most <code>1000</code> calls will be made to <code>flip</code> and <code>reset</code>.</li>
</ul>
</div>