#include<stdio.h>
#include<stdlib.h>
void input(int a[], int n)
{
	int i;
	printf("enter the value \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void merge(int a[], int lb,int mid, int ub)
{
	int i=lb,j=mid+1,k=lb, c[50];
	while(i <= mid && j <= ub)
	{
		if(a[i] < a[j])
		{
			c[k++]=a[i];
			i++;
		}
		else if(a[i] > a[j])
		{
			c[k++] = a[j];
			j++;
		}
	}
	while(i<=lb)
	{
		c[k++] = a[i++];
	}
	while(j <= ub)
	{
		c[k++] = a[j++];
	}
	for(i = lb; i <= ub; i++)
		a[i] = c[i];
}
void mergeSort(int a[], int lb,int ub)
{
	int mid;
	if(lb < ub)
	{
		mid = (lb + ub) / 2;
		mergeSort(a, lb, mid);
		mergeSort(a, mid + 1, ub);
		merge(a, lb, mid, ub);
	}
}

void display(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int a[50];
	int n;
	printf("enter the value of n : ");
	scanf("%d",&n);
	input(a, n);
	printf("Before Sorting : \n");
	display(a, n);
	mergeSort(a, 0, n - 1);
	printf("After Sorting : \n");
	display(a, n);
}
