#include <stdio.h>
int main(){
int i,j;
int k=0;
int arr[5][5];

for(i=1;i<=4;i++){

    for(j=1;j<=5;j++){
    	if(j==1)
		//printf("%d", j);
		arr[i-1][j-1]=j;
		else
		//printf("%d", j+k);
		arr[i-1][j-1]=j+k;
		printf("%d", arr[i-1][j-1]);
    }
    k=k+2;
    printf("\n");
}

return 0;
}






#include <stdio.h>
int main(){
int i,j;
int k=0;
int arr[5][5];

for(i=1;i<=4;i++){

    for(j=1;j<=5;j++){
    	if(j==1)
		//printf("%d", j);
		arr[i-1][j-1]=j;
		else
		//printf("%d", j+k);
		arr[i-1][j-1]=j+k;
		printf("%d", arr[i-1][j-1]);
    }
    k++;
    printf("\n");
}

return 0;
}
