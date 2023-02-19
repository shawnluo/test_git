
#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void quickSort(int* nums, int first, int end) {     //快速排序 
	int temp, l, r;
	if (first >= end) {
		return;
	}
	temp = nums[first];
	l = first;
	r = end;
	while (l < r) {
		while (l < r && nums[r] >= temp) {
			r--;
		}
		if (l < r) {
			nums[l] = nums[r];
		}
		while (l < r && nums[l] <= temp) {
			l++;
		}
		if (l < r) {
			nums[r] = nums[l];
		}
	}
	nums[l] = temp;
	quickSort(nums, first, l - 1);
	quickSort(nums, l + 1, end);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int i = 0;								//当前数值下标
	int left = i+1;							//左指针
	int right = numsSize - 1;				//右指针
	int sum = 0;							//和
	int base_alloc_size = 16;				//基本内存
	int** res = (int**)malloc(sizeof(int*) * base_alloc_size);
	(*returnSize) = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * base_alloc_size);

	if (numsSize < 3 || nums == NULL) {
		return NULL;
	}

	quickSort(nums, 0, numsSize - 1);                           //排序

	for (i = 0; i <= numsSize - 3; i++) {
		left = i + 1;
		right = numsSize - 1;
		if (nums[i] > 0) {										// 如果当前数字大于0，则三数之和一定大于0，所以结束循环
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {					// 去重
			continue;
		}
		while (left < right) {
			sum = nums[i] + nums[left] + nums[right];
			if (sum > 0) {
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				res[*returnSize] = (int*)calloc(3, sizeof(int));
				res[*returnSize][0] = nums[i];
				res[*returnSize][1] = nums[left];
				res[*returnSize][2] = nums[right];

				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;

				while (left < right && nums[left] == nums[left + 1]) {		//去除重复的
					left++;
				}
				while (left < right && nums[right] == nums[right - 1]) {
					right--;
				}
				left++; right--;
			}

			if (*returnSize == base_alloc_size) {							//空间不足，扩充内存
				base_alloc_size = base_alloc_size * 2;
				res = (int**)realloc(res, base_alloc_size * sizeof(int*));
				(*returnColumnSizes) = (int*)realloc((*returnColumnSizes), base_alloc_size * sizeof(int));
			}
		}
	}
	return res;
}


int main() {
	int num[] = { -1, 0, 1, 2, -1, -4 };
	int* nums = (int*)num;
	int numsSize = sizeof(num) / sizeof(int);
	int* returnSize = (int*)calloc(1, sizeof(int));
	//这里的内存分配最大值,即排列组合知识,C几取3
	//C6取3 == 20
	int** returnColumnSizes = (int**)malloc(sizeof(int*) * (numsSize * (numsSize - 1) * (numsSize - 2)) / 6);
	int** res = threeSum(nums, numsSize, returnSize, returnColumnSizes);

	for (int i = 0; i < *returnSize; i++) {				//打印
		for (int j = 0; j < 3; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
