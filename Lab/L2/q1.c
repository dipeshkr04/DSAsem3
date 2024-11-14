//bubble sort on array
#include<stdio.h>
#include<time.h>
void info(){
	time_t t;
	time(&t);
	printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n",ctime(&t));
	return;
}

void input(int n, int A[]){
    printf("Enter %d elements...\n",n);
    for(int i=0;i<n;i++){
        printf("\nEnter %d element...",i+1);
        scanf("%d",&A[i]);
    }
    return;
}
void output(int n, int A[]){
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
    return;
}
void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
    return;
}
void bubble(int n, int A[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                swap(&A[j+1],&A[j]);
            }
        }
    }
    return;
}
int main (){
    info();
    int n;
    printf("Enter no. of elements...");
    scanf("%d",&n);
    int A[n];
    input(n,A);
    printf("Array lements are...\n");
    output(n,A);
    bubble(n,A);
    printf("\nSorted Array...\n");
    output(n,A);
    return 0;
}