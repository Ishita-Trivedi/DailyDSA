<h2><a href="https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3029. Minimum Time to Revert Word to Initial State I</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> string <code>word</code> and an integer <code>k</code>.</p>

<p>At every second, you must perform the following operations:</p>

<ul>
	<li>Remove the first <code>k</code> characters of <code>word</code>.</li>
	<li>Add any <code>k</code> characters to the end of <code>word</code>.</li>
</ul>

<p><strong>Note</strong> that you do not necessarily need to add the same characters that you removed. However, you must perform <strong>both</strong> operations at every second.</p>

<p>Return <em>the <strong>minimum</strong> time greater than zero required for</em> <code>word</code> <em>to revert to its <strong>initial</strong> state</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> word = "abacaba", k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> At the 1st second, we remove characters "aba" from the prefix of word, and add characters "bac" to the end of word. Thus, word becomes equal to "cababac".
At the 2nd second, we remove characters "cab" from the prefix of word, and add "aba" to the end of word. Thus, word becomes equal to "abacaba" and reverts to its initial state.
It can be shown that 2 seconds is the minimum time greater than zero required for word to revert to its initial state.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> word = "abacaba", k = 4
<strong>Output:</strong> 1
<strong>Explanation:</strong> At the 1st second, we remove characters "abac" from the prefix of word, and add characters "caba" to the end of word. Thus, word becomes equal to "abacaba" and reverts to its initial state.
It can be shown that 1 second is the minimum time greater than zero required for word to revert to its initial state.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> word = "abcbabcd", k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> At every second, we will remove the first 2 characters of word, and add the same characters to the end of word.
After 4 seconds, word becomes equal to "abcbabcd" and reverts to its initial state.
It can be shown that 4 seconds is the minimum time greater than zero required for word to revert to its initial state.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 50 </code></li>
	<li><code>1 &lt;= k &lt;= word.length</code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
</ul>
</div>