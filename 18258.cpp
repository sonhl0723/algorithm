#include <iostream>
#include <cstring>
#include <string>

using namespace std;

typedef struct Queue{
    int data[2000000];
    int front, rear;
} Queue;

void init(Queue *q){
    q->front = -1;
    q->rear = -1;
}

int empty(Queue *q){
    if(q->front==-1 && q->rear==-1) return 1;
    else return 0;
}

void pop(Queue *q){
    if(!empty(q)){
        cout << q->data[q->front] << '\n';
        q->front = (q->front)+1;
        // if(q->front==-1) q->rear=-1;
        if(q->front > q->rear){
            q->front = -1;
            q->rear = -1;
        }
    }
    else cout << -1 << '\n';
}

void size(Queue *q){
    if(q->front!=-1) cout << (q->rear)-(q->front)+1 << '\n';
    else cout << 0 << '\n';
}

void front(Queue *q){
    if(!empty(q)){
        cout << q->data[q->front] << '\n';
    }
    else cout << -1 << '\n';
}

void back(Queue *q){
    if(!empty(q)){
        cout << q->data[q->rear] << '\n';
    }
    else cout << -1 << '\n';
}

void push(Queue *q, string input){
    if(!empty(q)){
        q->data[++(q->rear)] = stoi(input);
    }
    else{
        ++(q->front);
        ++(q->rear);
        q->data[q->front] = stoi(input);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    struct Queue q;
    int N;
    string command;

    cin >> N;
    cin.ignore();
    init(&q);

    while(N--){
        getline(cin, command);

        if(command.compare("pop")==0) pop(&q);
        else if(command.compare("size")==0) size(&q);
        else if(command.compare("empty")==0) cout << empty(&q) << '\n';
        else if(command.compare("front")==0) front(&q);
        else if(command.compare("back")==0) back(&q);
        else{
            if(command.length() >= 5) push(&q, command.substr(5));
            else return 0;
        }
    }
    
    return 0;
}