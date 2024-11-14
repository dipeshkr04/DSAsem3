#include<stdio.h>
#include<time.h>
void info(){
	time_t t;
	time(&t);
	printf("Harshit Srivastava\nBT23CSH051\n\n%s\n",ctime(&t));
	return;
}
void input(int A[], int n){
	printf("Enter elements...\n");
	for(int i=0;i<n;i++){
		printf("Enter element %d...",i+1);
		scanf("%d",&A[i]);
	}
	return;
}
void output(int A[], int n){
	for(int i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
	printf("\n");
	return;
}
void search(int A[], int n, int num){
	int flag=0;
	for(int i=0;i<n;i++){
		if(num==A[i]){
			flag=i+1;
		}
	}
	if(flag>0){
		printf("Number found and its position is %d.\n",flag);
	}
	else{
		printf("Number not found.\n");
	}
	return;
}
void large(int A[], int n){
	int l=A[0],s=0,t=0;
	for(int i=1;i<n;i++){
		if(l>s && l>t && l<A[i]){
			t=s;
			s=l;
			l=A[i];
		}
		else if(l>s && s>t && l>A[i] && s<A[i]){
			t=s;
			s=A[i];
		}
		else if(l>s && s>A[i] && s>t && t<A[i]){
			t=A[i];
		}
	}
	printf("Largest, second largest and third largest numbers are %d, %d and %d.\n",l,s,t);
	return;
}
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}
void sort(int A[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);
			}
		}
	}
	return;
}
void frequency(int A[], int n){
	for(int i=0;i<n;i++){
		int f=1;
		for(int j=1;j<n;j++){
			if(A[i]==A[j] && j!=i){
				f++;
			}
		}
		printf("Frequency of %d is %d\n.",A[i],f);
	}
	return;
}
void mode(int A[], int n){
	int temp=0,f,p=A[0];
	for(int i=0;i<n;i++){
		f=1;
		for(int j=1;j<n;j++){
			if(A[i]==A[j] && j!=i){
				f++;
			}
			if(f>temp){
				temp=f;
				p=A[i];
			}
		}
	}
	printf("Mode is %d.\n",p);
	return;
}
void reverse(int A[], int n){
	for(int i=0;i<n/2;i++){
		swap(&A[i],&A[n-i-1]);
	}
	return;
}
int main (){
	info();
	int n;
	printf("Enter no. of elements...");
	scanf("%d",&n);
	int A[n];
	input(A,n);
	printf("Entered array is...\n");
	output(A,n);

	//searching
	printf("Enter number to be searched...");
	int num;
	scanf("%d",&num);
	search(A,n,num);

	//large,2nd large, 3rd large
	large(A,n);

	//frequency
	frequency(A,n);

	//mode
	mode(A,n);

	//reverse
	reverse(A,n);
	printf("Reversed array is...\n");
	output(A,n);

	//sorted array
	sort(A,n);
	printf("Sorted array is...\n");
	output(A,n);
    
	return 0;
}