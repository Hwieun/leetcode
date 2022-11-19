class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        int max_count = 0, count_max_task = 0;
        for(char task : tasks) {
            v[task - 'A']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(max_count < v[i]) {
                max_count = v[i];
                count_max_task = 1;
            }
            else if(max_count == v[i])
                count_max_task++;
        }
        
        int part_count = max_count - 1;
        int empty_slot = part_count * (n - (count_max_task - 1));
        int available_tasks = tasks.size() - max_count * count_max_task;
        
        return tasks.size() + max(0, empty_slot - available_tasks);
    }
};