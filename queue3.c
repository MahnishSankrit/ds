#include<stdio.h>
#define max_size 10
int q[max_size];
 
struct queue{
	int pid;
	int at;
	int et;
};
int front = -1;
int rear = -1;
int elem,elem1;
int isempty(){
	if(rear==front){
		return 1;
	}
	else{
		return 0;
	}
}

int isfull(){
	if(rear = max_size - 1){
		return 1;
	}
	else{
		return 0;
	}
}

void enqueue(struct queue q[],int n){
	if(isfull()){
		printf("queue is full\n");
	}
	else{
		printf("enter the arrival time and execution time\n");
		scanf("%d%d",&elem,&elem1);
		rear = rear+1;
		q[rear].at = elem;
		q[rear].et = elem1; 
		 for (int i = 0; i <n; i++) {
            printf("%d\t\t%d\n", q[i].pid, q[i].et);
        }	
	}
}

void dequeue(struct queue q[],int n){
	if(isempty()){
		printf("queue is empty\n");
	}
	else{
		printf("job is removed\n");
		front = front +1;
		for(int i;i<n;i++){
			printf("%d\t%d\n",q[i].at,q[i].et);
		}
	}
}

//void accept(struct queue q[],int n){
//	printf("enter the arrival time and execution time \n");
//	for(int i = 0;i<n;i++){
//		printf("pid %d",i+1);
//		scanf("%d%d",&q[i].at,q[i].et);
//	}
//}

int main(){
	struct queue q[10];
	
	int n;
	printf("enter th number of jobs\n");
	scanf("%d",&n);
	enqueue(q,n);
	dequeue(q,n);

return 0;
}
