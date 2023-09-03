#include <stdio.h>
#include <string.h>


int combination_include_k_numbers(int *pArr,int n, int k)
{
    if((pArr == NULL)
    ||(n < 0)
    ||(k < 0))
    {
        return -1;
    }

    int n = 0;
    int k = 2;
    int i = 0;
    int base_idx = 0;
    int current_idx = 0;
    int j = 0;
    int  gap = 0;
    int rest_len = 0;

    for(i = 0;i < n;i++)
    {
        base_idx = i;
        gap = 0;
        while(1)
        {
            if(((base_idx+gap+1) < n-1) && ((base_idx+gap+k-1) < n-1))
            {
                //print out the first element
                printf("\n %d",pArr[base_idx]);
                
                //print out the second element
                printf("\n %d",pArr[base_idx])+gap+1);
                
                current_idx = pArr[base_idx]+gap+2;
                //print out the remaining elements
                for(rest_len = k-2; rest_len>=0;rest_len--)
                {
                    
                }
                printf("\n  ")
            }
    }

}