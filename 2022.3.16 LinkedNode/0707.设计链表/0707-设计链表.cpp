class MyLinkedList {
public:
    //定义链表节点结构体
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int x): val(x), next(nullptr) {}
    };
    MyLinkedList() {
         _dummyHead = new LinkedNode(0);
         _size = 0;
    }
    
    int get(int index) {
        // index是从0开始的 
        if (index > _size - 1 || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur -> next;
        }
        cur = cur -> next;
        return cur -> val;
    }
    
    void addAtHead(int val) {
        LinkedNode* cur = new LinkedNode(val);
        ////申请结构体记得给next指针赋值！！！！
        // 添加头节点只需更改添加的节点以及dummyhead即可
        cur -> next = _dummyHead -> next;
        _dummyHead -> next = cur;
        _size++; 
    }
    
    void addAtTail(int val) {
        //newNode 本身已经指向nullptr
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        // 只需改变之前的最后一个结点的指向即可
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
       if (index > _size) {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        // 重新给新节点的next赋值
        newNode->next = cur->next;
        // 让它指向新节点
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        // 找到要删除的节点
        LinkedNode* tmp = cur->next;
        // 给要删除的节点的前一个结点的next指针重新指向
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    private:
    int _size;
    LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */