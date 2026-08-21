class Solution {
  public:
    int longestKSubstr(string &s, int k) {
     int n = s.size();
     int low = 0;
     int high = 0;
     unordered_map<char, int> freq;
     int result = -1;
     for(int high = 0; high < n; high++){
         freq[s[high]]++;
         while(freq.size() > k){
             freq[s[low]]--;
             if(freq[s[low]] == 0){
             freq.erase(s[low]);
            
             }
             low++;
         }
         if(freq.size() == k){
             int length  = high - low +1;
             result = max(length, result);
         }
         
     }
     return result;   
    }
};

