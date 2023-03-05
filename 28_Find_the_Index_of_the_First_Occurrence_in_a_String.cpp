class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_len = haystack.size();
        int n_len = needle.size();
        int diff_len = h_len - n_len + 1;
        bool flag;
        for (int i = 0; i < diff_len; i++) {
            if (haystack[i] == needle[0]) {
                flag = true;
                for (int j = 1; j < n_len; j++) {
                    if (haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
};