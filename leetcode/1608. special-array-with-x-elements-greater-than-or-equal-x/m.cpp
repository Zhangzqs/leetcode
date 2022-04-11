class NumArray {
   public:
    vector<int>& nums;
    NumArray(vector<int>& nums) { this->nums = nums; }

    void update(int index, int val) { nums[index] = val; }

    int sumRange(int left, int right) {
        int s = 0;
        for (int i = left; i <= right; i++) s += nums[i];
        return s;
    }
};