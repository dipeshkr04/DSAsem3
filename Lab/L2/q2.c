//selection sort on array

#include<stdio.h>
#include<stdlib.h>
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
void selection(int n, int A[]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j]){
                swap(&A[i],&A[j]);
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
    selection(n,A);
    printf("\nSorted Array...\n");
    output(n,A);
    return 0;
}