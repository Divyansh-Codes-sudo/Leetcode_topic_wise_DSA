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
        vector<int> arr;

        ListNode* temp = head;

        while (temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        int i = 1;
        vector<int> crit;

        while (i < n-1){
            if ((arr[i] < arr[i-1] && arr[i] < arr[i+1])|| (arr[i] > arr[i-1] && arr[i] > arr[i+1])){
                crit.push_back(i);
                i++;
            }else{
                i++;
            }
        }

        n = crit.size();
        if (n <= 1) return {-1 , -1};
        int mini = INT_MAX;
        for (int i = 1 ; i < n ; i++){
            mini = min(mini , crit[i] - crit[i-1]);
        }

        return {mini , (crit[n-1] - crit[0])};


    }
};