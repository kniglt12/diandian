#include<string.h>
#include<stdio.h>
#include<math.h> 
int main() {
	int a, b, c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d 0 0\n", c);
	printf("%d %d 1\n", a, abs(a - c));
	printf("%d %d 0\n", b ,abs(a - b) + abs(a - c));
	return 0;
}
