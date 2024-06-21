function removeDuplicates(nums: number[]): number {
    let count = 1;
    let curIndex = 1, replaceIndex = 1;
    let lastValue = nums[0];
    while (curIndex < nums.length) {
        if (nums[curIndex] == lastValue) curIndex++;
        else {
            nums[replaceIndex] = nums[curIndex];
            lastValue = nums[curIndex];
            curIndex++;
            replaceIndex++;
            count++;
        }
    }
    return count;
};