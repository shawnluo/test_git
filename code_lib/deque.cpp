void printQue(std::deque<int> que) {
    for(auto it : que) {
        cout << it << " ";
    }
    cout << endl;
}

int test() {
    std::deque<int> que;

    que.push_back(100);
    que.push_back(200);
    que.push_back(300);
    printQue(que);

    cout << que.front() << endl;

    que.pop_front();
    printQue(que);

    que.pop_back();
    printQue(que);

    return 0;
}