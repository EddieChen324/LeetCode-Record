class MyLinkedList {
public:
    //��������ڵ�ṹ��
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
        // index�Ǵ�0��ʼ�� 
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
        ////����ṹ��ǵø�nextָ�븳ֵ��������
        // ���ͷ�ڵ�ֻ�������ӵĽڵ��Լ�dummyhead����
        cur -> next = _dummyHead -> next;
        _dummyHead -> next = cur;
        _size++; 
    }
    
    void addAtTail(int val) {
        //newNode �����Ѿ�ָ��nullptr
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        // ֻ��ı�֮ǰ�����һ������ָ�򼴿�
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
        // ���¸��½ڵ��next��ֵ
        newNode->next = cur->next;
        // ����ָ���½ڵ�
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
        // �ҵ�Ҫɾ���Ľڵ�
        LinkedNode* tmp = cur->next;
        // ��Ҫɾ���Ľڵ��ǰһ������nextָ������ָ��
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
    // ��ӡ����
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