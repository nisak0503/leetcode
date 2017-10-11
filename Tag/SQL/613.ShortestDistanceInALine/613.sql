# Write your MySQL query statement below
SELECT min(shortest) AS shortest
FROM
(
SELECT (A.x - B.x) AS shortest
FROM point A, point B
WHERE A.x > B.x
) AS C;

/*
779ms, 8.42% 
非常慢了啦
写的时候就在想，为什么不直接就用一个select呢
685ms, 51.49%

可以明显看出nested sql非常非常慢了
*/

SELECT min(A.x - B.x) AS shortest
FROM point A, point B
WHERE A.x > B.x;

/*
使用ABS的话好像也不快啊
727ms, 22.28%
*/

# Write your MySQL query statement below

SELECT min(abs(A.x - B.x)) AS shortest
FROM point A JOIN point B
WHERE A.x > B.x;
