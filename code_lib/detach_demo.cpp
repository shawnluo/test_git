
/*
总结出以下结论：

1.主进程结束时（调用return/exit），子线程会随之结束。可以通过pread_exit退出进程而不杀掉其子线程。

2.用detach分离子线程和主进程，二者任意一个退出，整个进程（包括线程）都会结束。如果线程是正常结束（代码执行完毕或者调用了return），主进程不受影响。

3.在main函数中，如果不显示的调用return，编译器会自动给加一句return 0。
*/

#include <iostream>
#include <thread>
#include <unistd.h>
  
int main()
{
    std::thread my_thread([] {
        cout << "thread bye" << endl;
        exit(0); // 线程主动退出，此时，主进程会随之结束
        // return 0; //线程正常结束，主进程不受影响
    });
    this_thread::sleep_for(chrono::seconds(2));
    my_thread.detach();
    cout << "main bye" << endl;
}