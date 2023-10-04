void test_cast() {
    int i = 10, j = 2;
    double x = static_cast<double>(j) / i;
    cout << x << endl;

    cout << j / i << endl;
}

/*
dynamic_cast<type>(expression)
相比static_cast，dynamic_cast会在运行时检查类型转换是否合法，
具有一定的安全性。由于运行时的检查，所以会额外消耗一些性能。
dynamic_cast使用场景与static相似，在类层次结构中使用时，
上行转换和static_cast没有区别，都是安全的；下行转换时，
dynamic_cast会检查转换的类型，相比static_cast更安全。

dynamic_cast转换仅适用于指针或引用。

在转换可能发生的前提下，dynamic_cast会尝试转换，若指针转换失败，则返回空指针，
若引用转换失败，则抛出异常。
*/