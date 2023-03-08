/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long rec[100001] = { 0 };
    long long sorted[100001];
    void merge(int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        int k = start;

        while ((i <= mid) && (j <= end)) {
            if (rec[i] < rec[j]) {
                sorted[k] = rec[j];
                j++;
            }
            else {
                sorted[k] = rec[i];
                i++;
            }
            k++;
        }

        if (i > mid) {
            for (int t = j; t <= end; t++) {
                sorted[k] = rec[t];
                k++;
            }
        }
        else {
            for (int t = i; t <= mid; t++) {
                sorted[k] = rec[t];
                k++;
            }
        }

        for (int t = start; t <= end; t++) {
            rec[t] = sorted[t];
        }
        return;
    }

    void merge_sort(int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            merge_sort(start, mid);
            merge_sort(mid + 1, end);
            merge(start, mid, end);
        }
        return;
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<pair<TreeNode*, int>> Q;
        pair<TreeNode*, int> cur;
        Q.push(make_pair(root, 0));
        while (!Q.empty()) {
            cur = Q.front();
            Q.pop();
            rec[cur.second] += cur.first->val;
            if (cur.first->left) {
                Q.push(make_pair(cur.first->left, cur.second + 1));
            }
            if (cur.first->right) {
                Q.push(make_pair(cur.first->right, cur.second + 1));
            }
        }
        merge_sort(0, 100000);
        long long ans = rec[k - 1];
        return (ans == 0) ? -1 : ans;
    }
};