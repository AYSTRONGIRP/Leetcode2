class Solution {
    public int countPairs(int[] nums) {

        //Initial Greedy
        Arrays.sort(nums);

        int pair = 0;
        //Prefix Sum
        Map<Integer, Integer> freq = new HashMap<>();

        for (int i = 0; i < nums.length; i++){

            //All possible numbers up to 1 swap
            Set<Integer> hold = swap(nums[i]);

            //All possible numbers up to 2 swaps
            Set<Integer> total = new HashSet<>();

            //Generate all possible numbers up to 2 swaps
            for (int x : hold){
                for (int y : swap(x)){
                    total.add(y);
                }
            }

            //Check if any of possible swapped number contained in prefix sum
            for (int x : total){
                if (freq.containsKey(x)){
                    pair += freq.get(x);
                }
            }

            //Build prefix sum
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
        }

        return pair;
    }

    //Generate all possible number with up to 1 additional swap
    private Set<Integer> swap(int n){

        //Storing all possible generated numbers
        Set<Integer> s = new HashSet<>();

        //Store the original number
        s.add(n);

        //Store the digits
        List<Integer> num = new ArrayList<>();

        //Split number into digits
        while (n > 0){

            //Add the last digit
            num.add(0, n%10);

            //Right shift one place
            //Ex: 12345 -> 1234, or 2742 -> 274
            n /= 10;
        }

        //Trying out all possible numbers with 1 swap
        for (int i = 1; i < num.size(); i++){
            for (int j = 0; j < i; j++){
                int hold1 = num.get(i);
                int hold2 = num.get(j);

                //Swap it
                num.set(i, hold2);
                num.set(j, hold1);

                //Combine all digits into one number
                int sol = cal(num);

                //Add it to all possible generated numbers
                s.add(sol);

                //Swap it back to original number
                num.set(i, hold1);
                num.set(j, hold2);
            }
        }

        return s;
    }

    //Combined all digits into a number
    private int cal(List<Integer> a){

        //Start off with ones digit, then tens, then hundreds, etc
        int ten = 1;

        //The final answer
        int ans = 0;

        //Start from the ones, which is end of the array
        for (int i = a.size() - 1; i > -1; i--){

            //Add the number into the correct digit placement
            ans += ten * a.get(i);

            //Increase from ones to tens, or tens to hundreds, etc
            ten *= 10;
        }

        return ans;
    }
}