package ellinx.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is: [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]
 * 
 * @author Ellinx
 *
 */
public class FourSum {
	public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        if (n<4) return res;
        Arrays.sort(nums);
        
        for (int i=0;i<n-3;i++) {
        	if (i>0 && nums[i-1]==nums[i]) continue;
        	if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        	if (nums[n-4]+nums[n-3]+nums[n-2]+nums[n-1]<target) break;
        	
        	for (int j=i+1;j<n-2;j++) {
        		if (j>i+1 && nums[j-1]==nums[j]) continue;
        		if (nums[i]+nums[j]+nums[j+1]+nums[j+1]>target) break;
            	if (nums[n-4]+nums[n-3]+nums[n-2]+nums[n-1]<target) break;
            	
            	int left = j+1;
            	int right = n-1;
            	while (left < right) {
            		int sum = nums[i]+nums[j]+nums[left]+nums[right];
            		if (sum < target) {
            			left++;
            		} else if (sum > target) {
            			right--;
            		} else {
            			List<Integer> tmp = new ArrayList<>();
            			tmp.add(nums[i]);
            			tmp.add(nums[j]);
            			tmp.add(nums[left]);
            			tmp.add(nums[right]);
            			res.add(tmp);
            			do{left++;} while (nums[left-1]==nums[left] && left<right);
            			do{right--;} while (nums[right]==nums[right+1] && left<right);
            		}
            	}
        	}
        }
        return res;
    }
	
	//test
	public static void main(String[] args) {
		FourSum tmp = new FourSum();
		int[] nums = {1, 0, -1, 0, -2, 2};
		List<List<Integer>> result = tmp.fourSum(nums, 0);
		for (List<Integer> each : result) {
			System.out.println(each.toString());
		}
	}
}
