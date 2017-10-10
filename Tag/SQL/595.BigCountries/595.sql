# Write your MySQL query statement below
SELECT w.name, w.population, w.area
FROM World w
WHERE w.area > 3000000 OR w.population > 25000000;

# 20.14%
# 虽然一次过的，但是好像特别慢？

# 答案中说 UNION 比较快

SELECT w.name, w.population, w.area
FROM World w
WHERE w.area > 3000000 

UNION
SELECT w.name, w.population, w.area
FROM World w
WHERE w.population > 25000000;
#14.17% ???

#但是我把w全部去掉之后。。85.16%!!!!!


SELECT name, population, area
FROM World
WHERE area > 3000000 

UNION
SELECT name, population, area
FROM World 
WHERE population > 25000000;

#然后我对第一种方法也去掉了w, 85.50%! 不懂。。
SELECT name, population, area
FROM World 
WHERE area > 3000000 OR population > 25000000;