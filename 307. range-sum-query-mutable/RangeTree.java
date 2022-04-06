class NumArray {
    class TreeNode {
        int start, end, sum;
        TreeNode left, right;
    }

    TreeNode buildTree(int[] nums, int start, int end) {
        int mid = (end - start) / 2 + start;
        TreeNode root = new TreeNode();
        root.start = start;
        root.end = end;
        if (start < end) {
            root.left = buildTree(nums, start, mid);
            root.right = buildTree(nums, mid + 1, end);
            root.sum = root.left.sum + root.right.sum;
        } else if (start == end) {
            root.left = null;
            root.right = null;
            root.sum = nums[start];
        }

        return root;
    }

    // 查询区间和
    int query(TreeNode node, int left, int right) {
        // 如果正好就是所求区间
        if (node.start == left && node.end == right)
            return node.sum;
        int mid = (node.end - node.start) / 2 + node.start;

        // 右边界都在左边,那就往左找
        if (right <= mid)
            return query(node.left, left, right);

        // 左边界都在右边,向右找
        if (left > mid)
            return query(node.right, left, right);

        // 一部分在左边,一部分在右边,需要分割
        return query(node.left, left, mid) +
                query(node.right, mid + 1, right);
    }

    // 更新线段树
    void update(TreeNode node, int index, int val) {
        // 找到叶子
        if (node.start == node.end) {
            node.sum = val;
            return;
        } else {
            int mid = (node.end - node.start) / 2 + node.start;
            if (index <= mid) {
                // 要更新的东西在左子树
                update(node.left, index, val);
            } else {
                // 要更新的东西在右子树
                update(node.right, index, val);
            }
            // 更新区间和
            node.sum = node.left.sum + node.right.sum;
        }
    }

    TreeNode root;

    public NumArray(int[] nums) {
        root = buildTree(nums, 0, nums.length - 1);
    }

    public void update(int index, int val) {
        update(root, index, val);
    }

    public int sumRange(int left, int right) {
        return query(root, left, right);
    }
}

public class RangeTree {
    public static void main(String[] args) {
        NumArray numArray = new NumArray(new int[] { 1, 3, 5 });
        System.out.println(numArray.sumRange(0, 2));
        numArray.update(1, 2);
        System.out.println(numArray.sumRange(0, 2));
    }
}