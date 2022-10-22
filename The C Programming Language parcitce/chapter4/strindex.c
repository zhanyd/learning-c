/**
 * @file strindex.c
 * @author zhanyd(zhanyd@sina.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 * 练习4-1 编写函数strindex(s, t)，它返回字符串t在s中最右边出现的位置。如果s中不包含t，则返回-1。
 */

#include <stdio.h>
#include <string.h>

// 最大输入长度
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

// 需要匹配的字符串
char pattern[] = "ould";

int main() {
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0) {
        if(strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

// 从键盘输入字符串
int getline(char s[], int lim) {
    int c, i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if(c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// 返回匹配的下标
int strindex(char s[], char t[]) {
    int i, j, k;
     printf("s: %s ; strlen(s): %d\n", s, strlen(s));
     printf("t: %s ; strlen(t): %d\n", t, strlen(t));
    for(i = strlen(s) - 1; i > 0 ; i--) {
        for(j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; j--, k--) {
             printf("s[j] = %c; j = %d\n", s[j], j);
             printf("t[k] = %c; k = %d\n", t[k], k);
        }
        if(k == -1) {
            printf("匹配下标: %d\n", i);
            return i;
        }
    }

    return -1;
}