<h2><a href="https://leetcode.com/problems/queue-reconstruction-by-height/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Facebook</div><div class="companyTagsContainer--tagOccurence">3</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>406. Queue Reconstruction by Height</a></h2><h3>Medium</h3><hr><div><p>You are given an array of people, <code>people</code>, which are the attributes of some people in a queue (not necessarily in order). Each <code>people[i] = [h<sub>i</sub>, k<sub>i</sub>]</code> represents the <code>i<sup>th</sup></code> person of height <code>h<sub>i</sub></code> with <strong>exactly</strong> <code>k<sub>i</sub></code> other people in front who have a height greater than or equal to <code>h<sub>i</sub></code>.</p>

<p>Reconstruct and return <em>the queue that is represented by the input array </em><code>people</code>. The returned queue should be formatted as an array <code>queue</code>, where <code>queue[j] = [h<sub>j</sub>, k<sub>j</sub>]</code> is the attributes of the <code>j<sup>th</sup></code> person in the queue (<code>queue[0]</code> is the person at the front of the queue).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
<strong>Output:</strong> [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
<strong>Explanation:</strong>
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
<strong>Output:</strong> [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= people.length &lt;= 2000</code></li>
	<li><code>0 &lt;= h<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= k<sub>i</sub> &lt; people.length</code></li>
	<li>It is guaranteed that the queue can be reconstructed.</li>
</ul>
</div>