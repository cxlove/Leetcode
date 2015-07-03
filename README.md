#LeetCode 记录
**跟风刷leetcode**,<del>cxlove刚好练习一下python</del>

Leetcode有个很严重的问题，就是大多没有数据范围。
所以我是在尽可能偷懒的情况下用尽可能优的做法。

##Two Sum 
找到数组中两个数的和为Target。

拿个map/c++，HashMap/Java,dict/python维护一下就好了，O(nlgn)

##Median of Two Sorted Arrays
两个有序数组，O(log(m + n))找到中位数。

其实就是在O(log(m + n))找到第K大。
那么只需要二分在某个数组中的个数，那么另外一个数组的个数就确定了。然后只需要check一下是否合法就OK了。

##Longest Substring Without Repeating Characters
最长的不出现重复字符的子串。

典型的two points问题，枚举左端点，维护右端点的右移。用个数组记录一下字符出现个数就ok了。O(n)。
不了解two points的话，也很容易想到具有单调性，枚举左端点，二分右端点，维护一下各个字符出现的前缀和，貌似也可做。

##Add Two Numbers
两个长整数的加法，链表形式。

没啥好说的，直接链表模拟就好。

## ZigZag Conversion 
按zigzag形状输出字符串。

按行枚举就好了，计算出相应的间隔，暴力就好。

## Reverse Integer 
将整数反转

直接做。。。

##String to Integer (atoi) 
字符串转换成整数。

按题意直接做。

##Palindrome Number
判断一个数是否是回文数。

转成字符串，reverse然后再判断。

## Regular Expression Matching
判断带有通配符的字符串是否相等。

做法1：直接递归做，遇到*的话，就一直往后枚举递归，匹配多少个。至少python这样直接搞会TLE，然后就得记忆化一下。

做法2：DP

##Container With Most Water 
两个端点从两头往中间靠，矮的那个移动

## Integer to Roman
阿拉伯数字转化成罗马数字

##Roman to Integer
罗马数字转化成阿拉伯数字

## Longest Common Prefix 
N个串的最长公共前缀

直接枚举判断就好

## 3Sum
选出triple ()和为0

排序之后，枚举前两个数，然后two points维护第三个数
根据单调性，注意一下不要重复就好

## 3Sum Closest 
选出triple ()的和最接近targe

排序后，枚举第一个数，然后两头夹维护后两个数

## 4Sum 
找出四个数的和为target

首先先类似3sum来一发O(n ^ 3)的枚举+two points , TLE
觉得确实有点慢，于是来一发类似3Sum Closest的O(n ^ 2)，Python还是TLE，换C++过了

## Letter Combinations of a Phone Number
直接模拟就好

##　Remove Nth Node From End of List 
删除链表倒数第n个节点

two points，维护两个指针，右指针先往右移动n步。
然后再同步移，直到右指针到尾，就能推断出需要删的节点是哪个。

## Valid Parentheses
判断括号序列是否合法

经典堆栈应用

##Generate Parentheses 
输出所有的合法括号 序列

直接dfs，记录前缀和判断是否合法


## Merge k Sorted Lists
合并K个有序链表

对应于两个链表的合并，K个就是维护K个指针，在K个value里找个最小的插入链表，然后后移。

可以用堆或者优化队列来加速合并。O(sumlen * log (k))

## Swap Nodes in Pairs 
链表相邻两两交换

直接模拟

## Remove Duplicates from Sorted Array 
去除重复元素

排序之后直接离散化,233333

## Remove Element 
删除指定val的元素

直接遍历一遍

## Implement strStr()
模拟strStr ()函数

裸的KMP匹配一下

##Divide Two Integers 
不用除法，乘法的情况下，计算除法

首先判断符号，保证是正数除以正数，直接用减法来模拟是会超时的

采用二分法，直接二分答案需要乘法也是不行的

二进制枚举，从高位开始

##Substring with Concatenation of All Words
直接枚举，然后切割子串，用map来统计一下，或者hash一下。

## Next Permutation
求一个全排列

C++直接next_permutation就行了。。。。

至于模拟的话，就直接贪心构造，从后往前枚举左指针，从后往前枚举右指针，插入然后排序贪心

## Longest Valid Parentheses 
最长的子串是合法的括号序列

堆栈模拟，如果当前是右括号，堆栈顶是左括号，那么会pop，那么当前位置一直到堆栈顶都是合法序列，因为全部被Pop掉了。

##Search in Rotated Sorted Array 
排序后的数组，旋转之后去查找

同样是二分，注意到分成两段，一段全部>=A[0]，一段全部<=A[-1]。
也就是看targe属于哪一段，然后二分。

## Search for a Range
一个排序的数组，查找某个数在数组中的下标区间

直接二分上下界

##Search Insert Position
有序数组，如果某个数存在返回下标，否则这个数插入到数组中的位置 

直接二分

## Valid Sudoku
判断数独是否合法

分三个部分判断，行列块

## Sudoku Solver 
求解数独

直接上DFS吧，DLX太麻烦了。。。

## Count and Say
题意比较DT

反正就是直接模拟就好，而且知道数量肯定是个位数

## Combination Sum 
找出所有的组合，和为target

直接dfs暴搜。。。

## Combination Sum II
和上一题差不多

dfs的时候，如果当前这个数不取，那么后面和它一样的数都不取

## First Missing Positive
找到最小的没有出现在数组中的正整数

由于题意要求常数空间，O(n)算法。所以排序以及set,hash之类的都是不可以的。

做法也比较厉害，原本数组下标是0到n-1，我们遍历数组让其中数字A出现在下标A-1中。然后遍历一次就好了。

##Trapping Rain Water
对于每个位置，水高是左右最大值的最小值
所以处理前缀的最大值，和后缀的最大值，然后枚举就行。

## Multiply Strings 
直接模拟高精度乘法

## Jump Game II 
首先容易想到n^2的DP
然后发现可以用线段树之类的优化到nlgn
最后其实可以O(n)做。
按BFS分层来做，每次走一个区间，记录每一步可以到达的最远的位置

## Permutation I & II
sort , next_permutation , unique大法好

## Rotate image
直接做

## Anagrams
题意很坑而已
直接对每个串sort，放进map里面

## pow (x , n)
直接上二分快速幂，注意指数为负的情况

## Maximum Subarray
维护前缀和的最小值，然后每次当前的前缀和剪去前缀的前缀的最小值就OK了。
O(n)

##Sprial Matrix
没啥好说的，暴力。

##Jump Game
维护能够到达最远的位置，然后一个个枚举

##Merge Intervals 
按左端点升序，然后每次和最后一个比较一下是否能够合并就行

##Insert Interval 
我懒，直接append之后按上一题来做

##Length of Last Word
strip()之后暴力。。。

##Spiral Matrix II
blablabla

##Permutation Sequence
按位枚举

## Summary Ranges 
就是枚举，遍历一下就好了

## Invert Binary Tree 
没啥意思的题，就是递归交换左右子树



