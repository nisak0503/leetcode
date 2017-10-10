class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0, horizon = 0;
        for(int i = 0; i < moves.size(); ++i)
        {
            switch(moves[i])
            {
                case 'U': vertical++; break;
                case 'D': vertical--; break;
                case 'L': horizon++; break;
                case 'R': horizon--; break;
                default:;
            }
        }
        return (vertical == 0 && horizon == 0);
    }
};

/*
22ms, 31.99%

下面这个改了for循环：
19ms, 42.16% !!!原来还可以这样写啊！
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0;
        int h = 0;
        for (char ch : moves) {
            switch (ch) {
                case 'U' : v++; break;
                case 'D' : v--; break;
                case 'R' : h++; break;
                case 'L' : h--; break;
            }
        }
        return v == 0 && h == 0;
    }
};