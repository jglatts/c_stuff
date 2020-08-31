#include <stdio.h>

/* Function Prototypes */
int check_price_and_quantity();
double get_discount();
void print_total_price();

/* Global Variables for revenue */
int item_price, quantity;
double discount;

/* Main Function */
int main(int argc, char* argv[]) {
	if (check_price_and_quantity()) {
		discount = get_discount();
		print_total_price();
	}
	return 0;
}

/* 
   Ask the user for price and quantity
   End the program if we get invalid input
*/
int check_price_and_quantity() {
	printf("Welcome To Temple Store\n");
	printf("\n\tEnter item price: ");
	scanf("%d", &item_price);
	if (item_price <= 0) {
		printf("\n\tThis is not a valid item price.\n\tPlease run the program again.\n");
		printf("\nThank you for using Temple Store\n");
		return 0;
	}

	printf("\tEnter quantity: ");
	scanf("%d", &quantity);
	if (quantity <= 0) {
		printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again.\n");
		printf("\nThank you for using Temple Store\n");
		return 0;
	}
	return 1;
}

/* Return the discount from the quantity purchased */
double get_discount() {
	if (quantity >= 50 || quantity <= 99)        return 0.1;
	else if (quantity >= 100 || quantity <= 149) return 0.15;
	else if (quantity >= 150)                    return 0.25;
	return 0;
}

/* Print the total price of the purchase */
void print_total_price() {
	printf("\n\tThe item price is: $%d\n", item_price);
	printf("\tThe order is: %d item(s)\n", quantity);
	printf("\tThe cost is: $%d\n", item_price * quantity);
	printf("\tThe discount is: %.1f%%\n", discount * 100);
	printf("\tThe discount amount is: $%.1f\n", discount * (item_price * quantity));
	printf("\tThe total is: $%.1f\n", (item_price * quantity) - (discount * (item_price * quantity)));
	printf("\nThank you for using Temple Store\n");
}
