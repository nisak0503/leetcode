# Write your MySQL query statement below
SELECT name 
FROM customer
WHERE referee_id is null or referee_id != 2;


/*
1873ms, 91.59%

这里需要注意的是， null 只能用is和is not来表示

注意，这里的or不能换成UNION SELECT...
因为 referee_id != 2 本身选择出来的只有null的，为什么呢？***

下面是另一种方法，据说非常快 IFNULL
IFNULL 的用法是 IFNULL(expr1, expr2)
如果expr1不是NULL那么返回expr1，否则返回expr2
我觉得有点像 ：？表示法

这样子的速度反而更慢了
1871ms, 92.21%

*/
# Write your MySQL query statement below
SELECT name 
FROM customer
WHERE IFNULL(referee_id, 0) <> 2;