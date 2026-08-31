/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 1;
        int first = -1;
        int prev = -1;
        
        int minDist = INT_MAX;
        int maxDist = -1;

        ListNode* curr = head->next;
        ListNode* before = head;

        while (curr->next != nullptr) {
            ListNode* after = curr->next;

            // Check if current node is a critical point
            if ((curr->val > before->val && curr->val > after->val) ||
                (curr->val < before->val && curr->val < after->val)) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prev);

                    // Distance from first critical point
                    maxDist = pos - first;
                }

                prev = pos;
            }

            before = curr;
            curr = curr->next;
            pos++;
        }

        if (first == -1 || minDist == INT_MAX) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};