// 算法思想：
// 定义一个指针cur，指向当前没有重复元素的那部分的下一个元素，pre指向cur的前驱，
// 比如2→3→2→5→4→3→7→6→7为当前链表的形状，刚开始cur指向3，pre指向2，定义一个工作指针runner，每次从head开始向后扫描，
// 扫描到cur就退出循环，
//      如果在到cur之前遇到一个节点的值与cur指向节点的值相同，
//          那么删除cur指向节点!!! --- important!
//          跳出循环（确保runner遍历过的范围无重复值），
//          又开始从头一轮循环来查找被更新的cur，
//              注意！此时cur已经变成cur->next了！
//              所以，不能更新当前的节点和前驱。
//      如果扫描到cur的时候才停止循环，说明前面没有重复的节点，
//          更新当前节点和它的前驱：pre = cur; cur = cur->next;

void delD(pNode pHead) {
    if(pHead == nullptr) return;

    pNode pre = pHead;
    pNode cur = pre->next;
    while(cur != nullptr) {
        pNode runner = pHead;
        while(runner != cur) {
            if(runner->data == cur->data) {
                pre->next = cur->next;
                pNode tmp = cur;
                cur = cur->next;
                free(tmp);
                break;
            }
            runner = runner->next;
        }
        if(runner == cur) {
            pre = cur;
            cur = cur->next;
        }
    }
}
