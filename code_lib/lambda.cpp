



#include "test.hpp"


https://www.jianshu.com/p/d686ad9de817


//   --- 1
// 定义简单的lambda表达式
auto basicLambda = [] { cout << "Hello, world!" << endl; };
// 调用
basicLambda();   // 输出：Hello, world!



//   --- 2
// 指明返回类型
auto add = [](int a, int b) -> int { return a + b; };
// 自动推断返回类型
auto multiply = [](int a, int b) { return a * b; };

int sum = add(2, 5);   // 输出：7
int product = multiply(2, 5);  // 输出：10


//   --- 3 引用捕捉
int main() {
    int x = 10;
    
    auto add_x = [x](int a) { return a + x; };  // 复制捕捉x
    auto multiply_x = [&x](int a) mutable { x += 1; return a * x; };  // 引用捕捉x
    
    cout << add_x(10) << " " << multiply_x(10) << endl;
    // 输出：20 100

    cout << x << endl;  // 因为用的是引用捕捉，x 变成 11

    return 0;
}


//   --- 3
int main() {
    int x = 10;
    
    // lambda表达式无法修改通过复制形式捕捉的变量, 因为函数调用运算符的重载方法是const属性的。
    // 有时候，你想改动传值方式捕获的值，那么就要使用mutable, 将函数调用运算符变成非const属性的：
    auto add_x = [x](int a) mutable { x *= 2; return a + x; };  // 复制捕捉x
    
    cout << add_x(10) << endl; // 输出 30
    return 0;
}


void test() {
    int i = 100;
    auto f = [&i] {return i;};
    i = 0;
    int j = f();
    cout << j << endl;
}

void func() {
	auto f = []() ->double {
		if (1 > 2)
			return 1;
		else 
			return 2.0;
	};
	std::cout << f() << std::endl;
}

int main(void) {
    test();

    return 0;
}






bool ransom4(string s, string t) {
    unordered_map<char, int> unmap;
    for(auto x : t) {
        unmap[x]++;
    }

    unordered_map<char, int>::iterator it;
    for(it = unmap.begin(); it != unmap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    std::for_each (
        unmap.begin(), 
        unmap.end(), 
        [](std::pair<char, int> p) {
            cout << p.first << " :: " << p.second << endl;
        }
    );
    return true;
}

int main(void) {
    string s = "abxx";
    string t = "abcxa";

    cout << ransom4(s, t) << endl;

    return 0;
}