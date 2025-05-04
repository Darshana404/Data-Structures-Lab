// Code for Lab7 - Q1
//To implement queue adt using array
#include<cstdio>
class queue{
    private:
        int arr[5];
        int front;
        int rear;
    public:
        queue(){
            front=-1;
            rear=-1;
        }
        bool isempty();
        bool isfull();
        void enqueue(int val);
        void dequeue();
        void peek();
};
bool queue::isempty(){
    return (front==-1 && rear==-1);
}
bool queue::isfull(){
    return (rear==4);
}
void queue::enqueue(int val){
    if(isfull()){
        printf("The list is full no more elements can be enqueued...\n");
        return;
    }
    rear++;
    arr[rear]=val;
    printf("%d has been enqueued..\n",val);
}

void queue::dequeue(){
    if(isempty()){
        printf("The list is empty...\n");
        return;
    }
    printf("Dequeued:%d",arr[front]);    
    if(front==rear){
        front=-1;
        rear=-1;
        return;
    }
    front++;  
}
void queue::peek(){
    if(isempty()){
        printf("The list is empty..\n");
        return;
    }
    printf("The peek element is:%d",arr[front]);
}
int main(){
    queue q;
    while(1){
        printf("\n------MENU-------\n");
        printf("1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.EXIT\n");
        int ch;
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                int val;
                printf("Enter the value:");
                scanf("%d",&val);
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                printf("Exiting..!\n");
                return 0;
            default:
                printf("Invalid choice..!\n");
                break;
        }
    }
}
