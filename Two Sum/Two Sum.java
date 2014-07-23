public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap <Integer  , Integer > map = new HashMap <Integer  , Integer > ();
        int ans[] = new int [2];
        for (int i = 0 ; i < numbers.length ; i ++) {
            if (map.containsKey  (target - numbers[i])) {
                ans[0] = map.get (target - numbers[i]);
                ans[1] = (i + 1);
                return ans;
            }
            map.put (numbers[i] , i + 1);
        }
        return ans;
    }
}