<h2><a href="https://leetcode.com/problems/find-k-closest-elements/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Facebook</div><div class="companyTagsContainer--tagOccurence">21</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Google</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>tiktok</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Uber</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Bloomberg</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Oracle</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>658. Find K Closest Elements</a></h2><h3>Medium</h3><hr><div><p>Given a <strong>sorted</strong> integer array <code>arr</code>, two integers <code>k</code> and <code>x</code>, return the <code>k</code> closest integers to <code>x</code> in the array. The result should also be sorted in ascending order.</p>

<p>An integer <code>a</code> is closer to <code>x</code> than an integer <code>b</code> if:</p>

<ul>
	<li><code>|a - x| &lt; |b - x|</code>, or</li>
	<li><code>|a - x| == |b - x|</code> and <code>a &lt; b</code></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [1,2,3,4,5], k = 4, x = 3
<strong>Output:</strong> [1,2,3,4]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [1,2,3,4,5], k = 4, x = -1
<strong>Output:</strong> [1,2,3,4]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>arr</code> is sorted in <strong>ascending</strong> order.</li>
	<li><code>-10<sup>4</sup> &lt;= arr[i], x &lt;= 10<sup>4</sup></code></li>
</ul>
</div>