#include <stdio.h>

#define SCORE_WIN 10
#define SCORE_BOARD 5

int main()
{
	int betA, betB, teamA, teamB;
	int score = 0;
	
	printf("Informe o placar da aposta:\n");
	scanf("%d %d", &betA, &betB);

	printf("Informe o resultado do placar:\n");
	scanf("%d %d", &teamA, &teamB);

	if(betA > betB && teamA > teamB || betA < betB && teamA < teamB || betA == betB && teamA == teamB)
		score += SCORE_WIN;

	if(betA == teamA)
		score += SCORE_BOARD;

	if(betB == teamB)
		score += SCORE_BOARD;

	printf("%d\n", score);		
		

	return 0;
}	
