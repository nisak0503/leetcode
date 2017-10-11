class Solution {
public:
    int findComplement(int num) {
        int k = (int) (log(num)/log(2)) + 1;
        return num ^ (pow(2, k) - 1);
    }
};

/*
6ms 3.13%

这也太慢了吧！！

搜出来的方法， 任何数和11111...1异或，得到的就是他的反码


以下的方法 3ms 24.13%

无符号mask = ~0 也就是全部都是1
一直做 num & mask， 让mask 左移1，后面补0 
直到num & mask 等于0
也就是说 前面mask为1的部分全是0了，后面mask也全是0了

然后给mask取反，相当于前面全是0，后面全是1
和num取反，前面全是1，后面反过来。
进行与操作，相当于得到了后面的部分。

num          = 00000101
mask         = 11111000
~mask & ~num = 00000010
*/

class Solution {
public:
    int findComplement(int num) {
        unsigned k = ~0;
        while(num & k) k = k << 1;
        return ~k & ~num;
    }
};