/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

let recurBS = function(nums, low, high, target){
    if(low > high) return -1; //not found
    let mid = low + Math.floor((high - low)/2);
    if(nums[mid] == target) return mid;
    else if(nums[mid] > target) return recurBS(nums, low, mid-1, target);
    else return recurBS(nums, mid+1, high, target);
}

var search = function(nums, target) {
    return recurBS(nums, 0, nums.length-1, target);
};