//input 10 students marks and functionsssss
#include <stdio.h>
void create_Mark(int a[],int n){
    int i;
    printf("Enter the marks secured by the students:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void display_Mark(int a[],int n){
    int i;
    printf("The marks secured by the students:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void max_Mark(int a[],int n){
    int i,m;
    m=a[0];
    for(i=0;i<n;i++){
        if(a[i]>m){
            m=a[i];
        }
    }
    printf("\nThe maximum marks:%d",m);
}
void min_Mark(int a[],int n){
    int i,m;
    m=a[0];
    for(i=0;i<n;i++){
        if(a[i]<m){
            m=a[i];
        }
    }
    printf("\nThe minimum marks:%d",m);
}
void sum_Mark(int a[],int n){
    int i,sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
        }
        printf("\nThe sum of the marks:%d",sum);
    }
void avg_Mark(int a[],int n){
    int i,sum=0,avg;
    for(i=0;i<n;i++){
        sum+=a[i];
        }
        avg=sum/n;
        printf("\nThe average of the marks is %d",avg);
    }
int main(){
    int a[100],n;
    printf("Enter the number of students:");
    scanf("%d",&n);
    create_Mark(a,n);
    display_Mark(a,n);
    max_Mark(a,n);
    min_Mark(a,n);
    sum_Mark(a,n);
    avg_Mark(a,n);
    return 0;
}
