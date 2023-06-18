#include<stdio.h>
#include<stdlib.h>
int main(){
    float a[6] = {5.6f, 2.3f, 1.0f, 4.5f, 3.2f, 6.7f};
    float max1 = a[0];
	int max_index1 = 0;
	float max2 = a[1];
	int max_index2 = 1;
	for (int i = 0; i < 6; i++) {
			if (a[i] > max1) {
        max2 = max1;
        max_index2 = max_index1;
        max1 = a[i];
        max_index1 = i;
				} 
			else if (a[i] > max2) {
        max2 = a[i];
        max_index2 = i;
				}
			}
    printf("%f %d %f %d",max1,max_index1,max2,max_index2);
    }