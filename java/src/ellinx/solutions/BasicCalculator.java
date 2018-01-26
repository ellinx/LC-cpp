package ellinx.solutions;

import java.util.Deque;
import java.util.LinkedList;

public class BasicCalculator {
	/**
	 * Implement a basic calculator to evaluate a simple expression string.
	 * 
	 * The expression string may contain open ( and closing parentheses ), the plus
	 * + or minus sign -, non-negative integers and empty spaces .
	 * 
	 * You may assume that the given expression is always valid.
	 * 
	 * Some examples: 
	 * "1 + 1" = 2 
	 * " 2-1 + 2 " = 3 
	 * "(1+(4+5+2)-3)+(6+8)" = 23 
	 * 
	 * Note:
	 * Do not use the eval built-in library function.
	 * 
	 *
	 */
	public int calculateI(String s) {
        int res = 0;
        int index = 0;
        char operator = ' ';
        while (index < s.length()) {
        	if (s.charAt(index) == ' ') {
        		//white space
        		index++;
        	} else if (s.charAt(index) == '+' || s.charAt(index) == '-') {
        		//operator '+' or '-'
        		if (operator != ' ') {
        			System.out.println("error, previous operator is not consumed");
        		}
        		operator = s.charAt(index);
        		index++;
        	} else if (s.charAt(index) == '(') {
        		//expression string within ()
        		int left = 0;
        		int end = index+1;
        		while (end < s.length()) {
        			if (s.charAt(end) == '(')
        				left++;
        			else if (s.charAt(end) == ')') {
        				if (left==0) {
        					if (operator == ' ')
        						res = calculateI(s.substring(index+1, end));
        					else {
        						int op2 = calculateI(s.substring(index+1, end));
        						res = (operator=='+')?(res+op2):(res-op2);
        						operator = ' ';
        					}
        					index = end+1;
        					break;
        				} else {
        					left--;
        				}
        			}
        			end++;
        		}
        	} else {
        		//number
        		int end = index+1;
        		while (end < s.length()) {
        			char a = s.charAt(end);
        			if ( a >= '0' && a <= '9') {
        				end++;
        			} else {
        				break;
        			}
        		}
        		if (operator == ' ')
					res = Integer.valueOf(s.substring(index, end));
				else {
					int op2 = Integer.valueOf(s.substring(index, end));
					res = (operator=='+')?(res+op2):(res-op2);
					operator = ' ';
				}
        		index = end;
        	}
        }
        return res;
    }
	
	/**
	 * Implement a basic calculator to evaluate a simple expression string.
	 * 
	 * The expression string contains only non-negative integers, +, -, *, / operators 
	 * and empty spaces . The integer division should truncate toward zero.
	 * 
	 * You may assume that the given expression is always valid.
	 * 
	 * Some examples:
	 * "3+2*2" = 7
	 * " 3/2 " = 1
	 * " 3+5 / 2 " = 5
	 * Note: Do not use the eval built-in library function.
	 */
	public int calculateII(String s) {
        Deque<Character> operators = new LinkedList<>();
        Deque<Integer> operands = new LinkedList<>();
        int index = 0;
        while (index < s.length()) {
        	char a = s.charAt(index);
        	if (a == ' ') {
        		//white space
        		index++;
        	} else if (a == '+' || a == '-' || a == '*' || a == '/') {
        		//operators '+', '-', '*' and '/'
        		operators.offerLast(a);
        		index++;
        	} else {
        		//number
        		int end = index+1;
        		while (end < s.length()) {
        			char tmp = s.charAt(end);
        			if (tmp>='0' && tmp<='9') {
        				end++;
        			} else {
        				String numStr = s.substring(index,end);
        				if (!operators.isEmpty()) {
        					char prevOp = operators.peekLast();
            				if (prevOp == '+' || prevOp == '-') {
            					operands.offerLast(Integer.valueOf(numStr));
            				} else {
            					int op1 = operands.pollLast();
            					int op = operators.pollLast();
            					int result = Integer.valueOf(numStr);
            					result = (op=='*')?(op1*result):(op1/result);
            					operands.offerLast(result);
            				}
        				} else {
        					operands.offerLast(Integer.valueOf(numStr));
        				}
        				index = end;
        				break;
        			}
        		}
        		if (index < end) {
        			String numStr = s.substring(index,end);
        			if (!operators.isEmpty()) {
    					char prevOp = operators.peekLast();
        				if (prevOp == '+' || prevOp == '-') {
        					operands.offerLast(Integer.valueOf(numStr));
        				} else {
        					int op1 = operands.pollLast();
        					int op = operators.pollLast();
        					int result = Integer.valueOf(numStr);
        					result = (op=='*')?(op1*result):(op1/result);
        					operands.offerLast(result);
        				}
    				} else {
    					operands.offerLast(Integer.valueOf(numStr));
    				}
    				index = end;
        		}
        	}
        }
        
        while (!operators.isEmpty()) {
        	int op1 = operands.pollFirst();
        	int op2 = operands.pollFirst();
        	int op = operators.pollFirst();
        	op2 = (op=='+')?(op1+op2):(op1-op2);
        	operands.offerFirst(op2);
        }
        return operands.pollFirst();
    }
	
	//test 
	public static void main(String[] args) {
		BasicCalculator bc = new BasicCalculator();
		String s = "3+2*2";
		int result = bc.calculateII(s);
		System.out.println(result);
	}
}
