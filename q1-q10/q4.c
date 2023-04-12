//
// Created by luton on 2023/3/10.
//

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
  // Regulate the input so that nums1.length <= nums2.length
  if (nums1Size > nums2Size) {
    return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
  }

  int total_size = nums1Size + nums2Size;
  int partition = (total_size + 1) / 2;

  // Edge cases
  if (nums2Size == 0) {
    return 0;
  }
  if (nums1Size == 0) {
    if (nums2Size % 2 == 0) {
      return (nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2.0;
    }
    else {
      return nums2[nums2Size / 2];
    }
  }

  // Now, do the partition
  int left1 = 0;
  int right1 = nums1Size;
  int cut1 = 0;
  int cut2 = 0;
  int l1, r1, l2, r2;

  while (left1 <= right1) {
    // Find cut1 and cut2
    cut1 = (left1 + right1) / 2;
    cut2 = partition - cut1;

    // Calculate l1
    if (cut1 == 0) {
      l1 = INT_MIN;
    }
    else {
      l1 = nums1[cut1-1];
    }

    // Calculate l2
    if (cut2 == 0) {
      l2 = INT_MIN;
    }
    else {
      l2 = nums2[cut2 - 1];
    }

    // Calculate r1
    if (cut1 >= nums1Size) {
      r1 = INT_MAX;
    }
    else {
      r1 = nums1[cut1];
    }

    // Calculate r2
    if (cut2 >= nums2Size) {
      r2 = INT_MAX;
    }
    else {
      r2 = nums2[cut2];
    }

    if (l1 <= r2 && l2 <= r1) {
      if (total_size % 2) {
        return max(l1, l2);
      }
      else {
        return (max(l1, l2) + min(r1, r2)) / 2.0;
      }
    }
    else {
      if (l1 > r2) {
        right1 = cut1 - 1;
      }
      else {
        left1 = cut1 + 1;
      }
    }
  }

  return 0;
}

int main(void) {
  int *a = malloc(0 * sizeof(int));
  int *b = malloc(1 * sizeof(int));
  b[0] = 2;
  double result = findMedianSortedArrays(b, 1, a, 0);
  printf("%f\n", result);
  free(a);
  free(b);
}