# Write your MySQL query statement below

SELECT x, y, z, 
case when x+y>z and x+z>y and z+y>x then "Yes"
else "No"
end as "triangle"
from triangle;

/*
480ms

46.53%
这个case when then else end as真是神器啊！
*/