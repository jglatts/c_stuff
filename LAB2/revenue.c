#include <stdio.h>

int main(int argc, char* argv[]) {
	int item_price, quantity;
	double discount;

	printf("Welcome To Temple Store\n");
	printf("\n\tEnter item price: ");
	scanf("%d", &item_price);
	if (item_price <= 0) {
		printf("\n\tThis is not a valid item price.\n\tPlease run the program again.\n");
		printf("\nThank you for using Temple Store\n");
		return 1;
	}
	
	printf("\tEnter quantity: ");
	scanf("%d", &quantity);
	if (quantity <= 0) {
		printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again.\n");
		printf("\nThank you for using Temple Store\n");
		return 1;
	}
	
	if (quantity >= 50 || quantity <= 99)        discount = 0.1;
	else if (quantity >= 100 || quantity <= 149) discount = 0.15;
	else if (quantity >= 150)                    discount = 0.25;

	printf("\n\tThe item price is: $%d\n", item_price);
	printf("\tThe order is: %d item(s)\n", quantity);
	printf("\tThe cost is: $%d\n", item_price * quantity);
	printf("\tThe discount is: %.1f%%\n", discount * 100);
	printf("\tThe discount amount is: $%.1f\n", discount * (item_price *  quantity));
	printf("\tThe total is: $%.1f\n", (item_price * quantity) - (discount * (item_price * quantity)));
	printf("\nThank you for using Temple Store\n");

	return 0;
}
