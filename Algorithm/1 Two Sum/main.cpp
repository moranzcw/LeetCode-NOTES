#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int num,pos;
};

bool cmp(Node a, Node b)
{
    return a.num < b.num;
}

class Solution 
{
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> result;
        vector<Node> sortedArray;
        for(int i = 0;i<numbers.size();i++)
        {
            Node temp;
            temp.num = numbers[i];
            temp.pos = i;
            sortedArray.push_back(temp);
        }
        /* step 1. sort */
        sort(sortedArray.begin(),sortedArray.end(),cmp);

        /*step 2. two pointer for head and tail, then get closer, find the target. */
        for(int i = 0, j =sortedArray.size()-1; i != j;)
        {
            int sum = sortedArray[i].num + sortedArray[j].num;
            if(sum == target)
            {
                if (sortedArray[i].pos < sortedArray[j].pos)
                {
                    result.push_back(sortedArray[i].pos + 1);
                    result.push_back(sortedArray[j].pos + 1);
                } 
                else
                {
                    result.push_back(sortedArray[j].pos + 1);
                    result.push_back(sortedArray[i].pos + 1);
                }
                break;
            }
            else if (sum < target)
            {
                i++;
            }
            else if (sum > target)
            {
                j--;
            }
        }
        return result;
    }
};

int main()
{
    // test
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(15);
    Solution sol;
    vector<int> temp(sol.twoSum(numbers,9));
    cout<<temp[0]<<temp[1];
}