//
// Created by luton on 2023/3/10.
//
#include <string.h>

int max(int a, int b) {
    if (a >= b) return a;
    return b;
}

int lengthOfLongestSubstring(char *s){

    int chars[128] = {0};
    int max_value = 0;
    int start = -1;

    for(int i = 0; i < strlen(s); i++) {
        int closest = -1;
        for(int j = 0; j < i; j++) {
            if (s[j] == s[i]) {
                closest = j;
                start = max(start, closest);
            }
        }
        max_value = max(max_value, i - start);
    }
    return max_value;
}