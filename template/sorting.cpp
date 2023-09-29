#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bubbleSort(int *arr,int n);
void altSort(int *arr,int n);

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int& i : arr)
	{
		scanf("%d",&i);
	}

	altSort(arr,sizeof(arr)/sizeof(int));

	for (int i : arr)
	{
		printf("%d ",i);
	}
	
	return 0;
}
void bubbleSort(int arr[],int n){
	for(int i=0;i<n;i++){
		for (int j = 0; j < i; j++)
		{
			if (arr[i]<arr[j])
			{
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
}

void altSort(int arr[],int n){
	for (int i = 0; i < n; i++)
	{
		int min=arr[i];
		int ss=i;
		for (int  j = i+1; j < n; j++)
		{
			if (min>arr[j])
			{
				min=arr[j];
				ss=j;
			}
		}
		arr[ss]=arr[i];
		arr[i]=min;
	}
}