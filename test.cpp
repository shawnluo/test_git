#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;


int dp_11(vector<int>& weight, vector<int>& value, int BAG) {
    vector<vector<int>> dp(weight.size(), vector<int>(BAG + 1, 0));

    return 0;
}

int main(void) {
    shared_ptr<string> pa(new string("CHN"));
    shared_ptr<string> pb(new string("USA"));

    cout << "*pa: " << *pa << endl;
    cout << "pa.use_count: " << pa.use_count() << endl; // 1

    cout << "*pb: " << *pb << endl;
    cout << "pb.use_count: " << pb.use_count() << endl; // 1

    pa = pb;
    cout << *pa << endl;
    cout << pa.use_count() << endl; // 2：pa 和 pb指向同一个资源 USA了，该资源的计数为2，所以pb、pb都输出2
    cout << pb.use_count() << endl;

    pa.reset();
    pb.reset();
    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;

    /* 
        下面是不合法的:
        p1 和 p2 并不会共享同一个对p的托管计数。而是各自将对p的托管技术都记为1，因为 p2 无法知道 p 已经被 p1 托管过。
        这样，当 p1 消亡时要析构 p，p2 消亡时要再次析构 p，这会导致程序崩溃。
     */
    string* p = new string("abc");
    // shared_ptr<string> p1(p), p2(p);
    shared_ptr<string> p1(p);
    shared_ptr<string> p2(p);

    return 0;
}