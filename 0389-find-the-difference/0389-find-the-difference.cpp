class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<int,int>freq1;
       unordered_map<int,int>freq2;
       char ch;
        for(int i=0;i<s.size();i++)
{
              freq1[s[i]-'a']++;

}   

        for(int i=0;i<t.size();i++)
{
              freq2[t[i]-'a']++;

} 
for(const auto& p:freq1){
    if(freq2.find(p.first)!=freq2.end()){
        int cnt = freq1[p.first];
        freq1[p.first]=0;
        freq2[p.first]-=cnt;
    }
}
for(const auto& p: freq2){
    if(p.second!=0){
        int q = p.first;
         ch = q+'a';
        break;
    }
}
return ch;
 }
};