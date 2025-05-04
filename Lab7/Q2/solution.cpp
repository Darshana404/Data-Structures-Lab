// Code for Lab7 - Q2
//Implement circular queue adt using array
#include<cstdio>
class cirqueue{
    private:
        int arr[5];
        int front;
        int rear;
    public:
        cirqueue(){
            front=-1;
            rear=-1;
        }
        bool isempty();
        bool isfull();
        void enqueue(int val);
        void dequeue();
        void peek();
};
bool cirqueue::isempty(){
    if(front==-1 && rear==-1){
        return true;
    }
    return false;
}
bool cirqueue::isfull(){
    if((rear+1)%5==front){
        return true;
    }
    return false;
}
void cirqueue::enqueue(int val){
    if(isfull()){
        printf("The list is full no more element can be enqueued..\n");
        return;
    }
    if(front=-1){
        front=0;
    }
    int Rear=(rear+1)%5;
    arr[rear]=val;
    printf("Enqueued:%d",val);
}
void cirqueue::dequeue(){
    if(isempty()){
        printf("The list is empty..\n");
        return;
    }
    printf("Dequeued:%d\n",arr[front]);
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
        int Front=(front+1)%5;
    }   
}
void cirqueue::peek(){
    if(isempty()){
        printf("The list is empty...\n");
        return;
    }
    printf("The peek element is:%d",arr[front]);
}
int main(){
    cirqueue q;
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
