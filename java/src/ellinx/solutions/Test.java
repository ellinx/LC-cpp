package ellinx.solutions;

import java.util.List;

public class Test {
	public static void main(String[] args) {
		
		//setup test input
		int[] nums = {4,3,2,7,8,2,3,1};
		FindAllNumbersDisappearedInArray myTest = new FindAllNumbersDisappearedInArray();
		List<Integer> list = myTest.findDisappearedNumbers(nums);
		System.out.println(list);
	}
}
