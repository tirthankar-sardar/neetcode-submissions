class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task : tasks){
            freq[task - 'A']++;
        }
        int max_freq = INT_MIN;

        for(int f : freq){
            max_freq = max(max_freq, f);
        } //calculating the maximum freq
        int count_max_freq = 0;
        for(int f : freq){
            if(f == max_freq){
                count_max_freq++;
            }
        } //counting how many task has maximum freq
        int frame = (max_freq - 1)*(n+1)+count_max_freq;

        return max(frame, (int)tasks.size());
    }
};
