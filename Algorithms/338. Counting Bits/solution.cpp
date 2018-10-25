/* 每个数向右移1位（除以2）后，
二进制表示里的'1'的个数要么与原来相等（偶数，末位是'0')，
要么少了一个（奇数，末位是'1')。

所以在程序循环中，若计算array[i]的'1'的个数，因为之前已经计算过array[i/2]，
此时只需判断array[i]的奇偶性，就可以计算array[i]的'1'的个了。
*/

class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> results = vector<int>(num+1, 0);
        for(int i=1;i<=num;i++)
        {
            results[i] = results[ i >> 1 ] + (i & 1);
        }
        return results;
    }
};