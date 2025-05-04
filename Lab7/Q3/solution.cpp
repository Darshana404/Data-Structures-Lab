// Code for Lab7 - Q3
//Implement queue adt using linked list

#include<cstdio>
#include<cstdlib>

struct node{
    int data;
    struct node *next;
};

class queue{
    private:
        struct node *front;
        struct node *rear;
    public:
        queue(){
            front=NULL;
            rear=NULL;
        }
    bool isempty();
    void enqueue(int val);
    void peek();
    void dequeue();
};

bool queue::isempty(){
    return front==NULL;
}
void queue::enqueue(int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    if(front==NULL){
        front=rear=newnode;
    }else{
        rear->next=newnode;
        rear=newnode;
    }
    printf("The element was enqueued successfully..\n");
}
void queue::dequeue(){
    if(isempty()){
        printf("The list is empty..\n");
        return;
    }
    struct node *temp=front;
    printf("Dequeued:%d",front->data);
    front=front->next;
    free(temp);
    if(front==NULL){
        rear=NULL;
    }
}
void queue::peek(){
    if(isempty()){
        printf("The list is empty..\n");
    }else{
        printf("Peek is:%d\n",front->data);
    }
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
