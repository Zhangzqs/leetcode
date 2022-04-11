/*
在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。

如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：

age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
否则，x 将会向 y 发送一条好友请求。

注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。

返回在该社交媒体网站上产生的好友请求总数。

示例 1：

输入：ages = [16,16]
输出：2
解释：2 人互发好友请求。
示例 2：

输入：ages = [16,17,18]
输出：2
解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
示例 3：

输入：ages = [20,30,100,110,120]
输出：3
解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。


提示：

n == ages.length
1 <= n <= 2 * 104
1 <= ages[i] <= 120
*/

fn num_friend_requests(ages: Vec<i32>) -> i32 {
    // 初始化各个年龄段的人数
    // 年龄取值为1~120，0下标不用，即开辟数组空间121
    let mut ages_num = vec![0; 121];
    ages.iter().for_each(|&age| {
        ages_num[age as usize] += 1;
    });

    (1..121)
        .filter(|&age| ages_num[age] > 0)
        // 计算所有年龄为x的人，发送的消息量
        .map(|x| -> i32 {
            let target_people_num = (1..=x)
                // 判断x是否向y发送消息
                .filter(|&y| {
                    let b1 = y <= x / 2 + 7;
                    let b2 = y > x;
                    let b3 = y > 100 && x < 100;
                    !(b1 || b2 || b3)
                })
                .map(|y| ages_num[y])
                .sum::<i32>();
            (target_people_num - 1) * ages_num[x]
        })
        .filter(|&count| count > 0)
        .sum()
}
fn main() {
    assert_eq!(num_friend_requests(vec![16, 16]), 2);
    assert_eq!(num_friend_requests(vec![16, 17, 18]), 2);
    assert_eq!(num_friend_requests(vec![20, 30, 100, 110, 120]), 3);
}
