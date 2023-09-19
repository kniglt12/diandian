#include<string.h>
#include<stdio.h>

int num, top, bu, s[10000], e[10000], t[100000];
int up[100000];
int qs[10000], qe[10000];
int elenow[2], eled[2], elenum[2], ele[2][5];
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
	//printf("ssasa");
	scanf("elevator %d %d %d", &elenow[0], &elenow[1], &num);//多输入一个总乘客数呗，不文件输入输出没想到好的终止办法qwq- 
	for (int i = 1; i <= num; i++) {
		scanf("%d %d %d", &s[i], &e[i], &t[i]);

	}
	int ti = 1;
	top = 1;
	update(0);
	update(1);
	printf("elevator1 %d 0 0\n", elenow[0]);
	printf("elevator2 %d 0 0\n", elenow[1]);
	while (1) {
		for (int k = 0; k <= 1; k++) {
			//cout << top<<" "<<bu <<" "<<eled[0] << endl;
			//cout<<"!!!" << eled[0] << " " << ti << " " << elenow[0] << endl;
			//printf("tttt %d %d %d %d\n", k, eled[k], elenow[k],elenum[k]);
			for (int i = 1; i <= 4; i++) {
				if (ele[k][i] == elenow[k]) {
					ele[k][i] = 0;
					elenum[k]--;
					printf("elevator%d out %d %d %d\n",k+1, elenow[k], ti, elenum[k]);
					cou++;
				}
			}
			for (int i = top; i <= bu; i++) {
				//cout << "sadadad";
				if (elenum[k] == 4)
					break;
				if (qs[i] == elenow[k]) {
					if (elenum[k] == 0) {
						for (int j = 1; j <= 4; j++) {
							if (ele[k][j] == 0) {
								ele[k][j] = qe[i];
								elenum[k]++;
								eled[k] = up[i];
								printf("elevator%d in %d %d %d\n", k+1,elenow[k], ti, elenum[k]);
								break;
							}
						}
						for (int j = i; j >= top + 1; j--) {
							swapint(&qs[j], &qs[j - 1]);
							swapint(&qe[j], &qe[j - 1]);
							swapint(&up[j], &up[j - 1]);
						}
						top++;
						//continue;
					}
					else {
						if (eled[k] == up[i]) {
							for (int j = 1; j <= 4; j++) {
								if (ele[k][j] == 0) {
									ele[k][j] = qe[i];
									elenum[k]++;

									printf("elevator%d in %d %d %d\n", k+1,elenow[k], ti, elenum[k]);
									break;
								}
							}
							for (int j = i; j >= top + 1; j--) {
								swapint(&qs[j], &qs[j - 1]);
								swapint(&qe[j], &qe[j - 1]);
								swapint(&up[j], &up[j - 1]);
							}
							top++;
						}
					}

					//cout << "!!!" << eled[k] << " " << ti << " " << elenow[k] << " "<<top<<endl;
				}

			}
		}


		if (cou == num ) {
			break;
		}
		ti++;

		update(ti);
		if (elenum[0] == 0) {
			if (top > bu)
				eled[0] = 0;
			else if (qs[top] > elenow[0])
				eled[0] = 1;
			else if (qs[top] < elenow[0])
				eled[0] = -1;
			else
				eled[0] = 0;
			//cout << "tttt";
		}
		elenow[0] = elenow[0] + eled[0];
		if (elenum[1] == 0) {
			if (top > bu)
				eled[1] = 0;
			else if (qs[top] > elenow[1])
				eled[1] = 1;
			else if (qs[top] < elenow[1])
				eled[1] = -1;
			else
				eled[1] = 0;
			//cout << "tttt";
		}
		elenow[1] = elenow[1] + eled[1];
	}
	return 0;
}
