import java.lang.String;

class Solution13 {
    int[]    nums = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    String[] str  = { "M", "", "D", "", "C", "", "L", "", "X", "", "V", "", "I" };
    String[] str1 = { "", "CM", "", "CD", "", "XC", "", "XL", "", "IX", "", "IV", "" };

    public int romanToInt(String s) {
        if (s.isEmpty())
            return 0;

        for (int i = 0; i < 13; i++) {
            if (s.length() > 1 && s.substring(0,2).equals(str1[i])) {
                return nums[i] + romanToInt(s.substring(2));
            }

            if (s.substring(0,1).equals(str[i])) {
                return nums[i] + romanToInt(s.substring(1));
            }
        }

        return 0;
    }

    public static void main(String args[]) {
        Solution solution = new Solution();
        System.out.printf("romanToInt('MCMXCIV') = %d\n", solution.romanToInt("MCMXCIV"));
    }
}
