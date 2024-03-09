<h2><a href="https://leetcode.com/problems/matrix-diagonal-sum/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Bloomberg</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1572. Matrix Diagonal Sum</a></h2><h3>Easy</h3><hr><div><p>Given a&nbsp;square&nbsp;matrix&nbsp;<code>mat</code>, return the sum of the matrix diagonals.</p>

<p>Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png" style="width: 336px; height: 174px;">
<pre><strong>Input:</strong> mat = [[<strong>1</strong>,2,<strong>3</strong>],
&nbsp;             [4,<strong>5</strong>,6],
&nbsp;             [<strong>7</strong>,8,<strong>9</strong>]]
<strong>Output:</strong> 25
<strong>Explanation: </strong>Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[<strong>1</strong>,1,1,<strong>1</strong>],
&nbsp;             [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;             [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;             [<strong>1</strong>,1,1,<strong>1</strong>]]
<strong>Output:</strong> 8
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> mat = [[<strong>5</strong>]]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == mat.length == mat[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>
</div>