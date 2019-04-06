#include <math.h>
#include<stdio.h>
int main()
{
	int t,j,k,maxx;
	scanf("%d",&t);
	while(t--){
		int num;
		scanf("%d",&num);
		//Edge case
		int flag = 0;

		int numA[num];
		for( j = 0; j < num; j++){
			scanf("%d",&numA[j]);
		}

		if(num == 1){
			printf("NO\n");;
			continue;
		}

		for( j = 0; j < (num - 1); j++){
			for( k = j+1; k < num; k++){
				int div = 2;
                if(numA[k]>numA[j]) maxx=numA[k];
                else  maxx=numA[j];
				while(div <= maxx){
					if((numA[k] % div == 0) && (numA[j] % div == 0)){
						flag = 1;
						break;
					}
					if(div == maxx){
						flag = 0;
					}
					div++;
				}
			}

			if(!flag){
				printf("YES\n");
				break;
			}
		}

		if(flag){
                printf("NO\n");
		}
	}

	return 0;
}
