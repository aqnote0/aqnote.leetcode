/*
 * ============================================================================
 *
 *       Filename:  1.c
 *
 *    Description: https://leetcode-cn.com/problems/two-sum/
 *
 *        Version:  1.0
 *        Created:  10/08/19 10:10:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);  // 返回数组
    *returnSize = 2;                              // 返回数组的长度
    int loop1, loop2;
    for (loop1 = 0; loop1 < numsSize - 1; loop1++) {
        for (loop2 = loop1 + 1; loop2 < numsSize; loop2++) {
            if (nums[loop1] + nums[loop2] == target) {
                result[0] = loop1;
                result[1] = loop2;
                return result;
            }
        }
    }
    return result;
}

int main(int argc, char** argv) {
    int nums[] = {15, 11, 2, 7};
    int len = sizeof(nums) / sizeof(nums[0]);

    int target = 9;
    int* result = twoSum(nums, len, target, (void*)0);
    printf("[%d, %d]\n", result[0], result[1]);
    free(result);
    return 0;
}
