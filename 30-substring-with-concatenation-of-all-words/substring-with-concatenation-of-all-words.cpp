class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowSize = wordLen * wordCount;
        int n = s.size();

        if (n < windowSize) return ans;

        unordered_map<string, int> freq;
        for (auto& w : words) freq[w]++;

        // Try each offset within word length
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> seen;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (freq.find(word) != freq.end()) {
                    seen[word]++;
                    count++;

                    // Shrink window if too many of this word
                    while (seen[word] > freq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If valid window
                    if (count == wordCount) {
                        ans.push_back(left);
                        // shrink from left
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    // reset if word not in dictionary
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return ans;
    }
};
