#include<stdio.h>

struct student{
	char name[10];
	int roll;
};
void create(struct student arr[],int n){
	printf("enter the student details \n");
	for(int i =0 ;i<n;i++){
		scanf("%s %d",arr[i].name,&arr[i].roll);
	}
}

void display(struct student arr[], int n){
	printf("the student details are\n");
	printf("name\troll\n");
	for(int i =0;i<n;i++){
		printf("%s\t%d\n",arr[i].name,arr[i].roll);
	}
}

void bubblesort(struct student arr[],int n){
	struct student temp;
	for(int i =0;i<n-1;i++){
		for(int j = 0 ; j<n-i-1;j++){
			if(arr[j].roll>arr[j+1].roll){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
			}
		}
	}
}

void selectsort(struct student arr[],int n){
	int minpos;
	struct student temp;
	for(int i = 0;i<n-1;i++){
		minpos = i;
		for(int j =i+1;j<n;j++ ){
			if(arr[j].roll<arr[minpos].roll){
				minpos = j;
			}
		}
		if(minpos != i){
			temp = arr[i];
			arr[i] = arr[minpos];
			arr[minpos] = temp;
		}
	}
}

void insertionsort(struct student arr[], int n){
	struct student key;
	for(int i = 0;i<n;i++){
		key = arr[i];
		int j = i-1;
		while(j>= 0 && arr[j].roll>arr[j+1].roll){
			arr[j+1].roll = arr[j].roll;
			j = j-1;
		}
		arr[j+1] = key;
	}
}

void shellsort(struct student arr[], int n){
	int gap,j;
	struct student temp;
	for(gap = n/2; gap > 0;gap = gap/2){
		for(int i = gap;i<n;i++){
			temp = arr[i];
			for( j = i;j>= gap && arr[j-gap].roll>temp.roll;j =j-gap){
				arr[j] = arr[j-gap];
			}
			arr[j] = temp;
		}
	}
}

int main(){
	struct student arr[10];
	int n;
	printf("enter the number of the student\n");
	scanf("%d",&n);
	int choice;
	
	while(1){
		printf("1.create\n");
		printf("2.display\n");
		printf("3.bubble\n");
		printf("4.select\n");
		printf("5.insert\n");
		printf("6.shell\n");
		printf("7.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: create(arr,n);
				break;
			case 2: display(arr,n);
				break;
			case 3: bubblesort(arr, n);
				break;
			case 4: selectsort(arr,n);
				break;
			case 5: insertionsort(arr,n);
				break;
			case 6: shellsort(arr,n);
				break;
			case 7: printf("exiting......\n");
				return 0;
			default : printf("invalid option\n");							
				break;
		}
	}
	return 0;
	
}
