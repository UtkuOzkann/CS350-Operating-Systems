#include <stdio.h>
#include <stdbool.h>
int main()
{

	int numberOfPeople;
	int orderList = 0;
	int finalOrderList;
	int thresholdValue = 8;
	int indexSize = 0;
	int count = 0;
	int value = 0;
	int finalFood = 0;
	int finalFoodIndex = 0;
	int totalSizeOfSecondRound = 0;
	int secondRoundSize;
	bool aboveThreshold = false;
	char foods[5][20] = {"Kebab", "Burger", "Pasta", "Lahmacun", "Salad"};
	int foodSize = sizeof(foods) / sizeof(foods[0]);
	int index[foodSize];
	int finalRound[foodSize];

	printf("Please enter the number of people: ");
	scanf("%d", &numberOfPeople);
	for (int i = 0; i < foodSize; i++)
	{
		printf("%d - %s\n", (i + 1), foods[i]);
		index[i] = 0;
		finalRound[i] = 0;
	}
	for (int i = 0; i < numberOfPeople; i++)
	{
		printf("You are user%d\n", (i + 1));
		printf("Please order your menu:\n");
		for (int j = 0; j < foodSize; j++)
		{
			printf("Your %d%s%s", (j + 1), ". choice", ":");
			scanf("%d", &orderList);
			index[orderList - 1] += foodSize - j;
		}
	}
	indexSize = sizeof(index) / sizeof(index[0]);
	printf("Your first round picks and scores\n");
	for (int i = 0; i < indexSize; i++)
	{
		if (index[i] >= thresholdValue)
		{
			count++;
			aboveThreshold = true;
			printf("%d) %s => %d\n", (i + 1), foods[i], index[i]);
		}
	}

	if (count == 0)
	{
		printf("You are eating at home/dorm today!\n");
	}
	else if (count == 1)
	{
		printf("You are eating");
		for (int i = 0; i < indexSize; i++)
		{
			if (index[i] >= thresholdValue)
				printf(" %s", foods[i]);
		}
	}
	else
	{
		printf("It's time for the second round! Here are the top rated menus in the first round. Please order your menu!\n");
		value = 0;
		for (int i = 0; i < indexSize; i++)
		{
			if (index[i] >= thresholdValue)
			{
				printf("%d) %s\n", (i + 1), foods[i]);
			}
		}
		printf("Second round begins!\n");

		for (int i = 0; i < numberOfPeople; i++)
		{
			value = 0;
			printf("You are user%d\n", (i + 1));
			printf("Please order your menu:\n");
			for (int i = 0; i < foodSize; i++)
			{
				if (index[i] >= thresholdValue)
				{
					printf("Your %d%s%s", (++value), ". choice", ":");
					scanf("%d", &finalOrderList);
					finalRound[finalOrderList - 1] += foodSize - i;
				}
			}
		}
		indexSize = sizeof(index) / sizeof(index[0]);
		printf("Here are your second round picks and scores\n");
		value = 0;
		for (int i = 0; i < indexSize; i++)
		{
			if (finalRound[i] >= thresholdValue)
			{
				count++;
				printf("%d) %s => %d\n", (i + 1), foods[i], finalRound[i]);
			}
		}

		for (int i = 0; i < foodSize; i++)
		{
			if (finalRound[i] > finalFood)
			{
				finalFood = finalRound[i];
				finalFoodIndex = i;
			}
		}

		printf("You will eat %s today\n", foods[finalFoodIndex]);
	}
	return 0;
}
