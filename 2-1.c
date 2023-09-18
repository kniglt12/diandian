#include<string.h>
#include<stdio.h>

int num, top, bu, s[10000], e[10000], t[100000];
int up[100000];
int qs[10000], qe[10000];
int elenow, eled, elenum, ele[5];
int cou;
void update(int ti) {
	for (int i = 1; i <= num; i++) {
		if (t[i] == ti) {
			bu++;
			qs[bu] = s[i];
			qe[bu] = e[i];
			if (e[i] > s[i])
				up[bu] = 1;
			else
				up[bu] = -1;
		}
	}
}
void swapint(int* a, int* b) {
	int c;
	c = *b;
	*b = *a;
	*a = c;
}
int main() {
	FILE* pf1 = fopen("in.txt", "r");
	FILE* pf2 = fopen("out.txt", "w");
	fscanf(pf1, "elevator %d", &elenow);
	num = 0;
	while (!feof(pf1)) {
		num++;
		fscanf(pf1, "%d %d %d", &s[num], &e[num], &t[num]);

	}
	int ti = 1;
	top = 1;
	update(0);
	update(1);
	fprintf(pf2, "%d 0 0\n", elenow);
	while (1) {

		//cout << top<<" "<<bu <<" "<<eled << endl;
		//cout<<"!!!" << eled << " " << ti << " " << elenow << endl;
		for (int i = 1; i <= 4; i++) {
			if (ele[i] == elenow) {
				ele[i] = 0;
				elenum--;
				fprintf(pf2, "out %d %d %d\n", elenow, ti, elenum);
				cou++;
			}
		}
		for (int i = top; i <= bu; i++) {
			//cout << "sadadad";
			if (elenum == 4)
				break;
			if (qs[i] == elenow) {
				if (elenum == 0) {
					for (int j = 1; j <= 4; j++) {
						if (ele[j] == 0) {
							ele[j] = qe[i];
							elenum++;
							eled = up[i];
							fprintf(pf2, "in %d %d %d\n", elenow, ti, elenum);
							break;
						}
					}
					for (int j = top; j >= i + 1; j--) {
						swapint(qs[j], qs[j - 1]);
						swapint(qe[j], qe[j - 1]);
						swapint(up[j], up[j - 1]);
					}
					top++;
				}
				else {
					if (eled == up[i]) {
						for (int j = 1; j <= 4; j++) {
							if (ele[j] == 0) {
								ele[j] = qe[i];
								elenum++;

								fprintf(pf2, "in %d %d %d\n", elenow, ti, elenum);
								break;
							}
						}
						for (int j = top; j >= i + 1; j--) {
							swapint(qs[j], qs[j - 1]);
							swapint(qe[j], qe[j - 1]);
							swapint(up[j], up[j - 1]);
						}
						top++;
					}
				}

				//cout << "!!!" << eled << " " << ti << " " << elenow << " "<<top<<endl;
			}

		}
		if (cou == num) {
			break;
		}
		ti++;

		update(ti);
		if (elenum == 0) {
			if (top > bu)
				continue;
			if (qs[top] > elenow)
				eled = 1;
			else if (qs[top] < elenow)
				eled = -1;
			else
				eled = 0;
			//cout << "tttt";
		}
		elenow = elenow + eled;
	}
	fclose(pf1);
	fclose(pf2);
	return 0;
}
