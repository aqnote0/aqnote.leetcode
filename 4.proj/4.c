/*
 * ============================================================================
 *
 *       Filename:  4.c
 *
 *    Description: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 *
 *        Version:  1.0
 *        Created:  08/26/20 15:33:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * 两个数组排序成一个有序数组，再根据算法取中位数
 */
double findMedianSortedArrays_v1(int *nums1, int nums1Size, int *nums2,
                                 int nums2Size) {

    int i, i1, i2;
    // 折半排序
    int numsSize = nums1Size + nums2Size;
    int nums[numsSize];

    i1 = 0;
    i2 = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums1[i1] < nums2[i2]) {
            nums[i] = nums1[i1];
            i1++;
        } else {
            nums[i] = nums2[i2];
            i2++;
        }
    }
    // 判断奇偶
    // 返回结果

    double m = 0;
    if (numsSize % 2 == 1) {
        m = nums[(numsSize + 1) / 2 - 1];
    } else {
        m = (nums[numsSize / 2 - 1] + nums[numsSize / 2]) / 2.0;
    }

    return m;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {

    int i, i1, i2, flag;
    int numsSize = nums1Size + nums2Size;
    int curNum;
    double result;

    result = 0;
    i1 = 0;
    i2 = 0;
    flag = 0;
    for (i = 0; i < numsSize; i++) {

        // C1: i1越界，循环未结束，取nums2的值
        if (i1 >= nums1Size) {
            curNum = nums2[i2];
            i2++;
            goto label_0;
        }

        // C2: i2越界，循环未结束，取nums1的值
        if (i2 >= nums2Size) {
            curNum = nums1[i1];
            i1++;
            goto label_0;
        }

        // C3: 都没越界
        if (nums1[i1] < nums2[i2]) {
            curNum = nums1[i1];
            i1++;
        } else {
            curNum = nums2[i2];
            i2++;
        }

    label_0:
        if (flag == 1) { // 偶数位且已找到第一个数
            result = (result + curNum) / 2.0;
            break;
        }

        // 奇偶数位处理逻辑
        if (numsSize % 2 == 1) {               // 奇数位
            if (i == (numsSize + 1) / 2 - 1) { // 判断是不是目标位置的数
                result = curNum;
                break;
            }
        } else {                         // 偶数位
            if (i == numsSize / 2 - 1) { // 判断是不是第一个数
                result = curNum;
                flag = 1;
                continue;
            }
        }
    }

    return result;
}

int main(int argc, char *argv[]) {

    // int nums1[] = {1, 3};
    // int nums2[] = {2};

    int nums1[] = {1, 2};
    int nums2[] = {3, 4};

    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2Size = sizeof(nums2) / sizeof(int);

    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("result=%f\n", result);

    return 0;
}
