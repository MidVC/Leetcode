//
// Created by luton on 2023/3/10.
//

int min(int a, int b) {
    if (a <= b)
        return a;
    return b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    // Regulate the input so that nums1.length >= nums2.length
    if (nums1Size < nums2Size)
        findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    // If nums2Size is 0, then simply return the median of the array nums1
    if (nums2Size == 0) {
        if (nums1Size % 2 == 0)
            return 0.5*(nums1[nums1Size/2] + nums1[(nums1Size-1)/2]);
        else
            return 1.0*nums1[nums1Size/2];
    }

    // Obtain the index of the median of the two arrays (combined)
    int median = (nums1Size+nums2Size-1)/2;
    int odd = (nums1Size+nums2Size-1)%2;

    // Do the binary search on nums2
    int Left_nums2 = 0;
    int Right_nums2 = nums2Size-1;
    for(int i = 0; i < 1001; i++) {
        int position_nums2 = (Left_nums2+Right_nums2)/2;
        int position_nums1 = median - position_nums1;
        if (Left_nums2 == Right_nums2)  {
            if (odd)
                return 1.0*min(nums1[position_nums1], nums2[position_nums2]);
            else
                return 0.5*(min(nums1[position_nums1], nums2[position_nums2]) +
                            min(nums1[position_nums1] + nums2[position_nums2] - min(nums1[position_nums1], nums2[position_nums2])
                                , min(nums1[position_nums1+1], nums2[position_nums2+1])));
        }
        else if (nums1[position_nums1] == nums2[position_nums2])
            return nums1[position_nums1];
        else if (nums1[position_nums1] > nums2[position_nums2]) {
            Left_nums2 = position_nums2;
        }
        else {
            Right_nums2 = position_nums2 - 1;
        }
    }

    return 0;
}