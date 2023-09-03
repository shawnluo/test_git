//0901
int binary_search_loop(int *pArr,int arr_len,int target)
{
    if((pArr == NULL)
    &&(arr_len < 0))
    {
        return -1;
    }
    int left = 0;
    int right = arr_len-1;
    int ret = -1;
    int mid = 0;
    while(left<=right)
    {
        if(left == right)
        {
            if(pArr[left] == target)
            {
                ret = left;
                goto end;
            }
        }
        else
        {
            mid = (left+right)/2;
            if(pArr[mid] == target)
            {
                ret = mid;
                goto end;
            }        
            else if(pArr[mid] < target)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
    }
end:
    return ret;
}


int binary_search_recursion(int *pArr, int left, int right, int target)
{
    if((pArr == NULL)
    ||(left < 0)
    ||(right < 0))
    {
        return -1;
    }
    int ret = -1;
    if(left <= right)
    {
        if(left == right)
        {
            if(pArr[left] == target)
            {
                ret = left;
                goto end;
            }
            else
            {
                ret = -1;
                return end;
            }
        }
        else
        {
            int mid = (left+right)/2;
            if(pArr[mid] == target)
            {
                ret = mid;
                return end;
            }
            else if(pArr[mid] > target)
            {
                right = mid-1;
                ret = binary_search_recursion(pArr,left,right,target);
                goto end;
            }
            else
            {
                left = mid+1;
                ret = binary_search_recursion(pArr,left,right,target);
                goto end;
            }
        }
    }
end:
    return ret;
}

int binary_search_solution2(int *pArr, int arr_len)
{
    if((pArr == NULL)
    ||(arr_len < 0))
    {
        return -1;
    }
    int left = 0;
    int right=arr_len-1;
    ret = binary_search_recursion(pArr,left,right,target);
    return ret;
}


int delete_given_element(int *pArr, int arr_len, int del_target)
{
    if((pArr == NULL)
    ||(arr_len < 0))
    {
        return -1;
    }
    int slow_idx = 0;
    int fast_idx = 0;
    int find_flag = 0;
    while((slow_idx <= arr_len-1)
        &&(fast_idx <= arr_len-1))
    {
            if(pArr[slow_idx] != del_target)
            {
                slow_idx++;
            }
            else
            {
                if(find_flag == 0)
                {
                    find_flag = 1;
                    fast_idx = slow_idx+1;
                    while((fast_idx <= arr_len-1) &&(pArr[fast_idx] == del_target))
                    {
                        fast_idx++;
                    }
                    if((fast_idx <= arr_len-1) &&(pArr[fast_idx] != del_target))
                    {
                        //delete the found target here
                        pArr[slow_idx] = pArr[fast_idx];
                        
                        find_flag = 0;
                        slow_idx++;
                    }
               }
            }
        }
    }
}


int del_duplicated_element(int *pArr, int arr_len)
{
    if((pArr == NULL)
    ||(arr_len < 0))
    {
        return -1;
    }

    int compare_base_idx = 0;
    int dup_hole_idx = -1;
    int non_dup_idx = -1;
    int find_hole_flag = 0;
    int j = 0;
    int new_len = 0;

    while((compare_base_idx <= arr_len-1)
    &&(dup_hole_idx <= arr_len-1)
    &&(non_dup_idx <= arr_len-1))
    {
        if((compare_base_idx+1) <= arr_len-1)
        {
            if(pArr[compare_base_idx +1] == pArr[compare_base_idx])
            {
                if(find_hole_flag == 0)
                {
                    find_hole_flag = 1;
                    dup_hole_idx = compare_base_idx+1;

                    //find the first non-duplicated element
                    j = dup_hole_idx+1;
                    while((j <= arr_len-1)
                        &&(pArr[j] == pArr[compare_base_idx]))
                    {
                        j++;
                    }
                    if((j <= arr_len+1) &&(pArr[j] != pArr[compare_base_idx]))
                    {
                        non_dup_idx = 0;

                        //delete the duplicated element here
                        pArr[dup_hole_idx] = pArr[non_dup_idx];
                        new_len++;
                        find_hole_flag = 1;
                        dup_hole_idx++;
                        compare_base_idx = non_dup_idx;
                        non_dup_idx=-1;
                    }

                }            

            }
        }
        else
        {
            compare_base_idx++;
            new_len++;
        }
    }
    return new_len;
}