// Created at 2023.04.12 by MidVC

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int min(int a, int b) {
  if (a <= b) {
    return a;
  }
  return b;
}

int max (int a, int b) {
  if (a >= b) {
    return a;
  }
  return b;
}

// get_manacher_string(s) is a helper function that returns a string that
//   starts with a '$', ends with a '^', and a '#' is inserted between
//   every two chars
// example: if we input "abc", then it will return a string "$#a#b#c#^"
// requires: s is a valid string
// effects: allocates heap memory (user must call free)
// time: O(n) where n is the length of the input string
char *get_manacher_string(char *s) {
  int s_len = strlen(s);
  char *s_n = malloc((2 * s_len + 5) * sizeof(char));
  s_n[0] = '$';
  s_n[1] = '#';
  int position = 2;
  for (int i = 0; i < s_len; i++) {
    s_n[position] = s[i];
    s_n[position + 1] = '#';
    position += 2;
  }
  s_n[position] = '^';
  s_n[position] = '\0';
  return s_n;
}

char * longestPalindrome(char * s){
  int p[10000];
  memset(p, 0, 10000 * sizeof(int));
  char *palindromic = malloc(1001 * sizeof(char));
  memset(palindromic, 0, 1001 * sizeof(char));
  char *manacher_s = get_manacher_string(s);
  int centre = 0;
  int border = 0;
  int s_len = strlen(s);
  int ms_len = strlen(manacher_s);
  int max_len = -1;

  for (int i = 1; i < ms_len; i++) {

    if (i < border) {
      p[i] = min(p[centre * 2 - 1], border - i);
    }
    else {
      p[i] = 1;
    }

    while (manacher_s[i - p[i]] == manacher_s[i + p[i]]) {
      p[i]++;
    }

    if (border < i + p[i]) {
      centre = i;
      border = i + p[i];
    }

    if (max_len < p[i] - 1) {
      max_len = p[i] - 1;
      int pos = (i - 1) / 2 - (max_len / 2);
      for (int j = 0; j < max_len; j++) {
        palindromic[j] = s[pos];
        pos++; 
      }
    }
  }

  return palindromic;
}

int dbg_longestPalindrome(char * s){
  int p[2004];
  memset(p, 0, 2004 * sizeof(int));
  char *palindromic = malloc(1001 * sizeof(char));
  memset(palindromic, 0, 1001 * sizeof(char));
  char *manacher_s = get_manacher_string(s);
  int centre = 0;
  int border = 0;
  int s_len = strlen(s);
  int ms_len = strlen(manacher_s);
  int max_len = -1;

  for (int i = 1; i < ms_len; i++) {

    if (i < border) {
      p[i] = min(p[centre * 2 - 1], border - i);
    }
    else {
      p[i] = 1;
    }

    while (manacher_s[i - p[i]] == manacher_s[i + p[i]]) {
      p[i]++;
    }

    if (border < i + p[i]) {
      centre = i;
      border = i + p[i];
    }

    if (max_len < p[i] - 1) {
      max_len = p[i] - 1;
      for (int i = 0; i < p[i] - 1; i++) {
        int j = 2 * (p[i] - 1) - i;
        palindromic[i] = s[i - p[i] + 1];
        palindromic[j] = s[i - p[i] + 1];
      }
    }
  }
  
  free(palindromic);
  return max_len;
}

int main(void) {
  char s[6] = "babad";
  int a = dbg_longestPalindrome(s);
  char *ps = longestPalindrome(s);
  printf("%d\n", a);
  printf("%s\n", ps);
  free(ps);
}