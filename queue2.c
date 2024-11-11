#include<stdio.h>
#define MAX_SIZE 100
#define maxsize 10
int rear = -1;
int front = -1;
int n;
int queue[MAX_SIZE];
int cirqueue[maxsize];
int front1 = 0;
int rear1 = 0;

void insert(){
	if(rear == MAX_SIZE-1){
		printf("queue is full\n");
	}
	else{
		printf("enter the element \n");
		scanf("%d",&n);
			if (front == -1) {  // Set front to 0 if it's the first element
            			front = 0;
        		}
		rear = rear+1;
		queue[rear] = n;
	}
}

int delete1(){
	if(rear == front){
		printf("queue is empty\n");
	}
	else{
		
		n = queue[front];
		front = front+1;
		return n;
	}
}

void display(){
	if(rear == front){
		printf("queue is empty\n");
	}
	else{
	printf("queue element is \n");
		for(int i=rear ; i>=front ;i--){
			printf("%d\t",queue[i]);
		}
	}
}

void cirinsert(){
	if((rear1 + 1)% maxsize == front1){
		printf("cirular queue is full \n");
	}
	else{
		printf("enter the element \n");
		scanf("%d",&n);
		rear1 = (rear1 + 1)% maxsize;
		cirqueue[rear1] = n;
	}
}

int cirdelete(){
	if(front == rear){
		printf("circular queue is empty \n");
	}
	else{
		front = (front + 1)% maxsize;
		n = cirqueue[front];
		return n;
	}
}

void cirdisplay(){
	if(rear == front){
		printf("circular queue is empty \n");
	}
	else{
	printf("element of this queue is \n");
		for(int i= front;i!=rear ;i=(i+1)%maxsize){
			printf("%d",cirqueue[i]);
		}
	}
}

int main(){
	int choice,q=1;
	while(1){
		printf("==========	    queue operation		==========	\n");
		printf("\n");
		printf("1. insert \n");
		printf("2. display \n");
		printf("3. delete \n");
		printf("4. cirular insert \n");
		printf("5. circular display \n ");
		printf("6. circular delelte \n");
		printf("7. exit \n");
	 	printf("\n");
	 	printf("enter your choice \n");
	 	scanf("%d",&choice);
	 	
	 	switch(choice){
	 		case 1: insert();
	 			break;
	 		case 2: display();
	 			break;
	 		case 3: delete1();
	 			break;
			case 4: cirinsert();
				break;
			case 5: cirdisplay();
				break;
			case 6: cirdelete();
				break;		
	 		case 7: printf("exiting......");
	 			return 0;
	 		default : printf("invalid option \n");
	 			break;					
	 	}
	}
return 0;
}
