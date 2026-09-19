class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>maxHeap;

        unordered_map<char,int>freq;

        for(char task: tasks){
            freq[task]++;
        }

      for(auto& task: freq){
         maxHeap.push(task.second);
      }

        int time=0;

      

        while(!maxHeap.empty()){
            int cycle = n+1;
              int i=0;
             vector<int>temp;

             while(i<cycle && !maxHeap.empty()){
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--;

                if(cnt>0){
                    temp.push_back(cnt);
                }
                
                time++;
                i++;
             }

             for(int i=0;i<temp.size();i++){
                maxHeap.push(temp[i]);
             }

             if(maxHeap.empty()) break;

             time += (cycle-i);
        }

return time;
        
    }   
};