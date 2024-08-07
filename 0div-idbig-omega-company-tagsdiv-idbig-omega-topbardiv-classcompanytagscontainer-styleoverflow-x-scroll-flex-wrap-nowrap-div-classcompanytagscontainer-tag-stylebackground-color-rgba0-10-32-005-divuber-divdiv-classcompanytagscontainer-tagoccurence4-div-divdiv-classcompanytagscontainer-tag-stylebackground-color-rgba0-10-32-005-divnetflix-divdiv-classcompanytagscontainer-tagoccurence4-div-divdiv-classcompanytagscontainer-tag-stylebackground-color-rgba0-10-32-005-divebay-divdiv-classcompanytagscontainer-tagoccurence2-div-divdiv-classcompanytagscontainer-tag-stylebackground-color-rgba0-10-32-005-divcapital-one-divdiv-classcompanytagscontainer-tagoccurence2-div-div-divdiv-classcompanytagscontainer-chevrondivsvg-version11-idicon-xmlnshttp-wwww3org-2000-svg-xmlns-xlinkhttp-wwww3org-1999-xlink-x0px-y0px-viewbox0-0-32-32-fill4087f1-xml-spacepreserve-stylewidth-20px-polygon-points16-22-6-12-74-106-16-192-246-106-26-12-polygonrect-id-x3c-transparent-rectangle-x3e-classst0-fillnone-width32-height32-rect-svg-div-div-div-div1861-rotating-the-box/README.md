<h2><a href="https://leetcode.com/problems/rotating-the-box/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Uber</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Netflix</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>eBay</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Capital One</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1861. Rotating the Box</a></h2><h3>Medium</h3><hr><div><p>You are given an <code>m x n</code> matrix of characters <code>box</code> representing a side-view of a box. Each cell of the box is one of the following:</p>

<ul>
	<li>A stone <code>'#'</code></li>
	<li>A stationary obstacle <code>'*'</code></li>
	<li>Empty <code>'.'</code></li>
</ul>

<p>The box is rotated <strong>90 degrees clockwise</strong>, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity <strong>does not</strong> affect the obstacles' positions, and the inertia from the box's rotation <strong>does not </strong>affect the stones' horizontal positions.</p>

<p>It is <strong>guaranteed</strong> that each stone in <code>box</code> rests on an obstacle, another stone, or the bottom of the box.</p>

<p>Return <em>an </em><code>n x m</code><em> matrix representing the box after the rotation described above</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png" style="width: 300px; height: 150px;"></p>

<pre><strong>Input:</strong> box = [["#",".","#"]]
<strong>Output:</strong> [["."],
&nbsp;        ["#"],
&nbsp;        ["#"]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode2withstones.png" style="width: 375px; height: 195px;"></p>

<pre><strong>Input:</strong> box = [["#",".","*","."],
&nbsp;             ["#","#","*","."]]
<strong>Output:</strong> [["#","."],
&nbsp;        ["#","#"],
&nbsp;        ["*","*"],
&nbsp;        [".","."]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode3withstone.png" style="width: 400px; height: 218px;"></p>

<pre><strong>Input:</strong> box = [["#","#","*",".","*","."],
&nbsp;             ["#","#","#","*",".","."],
&nbsp;             ["#","#","#",".","#","."]]
<strong>Output:</strong> [[".","#","#"],
&nbsp;        [".","#","#"],
&nbsp;        ["#","#","*"],
&nbsp;        ["#","*","."],
&nbsp;        ["#",".","*"],
&nbsp;        ["#",".","."]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == box.length</code></li>
	<li><code>n == box[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>box[i][j]</code> is either <code>'#'</code>, <code>'*'</code>, or <code>'.'</code>.</li>
</ul></div>