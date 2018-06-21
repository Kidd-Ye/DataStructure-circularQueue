# DataStructure-circularQueue
A example of circular queue
<pre><code> const int QueueSize = 100;

class CircularQueue{
public:
    CircularQueue(){
        front = rear = 0;
    }
    ~CircularQueue(){ cout << "destroy" << endl;}
    
    void EnQueue(int x);
    int DeQueue();
    int GetQueue();
    bool Empty(){
        if (front == rear) {
            return true;
        }else return false;
    }
private:
    int data[QueueSize];
    int front, rear;
};

void CircularQueue::EnQueue(int x){
    if ((rear + 1) % QueueSize == front) {
        cout << "queue is full, can not insert" << endl;
    }else{
        rear = (rear + 1) % QueueSize;
        data[rear] = x;
    }
}

int CircularQueue::DeQueue(){
    if (Empty()) {
        cout << "queue is empty" << endl;
        return 0;
    }else{
        front = (front + 1) % QueueSize;
        return data[front];
    }
}

int CircularQueue::GetQueue(){
    if (Empty()) {
        cout << "queue is empty" << endl;
        return 0;
    }else{
        return data[(front + 1) % QueueSize];
    }
}</code></pre>
