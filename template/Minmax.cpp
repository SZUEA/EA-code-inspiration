#include <cstdio>
#include <math.h>
void solution1(int m,int k, int *arr);
int solution2(int size,int *arr);
int main() {
//	int arr[]= {1,2,3,4,5,6,7,8,9};
//	solution(9,2,arr);
	int a;
	scanf("%d",&a);
	int b[a];
	for(int i=0;i<a;i++){
		scanf("%d",&b[i]);
	}
	printf("%d",solution2(a,b));
	
}            

int solution2(int size,int arr[]){
	float a=0.0,b=0.0;
	for(int i=0;i<size;i++){
		a=fmax(0.0,a+arr[i]);
		b=fmax(a,b);
	}
	return (int) b;
}

/*

1.sum			45
2.arrange 		1 2 3 4 5 | 6 7 | 8 9
3.ultimize

*/
void solution1(int m,int k, int arr[]) {
	int sum=0,in=0,ind=1;
	for(int i=0; i<m; i++) {
		sum+=arr[i];
	}
	for(int i=0; i<=m; i++) {
		in+=arr[i];
		if(sum/k<=in) {
			in=0;
			printf("%d %d\n",ind, i);
			ind=i+1;
		} else if(i==m) {
			printf("%d %d",ind, i);
		}
	}
}




