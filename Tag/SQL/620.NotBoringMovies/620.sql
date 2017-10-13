# Write your MySQL query statement below

SELECT * 

FROM cinema
WHERE (id % 2 = 1) AND description != 'boring'
ORDER BY rating desc;

/*
220ms, 15.48%

一旦把 % 换成 mod之后快了好多！！！

157ms, 90.75%
*/

# Write your MySQL query statement below

SELECT * 

FROM cinema
WHERE (mod(id, 2) = 1) AND description != 'boring'
ORDER BY rating desc;