#include "common.h"
#include "test.h"

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, k;
    int **res = (int **)malloc(sizeof(int *) * 10000);
    int count = 0;

    for(i = 0; i < numsSize; i++) {
        for(j = 1; j < numsSize; j++) {
            for(k = 2; k < numsSize; k++) {
                if(i != j && i != k && j != k && nums[i] + nums[j] + nums[k] == 0) {
                    res[count] = (int *)malloc(sizeof(int) * 3);
                    res[count][0] = nums[i];
                    res[count][1] = nums[j];
                    res[count][2] = nums[k];
                    count++;
                }
            }
        }
    }
    *returnSize = count;
    **returnColumnSizes = ;
    return res;
}

vector<vector<int>> threeSum(vector<int>& arr)
    {
       vector<vector<int>> ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int low,high;
        for(int i=0;i<n-2;i++)
        {
            if(i==0||(i>0&&arr[i]!=arr[i-1]))
              {
              low=i+1,high=n-1;
              while(low<high)
              {
                if(arr[low]+arr[high]+arr[i]==0)
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    ans.push_back(temp);
                    while(low<high&&arr[low]==arr[low+1])
                    {
                        low++;
                    }
                    while(high>low&&arr[high]==arr[high-1])
                    {
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(arr[low]+arr[high]+arr[i]>0)
                {
                    high--;
                }
                else
                {
                    low++;
                }
             }
            }
        }
        return ans;
    }
};

int main(void) {
    //break_int(8);
    string_reverse();

    return 0;
}