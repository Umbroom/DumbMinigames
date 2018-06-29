#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define A 8

int main() {
	srand((unsigned int)time(NULL));

	bool f, g1, g2, g3, g4, h;
	static int c, d, i, j, k, l, m[8], n[8], s[A + 4][A + 4], s0, s1, s2, x, y, z;
	static char a[A + 4][A + 4], b;

	for (i = 0; i < A + 4; i++)
		for (j = 0; j < A + 4; j++)
			a[i][j] = ' ';

	for (i = 1; i <= A; i++) {
		a[1][i + 1] = (char)('0' + i);
		a[i + 1][1] = (char)('0' + i);
	}

	printf("　あなたは先手(X)と後手(O)のどちらが良いですか。\n");
	do {
		printf("先手(X)なら0、後手(O)なら1と入力してください >>");
		scanf_s("%d", &z);
	} while (z != 0 && z != 1);

	puts("------------");
	for (i = 0; i <= A; i++) {
		for (j = 0; j <= A; j++)
			putchar(a[i + 1][j + 1]);
		putchar('\n');
	}
	puts("------------");

	//メインループ
	for (c = 0; c < A*A; c++) {
		b = (c % 2 == 0) ? 'X' : 'O';
		if (c % 2 == z) {
			//入力
			do {
				printf("%c(x,y) >>", b);
				scanf_s("%d%d", &x, &y);

				f = 1 <= x && x <= A && 1 <= y && y <= A && a[y + 1][x + 1] == ' ';
			} while (!f);
			a[y + 1][x + 1] = b;
		}
		else {
			//コンピュータの手番
			for (i = 2; i < A + 2; i++)
				for (j = 2; j < A + 2; j++)
					s[i][j] = 0;

			for (i = 2; i < A + 2; i++)
				for (j = 2; j < A + 2; j++)
					if (a[i][j] == ' ') {
						for (n[0] = 0; i - n[0] > 2; n[0]++)
							if (a[i - n[0] - 1][j] != b)
								break;
						for (n[1] = 0; i + n[1] < A + 1; n[1]++)
							if (a[i + n[1] + 1][j] != b)
								break;
						for (n[2] = 0; j - n[2] > 2; n[2]++)
							if (a[i][j - n[2] - 1] != b)
								break;
						for (n[3] = 0; j - n[3] < A + 1; n[3]++)
							if (a[i][j + n[3] + 1] != b)
								break;

						for (n[4] = 0; i - n[4] > 2 && j - n[4] > 2; n[4]++)
							if (a[i - n[4] - 1][j - n[4] - 1] != b)
								break;
						for (n[5] = 0; i + n[5] < A + 1 && j + n[5] < A + 1; n[5]++)
							if (a[i + n[5] + 1][j + n[5] + 1] != b)
								break;
						for (n[6] = 0; i - n[6] > 2 && j + n[6] < A + 1; n[6]++)
							if (a[i - n[6] - 1][j + n[6] + 1] != b)
								break;
						for (n[7] = 0; i + n[7] < A + 1 && j - n[7] > 2; n[7]++)
							if (a[i + n[7] + 1][j - n[7] - 1] != b)
								break;

						b = (b == 'O') ? 'X' : 'O';

						for (m[0] = 0; i - m[0] > 2; m[0]++)
							if (a[i - m[0] - 1][j] == b)
								break;
						for (m[1] = 0; i + m[1] < A + 1; m[1]++)
							if (a[i + m[1] + 1][j] == b)
								break;
						for (m[2] = 0; j - m[2] > 2; m[2]++)
							if (a[i][j - m[2] - 1] == b)
								break;
						for (m[3] = 0; j + m[3] < A + 1; m[3]++)
							if (a[i][j + m[3] + 1] == b)
								break;

						for (m[4] = 0; i - m[4] > 2 && j - m[4] > 2; m[4]++)
							if (a[i - m[4] - 1][j - m[4] - 1] == b)
								break;
						for (m[5] = 0; i + m[5] < A + 1 && j + m[5] < A + 1; m[5]++)
							if (a[i + m[5] + 1][j + m[5] + 1] == b)
								break;
						for (m[6] = 0; i - m[6] > 2 && j + m[6] < A + 1; m[6]++)
							if (a[i - m[6] - 1][j + m[6] + 1] == b)
								break;
						for (m[7] = 0; i + m[7] < A + 1 && j - m[7] > 2; m[7]++)
							if (a[i + m[7] + 1][j - m[7] - 1] == b)
								break;

						b = (b == 'O') ? 'X' : 'O';

						for (l = 0, k = 0; k < 8; k += 2)
							l += (n[k] + n[k + 1] >= 4) ? 1 : 0;
						if (l >= 1)
							s[i][j] = 100;
						else {
							for (l = 0, k = 0; k < 8; k += 2)
								l += (n[k] + n[k + 1] >= 3 && m[k] - n[k] >= 1 
									&& m[k + 1] - n[k + 1] >= 1) ? 1 : 0;
							if (l >= 1)
								s[i][j] = 80;
							else {
								for (l = 0, k = 0; k < 8; k += 2)
									l += ((n[k] + n[k + 1] >= 3 && m[k] + m[k + 1] - n[k] - n[k + 1] >= 1) ||
									(n[k] + n[k + 1] >= 2 && m[k] + m[k + 1] - n[k] - n[k + 1] >= 3 &&
										m[k] - n[k] >= 1 && m[k + 1] - n[k + 1] >= 1)) ? 1 : 0;
								if (l >= 2)
									s[i][j] = 60;
								else {
									for (l = 0, k = 0; k < 8; k += 2)
										l += (n[k] + n[k + 1] >= 1 && m[k] + m[k + 1] >= 5) ? 1 : 0;
									s[i][j] = 12 * l;

									for (l = 0, k = 0; k < 8; k += 2)
										l += (n[k] + n[k + 1] >= 2 && m[k] + m[k + 1] >= 5) ? 1 : 0;
									s[i][j] += 4 * l;

									if (s[i][j] == 0) {
										for (l = 0, k = 0; k < 8; k += 2)
											l += (m[k] + m[k + 1] >= 5) ? abs(m[k] - m[k + 1]) : 10;
										s[i][j] = 8 - l;
									}
								}
							}
						}
					}

			//敵の妨害
			b = (b == 'O') ? 'X' : 'O';
			for (i = 2; i < A + 2; i++)
				for (j = 2; j < A + 2; j++)
					if (a[i][j] == ' ') {
						for (n[0] = 0; i - n[0] > 2; n[0]++)
							if (a[i - n[0] - 1][j] != b)
								break;
						for (n[1] = 0; i + n[1] < A + 1; n[1]++)
							if (a[i + n[1] + 1][j] != b)
								break;
						for (n[2] = 0; j - n[2] > 2; n[2]++)
							if (a[i][j - n[2] - 1] != b)
								break;
						for (n[3] = 0; j - n[3] < A + 1; n[3]++)
							if (a[i][j + n[3] + 1] != b)
								break;

						for (n[4] = 0; i - n[4] > 2 && j - n[4] > 2; n[4]++)
							if (a[i - n[4] - 1][j - n[4] - 1] != b)
								break;
						for (n[5] = 0; i + n[5] < A + 1 && j + n[5] < A + 1; n[5]++)
							if (a[i + n[5] + 1][j + n[5] + 1] != b)
								break;
						for (n[6] = 0; i - n[6] > 2 && j + n[6] < A + 1; n[6]++)
							if (a[i - n[6] - 1][j + n[6] + 1] != b)
								break;
						for (n[7] = 0; i + n[7] < A + 1 && j - n[7] > 2; n[7]++)
							if (a[i + n[7] + 1][j - n[7] - 1] != b)
								break;

						b = (b == 'O') ? 'X' : 'O';

						for (m[0] = 0; i - m[0] > 2; m[0]++)
							if (a[i - m[0] - 1][j] == b)
								break;
						for (m[1] = 0; i + m[1] < A + 1; m[1]++)
							if (a[i + m[1] + 1][j] == b)
								break;
						for (m[2] = 0; j - m[2] > 2; m[2]++)
							if (a[i][j - m[2] - 1] == b)
								break;
						for (m[3] = 0; j + m[3] < A + 1; m[3]++)
							if (a[i][j + m[3] + 1] == b)
								break;

						for (m[4] = 0; i - m[4] > 2 && j - m[4] > 2; m[4]++)
							if (a[i - m[4] - 1][j - m[4] - 1] == b)
								break;
						for (m[5] = 0; i + m[5] < A + 1 && j + m[5] < A + 1; m[5]++)
							if (a[i + m[5] + 1][j + m[5] + 1] == b)
								break;
						for (m[6] = 0; i - m[6] > 2 && j + m[6] < A + 1; m[6]++)
							if (a[i - m[6] - 1][j + m[6] + 1] == b)
								break;
						for (m[7] = 0; i + m[7] < A + 1 && j - m[7] > 2; m[7]++)
							if (a[i + m[7] + 1][j - m[7] - 1] == b)
								break;

						b = (b == 'O') ? 'X' : 'O';

						for (l = 0, k = 0; k < 8; k += 2)
							l += (n[k] + n[k + 1] >= 4) ? 1 : 0;
						if (l >= 1)
							s[i][j] += 90;
						else {
							for (l = 0, k = 0; k < 8; k += 2)
								l += (n[k] + n[k + 1] >= 3 && m[k] - n[k] >= 1 && m[k + 1] - n[k + 1] >= 1) ? 1 : 0;
							if (l >= 1)
								s[i][j] += 70;
							else {
								for (l = 0, k = 0; k < 8; k += 2)
									l += ((n[k] + n[k + 1] >= 3 && m[k] + m[k + 1] - n[k] - n[k + 1] >= 1) ||
									(n[k] + n[k + 1] >= 2 && m[k] + m[k + 1] - n[k] - n[k + 1] >= 3 &&
										m[k] - n[k] >= 1 && m[k + 1] - n[k + 1] >= 1)) ? 1 : 0;
								if (l >= 2)
									s[i][j] += 50;
								else {
									for (l = 0, k = 0; k < 8; k += 2)
										l += (n[k] + n[k + 1] >= 1 && m[k] + m[k + 1] >= 5) ? 1 : 0;
									s[i][j] += 9 * l;

									for (l = 0, k = 0; k < 8; k += 2)
										l += (n[k] + n[k + 1] >= 2 && m[k] + m[k + 1] >= 5) ? 1 : 0;
									s[i][j] += 3 * l;
								}
							}
						}
					}

			b = (b == 'O') ? 'X' : 'O';

			d = 1;
			s0 = s[2][2];
			s1 = 2;
			s2 = 2;
			for (i = 2; i < A + 2; i++)
				for (j = 2; j < A + 2; j++)
					if (s0 == s[i][j] && a[i][j] == ' ' && rand() % (++d) == 0) {
						s0 = s[i][j];
						s1 = i;
						s2 = j;
					}
					else if (s0 < s[i][j] && a[i][j] == ' ') {
						s0 = s[i][j];
						s1 = i;
						s2 = j;
						d = 1;
					}

					printf("%c(x,y) >>%d %d\n", b, s2 - 1, s1 - 1);
					a[s1][s2] = b;
		}

		//表示
		puts("------------");
		for (i = 0; i <= A; i++) {
			for (j = 0; j <= A; j++)
				putchar(a[i + 1][j + 1]);
			putchar('\n');
		}
		puts("------------");

		//判定
		for (i = 2; i < A + 2; i++) {
			for (j = 2; j < A + 2; j++) {
				g1 = a[i - 2][j] == b && a[i - 1][j] == b && a[i][j] == b && a[i + 1][j] == b && a[i + 2][j] == b;
				g2 = a[i][j - 2] == b && a[i][j - 1] == b && a[i][j] == b && a[i][j + 1] == b && a[i][j + 2] == b;
				g3 = a[i - 2][j - 2] == b && a[i - 1][j - 1] == b && a[i][j] == b && a[i + 1][j + 1] == b && a[i + 2][j + 2] == b;
				g4 = a[i + 2][j - 2] == b && a[i + 1][j - 1] == b && a[i][j] == b && a[i - 1][j + 1] == b && a[i - 2][j + 2] == b;
				h = g1 || g2 || g3 || g4;

				if (h) {
					printf("　%cの勝ちです。\n", b);
					return 0;
				}
			}
		}
		if (c == A * A - 1)
			printf("　引き分けです。\n");
	}

	return 0;
}