//
//  main.cpp
//  CircularQueue
//
//  Created by kidd on 2018/6/21.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
using namespace std;
const int QueueSize = 100;

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
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, CircularQueue!\n";
    
    CircularQueue Q;
    Q.EnQueue(1);
    Q.EnQueue(2);
    Q.EnQueue(3);
    Q.EnQueue(4);
    
    cout << Q.DeQueue() << endl;
    cout << Q.DeQueue() << endl;
    cout << Q.DeQueue() << endl;
    cout << Q.DeQueue() << endl;
    cout << Q.DeQueue() << endl;
    cout << Q.DeQueue() << endl;
    cout << Q.GetQueue() << endl;
    return 0;
}
