class MyCircularQueue {
public:
    int * arr;
    int size;
    int front;
    int rear;
    MyCircularQueue(int k) {
        this -> size = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }
    
    ~MyCircularQueue() {
        delete[] arr;
    }

    bool enQueue(int value) {
        // overflow 
        if((rear + 1) % size == front){
            return false;
        }
        // single element 
        else if(front == -1 ){
            front++;
            rear++;
        }
        // circular behaviour
        else if(front!= 0 && rear == size-1){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        // logic : remove is done from front index 
        // underflow
        if(front == -1){
            return false;
        }
        // signle element
        else if(front == rear ){
            arr[front] = -1;
            front = -1;
            rear =-1;
        }
        else if(front == size-1){
            // circular bevaiour
            front = 0;
        }else{
            arr[front] == -1;
            front++;
        }
        return true;
    }
    
    int Front() {
        if(front == -1){
            return -1;
        }else{
            return arr[front];
        }
    }
    
    int Rear() {
           if(rear == -1){
            return -1;
        }else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(front == -1){
            return true;
        }else{
            return false;
        }
        
    }
    
    bool isFull() {
          if((rear + 1) % size == front){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */