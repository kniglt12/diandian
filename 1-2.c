#include<string.h>
#include<stdio.h>
#include<math.h> 
int a,b,c;
int main() {
	FILE* pf1 = fopen("in.txt", "r");
	FILE* pf2 = fopen("out.txt", "w");
	fscanf(pf1, "elevator %d", &c);
	fscanf(pf1, "%d %d", &a, &b);
	fprintf(pf2, "%d 0 0\n", c);
	fprintf(pf2, "%d %d 1\n", a, abs(a - c));
	fprintf(pf2, "%d %d 0\n", b ,abs(a - b) + abs(a - c));
	fclose(pf1);
	fclose(pf2);
	return 0;
}
