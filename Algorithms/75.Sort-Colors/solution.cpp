class Solution 
{
public:
    void sortColors(int A[], int n) 
    {
        int count[3] = {0};

        for(int i=0;i<n;i++)
            count[A[i]] ++;

        int index = 0;
        while(count[0])
        {
            A[index] = 0;
            count[0]--;
            index++;
        }
        while(count[1])
        {
            A[index] = 1;
            count[1]--;
            index++;
        }
        while(count[2])
        {
            A[index] = 2;
            count[2]--;
            index++;
        }
    }
};