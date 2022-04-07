class Solution {
    public boolean isSolvable(String[] words, String result) {
        Set<Character> set = new HashSet<>();
        boolean[] first = new boolean[26];
        for(String word : words){
            if(word.length() > 1)
                first[word.charAt(0) - 'A'] = true;
            for(int i = 0; i < word.length(); i++)
                set.add(word.charAt(i));
        }
        if(result.length() > 1)
            first[result.charAt(0) - 'A'] = true;
        for(int i = 0; i < result.length(); i++)
            set.add(result.charAt(i));
        StringBuilder sb = new StringBuilder();
        for(char ch : set)
            sb.append(ch);
        String str = sb.toString();
        int[] map = new int[26];
        Arrays.fill(map, -1);
        return find(str, 0, new boolean[10], map, words, result, first);
    }
    
    private boolean find(String str, int idx, boolean[] used, int[] map, String[] words, String result, boolean[] first){
        if(idx == str.length()){
            int sum = 0;
            for(String word : words){
                sum += solve(word, map);
            }
            return sum == solve(result, map);
        }
        char ch = str.charAt(idx);
        if(!first[ch - 'A']){
            if(!used[0]){
                used[0] = true;
                map[ch - 'A'] = 0;
                if(find(str, idx + 1, used, map, words, result, first))
                    return true;
                map[ch - 'A'] = -1;
                used[0] = false;
            }
        }
        for(int i = 1; i < 10; i++){
            if(!used[i]){
                used[i] = true;
                map[ch - 'A'] = i;
                if(find(str, idx + 1, used, map, words, result, first))
                    return true;
                map[ch - 'A'] = -1;
                used[i] = false;
            }
        }
        return false;
    }
    
    private int solve(String str, int[] map){
        int val = 0;
        for(int i = 0; i < str.length(); i++){
            val *= 10;
            val += map[str.charAt(i) - 'A'];
        }
        return val;
    }
}