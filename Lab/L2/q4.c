// merge sort on array

#include<time.h>
#include<stdio.h>

void info(){
	time_t t;
	time(&t);
	printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n",ctime(&t));
	return;
}

void input(int n, int A[]){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("Enter element %d ... ",i+1);
        scanf("%d",&A[i]);
    }
    return;
}
void output(int n, int A[]){
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
    return;
}
void merge(int lb,int ub, int A[]){
    int i,j,k=0,mid=(lb+ub)/2;
    int B[ub-lb+1];
    i=lb;
    j=mid+1;
    while(i<=mid&&j<=ub){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
        }
        else{
            B[k]=A[j];
            j++;
        }
        k++;
    }
    while(j<=ub){
        B[k]=A[j];
        j++;
        k++;
    }
    while(i<=mid){
        B[k]=A[i];
        i++;
        k++;
    }
    for(int p=0;p<k;p++){
        A[p+lb]=B[p];
    }
    return;
}
void divide(int lb,int ub, int A[]){
    int mid=(lb+ub)/2;
    if(lb<ub){
        divide(lb,mid,A);
        divide(mid+1,ub,A);
        merge(lb,ub,A);
    }
    return;
}
int main (){
    info();
    int n;
    printf("Enter number of elements...");
    scanf("%d",&n);
    int A[n];
    printf("Enter elements...\n");
    input(n,A);
    printf("Entered array is...\n");
    output(n,A);
    divide(0,n-1,A);
    printf("Sorted array is...\n");
    output(n,A);
    return 0;
}