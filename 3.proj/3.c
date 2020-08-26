/*
 * ============================================================================
 *
 *       Filename:  3.c
 *
 *    Description: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 *
 *        Version:  1.0
 *        Created:  02/24/20 15:45:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@qq.com>,
 *   Organization:
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int i, j, k;
    int max = 0;  // 最大子串长度

    // 获取字符串长度
    int s_length = 0;
    for (i = 0; s[i] != 0x00; i++) s_length++;

    for (i = 0; i < s_length; i++) {
        // 已找到最大，不需要再找
        if (max > s_length - i) break;

        int targets_length;  // 当前子串长度
        char targets[256];   // 当前子串内容
        memset(targets, 0, 256);

        // 从i开始找出最大子串
        targets[0] = s[i];
        targets_length = 1;
        for (j = i + 1; j < s_length; j++) {
            int add_flag = 1;
            // 是否存在相同的元素：存在，设置add_flag变量为0
            for (k = 0; k < targets_length; k++) {
                if (targets[k] == s[j]) {
                    add_flag = 0;
                    break;
                }
            }

            // 没有相同的字符，添加子串内容；存在相同字符，表示到找最大子串
            if (add_flag == 1) {
                targets[targets_length] = s[j];
                targets_length++;
            } else {
                break;
            }
        }
        max = targets_length > max ? targets_length : max;
    }

    return max;
}

int main(int argc, char **argv) {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));
    return 0;
}
