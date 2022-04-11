use std::{cell::RefCell, ops::Deref, rc::Rc};

struct TreeNode {
    start: i32,
    end: i32,
    sum: i32,
    left: Rc<RefCell<Option<TreeNode>>>,
    right: Rc<RefCell<Option<TreeNode>>>,
}

impl TreeNode {
    fn new() -> Self {
        Self {
            start: 0,
            end: 0,
            sum: 0,
            left: Rc::new(RefCell::new(None)),
            right: Rc::new(RefCell::new(None)),
        }
    }
}

fn buildTree(nums: &Vec<i32>, start: i32, end: i32) -> Rc<RefCell<Option<TreeNode>>> {
    let mid = (end - start) / 2 + start;
    let mut root = TreeNode::new();
    root.start = start;
    root.end = end;
    if start < end {
        root.left = buildTree(&nums, start, mid);
        root.right = buildTree(&nums, mid + 1, end);
        root.sum =
            root.left.borrow().as_ref().unwrap().sum + root.right.borrow().as_ref().unwrap().sum;
    } else if start == end {
        root.left = Rc::new(RefCell::new(None));
        root.right = Rc::new(RefCell::new(None));
        root.sum = nums[start as usize];
    }
    Rc::new(RefCell::new(Some(root)))
}

// 查询区间和
fn query(node: &Rc<RefCell<Option<TreeNode>>>, left: i32, right: i32) -> i32 {
    let a = node.borrow();
    let node = a.as_ref().unwrap();
    // 如果正好就是所求区间
    if node.start == left && node.end == right {
        return node.sum;
    }
    let mid = (node.end - node.start) / 2 + node.start;

    // 右边界都在左边,那就往左找
    if right <= mid {
        return query(&node.left, left, right);
    }

    // 左边界都在右边,向右找
    if left > mid {
        return query(&node.right, left, right);
    }

    // 一部分在左边,一部分在右边,需要分割
    query(&node.left, left, mid) + query(&node.right, mid + 1, right)
}

// 更新线段树
fn update(node: &mut Rc<RefCell<Option<TreeNode>>>, index: i32, val: i32) {
    let mut a = node.borrow_mut();
    let node = a.as_mut().unwrap();
    // 找到叶子
    if node.start == node.end {
        node.sum = val;
        return;
    } else {
        let mid = (node.end - node.start) / 2 + node.start;
        if index <= mid {
            // 要更新的东西在左子树
            update(&mut node.left, index, val);
        } else {
            // 要更新的东西在右子树
            update(&mut node.right, index, val);
        }

        let d = node.left.borrow().as_ref().unwrap().sum;
        let e = node.right.borrow().as_ref().unwrap().sum;
        node.sum = d + e;
    }
}

struct NumArray {
    root: Rc<RefCell<Option<TreeNode>>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {
    fn new(nums: Vec<i32>) -> Self {
        Self {
            root: buildTree(&nums, 0, nums.len() as i32 - 1),
        }
    }

    fn update(&mut self, index: i32, val: i32) {
        update(&mut self.root, index, val);
    }

    fn sum_range(&mut self, left: i32, right: i32) -> i32 {
        query(&mut self.root, left, right)
    }
}

fn main() {
    println!("Hello, world!");
}
