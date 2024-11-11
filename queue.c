#include<stdio.h>

struct queue{
	int pid;
	int at;
	int et;
	int wt;
	int tat;
	
};

void accept(struct queue q[],int n){
	int i;
	printf("enter the arrival time and execution time \n");
	for(i=0;i<n;i++){
		printf("job %d",i+1);
		scanf("%d%d",&q[i].at,&q[i].et);
		q[i].wt = 0;
		q[i].tat = 0;
		q[i].pid = i+1;
	}
}

void display(struct queue q[],int n){
	int i;
	printf("pid\tat\tet\twt\ttat\n");
	for(i=0;i<n;i++){
	printf("%d\t%d\t%d\t%d\t%d\n",q[i].pid,q[i].at,q[i].et,q[i].wt,q[i].tat);
	}
}

void insort(struct queue q[],int n){
	int i,j;
	struct queue sort;
	for(i=i;i<n;i++){
	sort = q[i];
	j = i-1;
		while(j>=0 && q[j].at>sort.at){
			q[j+1] =q[j];
			j = j-1;
		}
		q[j+1] = sort;
	}
}

void job_sch(struct queue q[],int n){
	int current_time = 0;
	for(int i = 0;i<n;i++){
		if(q[i].at>current_time){
			current_time = q[i].at;
		}
		current_time += q[i].et;
		q[i].tat = current_time - q[i].at;
		q[i].wt = q[i].tat - q[i].et;
	}
}

int main(){
	int n,choice;
	struct queue q[10];
	printf("enter the number of jobs\n");
	scanf("%d",&n);
	
	while(1){
		printf("=====================		job_sch		=====================\n");
		printf("1. accept  \n");
		printf("2. display \n");
		printf("3. insort  \n");
		printf("4. job_sch \n");
		printf("5. exit \n");
		
		printf("enter your choice \n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: accept(q,n);
				break;
			case 2: display(q,n);
				break;
			case 3: insort(q,n);
				printf("by sorting");
				display(q,n);
				break;
			case 4: job_sch(q,n);
			,,]\	display(q,n);
				break;
			case 5: printf("exiting..........\n");
				return 0;
			default : printf("invalid option ");
				  break;					
		}
	}	

return 0;
}
