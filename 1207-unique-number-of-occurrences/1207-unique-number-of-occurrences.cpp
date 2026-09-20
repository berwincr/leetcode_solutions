class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

         unordered_map<int,int>freq;
        for(int i=0;i<arr.size();i++){
                  freq[arr[i]]++;
        }
          unordered_set<int> seen;
        for(auto& f : freq){
            if(seen.find(f.second) !=seen.end())
                  return false;
             seen.insert(f.second);
        }
        return true;
    }
};