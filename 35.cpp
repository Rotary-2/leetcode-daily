class Solution {
public:
    vector<int> Nums;
    int Target;

    int search(int l, int r) {
        if (l > r) return l;

        int mid = (l + r) / 2;

        if (Nums[mid] == Target) return mid;
        if (Nums[mid] < Target) return search(mid + 1, r);
        else return search(l, mid - 1);
    }

    int searchInsert(vector<int>& nums, int target) {
        Nums = nums;
        Target = target;
        return search(0, nums.size() - 1);
    }
};