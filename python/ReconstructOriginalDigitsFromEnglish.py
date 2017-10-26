"""
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
"""

class ReconstructOriginalDigitsFromEnglish(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """

        res = ""
        letters = [0]*26

        for each in s:
            letters[ord(each)-ord('a')] += 1

        #z,w,u,x,g identify unique digits
        while letters[ord('z')-ord('a')]>0:
            res += "0"
            letters[ord('z')-ord('a')] -= 1
            letters[ord('e')-ord('a')] -= 1
            letters[ord('r')-ord('a')] -= 1
            letters[ord('o')-ord('a')] -= 1

        while letters[ord('w')-ord('a')]>0:
            res += "2"
            letters[ord('t')-ord('a')] -= 1
            letters[ord('w')-ord('a')] -= 1
            letters[ord('o')-ord('a')] -= 1

        while letters[ord('u')-ord('a')]>0:
            res += "4"
            letters[ord('f')-ord('a')] -= 1
            letters[ord('o')-ord('a')] -= 1
            letters[ord('u')-ord('a')] -= 1
            letters[ord('r')-ord('a')] -= 1

        while letters[ord('x')-ord('a')]>0:
            res += "6"
            letters[ord('s')-ord('a')] -= 1
            letters[ord('i')-ord('a')] -= 1
            letters[ord('x')-ord('a')] -= 1

        while letters[ord('g')-ord('a')]>0:
            res += "8"
            letters[ord('e')-ord('a')] -= 1
            letters[ord('i')-ord('a')] -= 1
            letters[ord('g')-ord('a')] -= 1
            letters[ord('h')-ord('a')] -= 1
            letters[ord('t')-ord('a')] -= 1


        #now o,h,s identify unique digits
        while letters[ord('o')-ord('a')]>0:
            res += "1"
            letters[ord('o')-ord('a')] -= 1
            letters[ord('n')-ord('a')] -= 1
            letters[ord('e')-ord('a')] -= 1

        while letters[ord('h')-ord('a')]>0:
            res += "3"
            letters[ord('t')-ord('a')] -= 1
            letters[ord('h')-ord('a')] -= 1
            letters[ord('r')-ord('a')] -= 1
            letters[ord('e')-ord('a')] -= 1
            letters[ord('e')-ord('a')] -= 1

        while letters[ord('s')-ord('a')]>0:
            res += "7"
            letters[ord('s')-ord('a')] -= 1
            letters[ord('e')-ord('a')] -= 1
            letters[ord('v')-ord('a')] -= 1
            letters[ord('e')-ord('a')] -= 1
            letters[ord('n')-ord('a')] -= 1


        #f and n differentiate what's left
        while letters[ord('f')-ord('a')]>0:
            res += "5"
            letters[ord('f')-ord('a')] -= 1
            letters[ord('i')-ord('a')] -= 1
            letters[ord('v')-ord('a')] -= 1
            letters[ord('e')-ord('a')] -= 1

        while letters[ord('n')-ord('a')]>0:
            res += "9"
            letters[ord('n')-ord('a')] -= 1
            letters[ord('i')-ord('a')] -= 1
            letters[ord('n')-ord('a')] -= 1
            letters[ord('e')-ord('a')] -= 1

        return "".join(sorted(res))


#test
tmp = ReconstructOriginalDigitsFromEnglish()
result = tmp.originalDigits("fviefuro")
print(result)
