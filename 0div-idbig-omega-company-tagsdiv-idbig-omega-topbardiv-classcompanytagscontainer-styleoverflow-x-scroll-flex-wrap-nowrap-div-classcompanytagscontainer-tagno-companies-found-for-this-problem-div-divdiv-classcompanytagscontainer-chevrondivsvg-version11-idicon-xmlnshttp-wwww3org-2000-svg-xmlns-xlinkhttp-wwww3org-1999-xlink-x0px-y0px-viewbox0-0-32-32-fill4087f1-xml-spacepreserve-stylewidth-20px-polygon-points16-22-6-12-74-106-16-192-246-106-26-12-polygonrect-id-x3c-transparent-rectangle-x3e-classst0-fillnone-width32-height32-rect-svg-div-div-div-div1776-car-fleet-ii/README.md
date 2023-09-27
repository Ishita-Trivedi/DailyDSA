<h2><a href="https://leetcode.com/problems/car-fleet-ii/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1776. Car Fleet II</a></h2><h3>Hard</h3><hr><div><p>There are <code>n</code> cars traveling at different speeds in the same direction along a one-lane road. You are given an array <code>cars</code> of length <code>n</code>, where <code>cars[i] = [position<sub>i</sub>, speed<sub>i</sub>]</code> represents:</p>

<ul>
	<li><code>position<sub>i</sub></code> is the distance between the <code>i<sup>th</sup></code> car and the beginning of the road in meters. It is guaranteed that <code>position<sub>i</sub> &lt; position<sub>i+1</sub></code>.</li>
	<li><code>speed<sub>i</sub></code> is the initial speed of the <code>i<sup>th</sup></code> car in meters per second.</li>
</ul>

<p>For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the <strong>slowest</strong> car in the fleet.</p>

<p>Return an array <code>answer</code>, where <code>answer[i]</code> is the time, in seconds, at which the <code>i<sup>th</sup></code> car collides with the next car, or <code>-1</code> if the car does not collide with the next car. Answers within <code>10<sup>-5</sup></code> of the actual answers are accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> cars = [[1,2],[2,1],[4,3],[7,2]]
<strong>Output:</strong> [1.00000,-1.00000,3.00000,-1.00000]
<strong>Explanation:</strong> After exactly one second, the first car will collide with the second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> cars = [[3,4],[5,4],[6,3],[9,1]]
<strong>Output:</strong> [2.00000,1.00000,1.50000,-1.00000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= cars.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= position<sub>i</sub>, speed<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li><code>position<sub>i</sub> &lt; position<sub>i+1</sub></code></li>
</ul>
</div>