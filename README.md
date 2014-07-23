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



