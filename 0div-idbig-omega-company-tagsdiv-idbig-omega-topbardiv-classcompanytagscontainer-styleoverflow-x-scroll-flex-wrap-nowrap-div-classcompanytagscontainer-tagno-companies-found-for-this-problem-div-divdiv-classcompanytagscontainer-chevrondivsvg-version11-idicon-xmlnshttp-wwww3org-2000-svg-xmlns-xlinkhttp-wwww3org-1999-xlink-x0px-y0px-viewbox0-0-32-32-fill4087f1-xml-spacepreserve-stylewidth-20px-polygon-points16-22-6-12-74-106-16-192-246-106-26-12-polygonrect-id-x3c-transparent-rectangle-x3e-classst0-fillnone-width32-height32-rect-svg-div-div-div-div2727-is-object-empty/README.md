<h2><a href="https://leetcode.com/problems/is-object-empty/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2727. Is Object Empty</a></h2><h3>Easy</h3><hr><div><p>Given an object or an array, return if it is empty.</p>

<ul>
	<li>An empty object contains no key-value pairs.</li>
	<li>An empty array contains no elements.</li>
</ul>

<p>You may assume the object or array is the output of&nbsp;<code>JSON.parse</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> obj = {"x": 5, "y": 42}
<strong>Output:</strong> false
<strong>Explanation:</strong> The object has 2 key-value pairs so it is not empty.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> obj = {}
<strong>Output:</strong> true
<strong>Explanation:</strong> The object doesn't have any key-value pairs so it is empty.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> obj = [null, false, 0]
<strong>Output:</strong> false
<strong>Explanation:</strong> The array has 3 elements so it is not empty.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>obj</code> is a valid JSON object or array</li>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Can you solve it in O(1) time?</strong></div>