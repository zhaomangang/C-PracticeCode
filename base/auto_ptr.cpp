#include <memory>
#include <iostream>
using namespace std;

class Point {
public:
    Point(int x,int y)
    {
        pos_x = x;
        pos_y = y;
    }
    ~Point()
    {
        cout<<"this is 析构函数\n";
    }
private:
    int pos_x;
    int pos_y;
};

int main()
{
    auto_ptr<Point> p(new Point(2,3));

    return 0;
}
