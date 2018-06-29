#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	srand((unsigned int)time(NULL));
	int player_hand = 0, cpu_hand, hands[100][2], result[3] = { 0, 0, 0 }, a[3], i, j;

	printf("グーが0，チョキが1，パーが2\n");

	for (i = 1; i <= 100; i++) {

		for (j = 0; j < 3; j++)
			a[j] = 0;


		for (j = i - 3; j >= 0 && j >= i - 6; j--)
			a[hands[j + 1][1]] += 1;


		if (a[0] <= a[1] && a[2] <= a[1])
			cpu_hand = (player_hand + 2) % 3;
		else if (a[0] <= a[2] && a[1] <= a[2])
			cpu_hand = (player_hand + 1) % 3;
		else
			cpu_hand = (player_hand);

		if (result[1] + result[2] >= 5)
			if ((double)result[2] / (result[1] + result[2]) < 0.5){
				cpu_hand = (player_hand + 1) % 3;
			}


		while (1){
			scanf_s("%d", &player_hand);
			if (player_hand == 0 || player_hand == 1 || player_hand == 2){
				break;
			}
			printf("やり直せ");
		}


		hands[i - 1][0] = player_hand;

		if (i != 1)
			if ((hands[i - 2][0] + 1) % 3 == player_hand)
				hands[i - 1][1] = 0;
			else if (hands[i - 2][0] == player_hand)
				hands[i - 1][1] = 1;
			else
				hands[i - 1][1] = 2;

			result[(cpu_hand - player_hand + 3) % 3] += 1;

			printf("%s%d%s%d%s%d%s%d%s", "CPUは", i, "戦", result[2], "勝", result[1], "負", result[0], "引分\n");
	}
}