##include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int check_price_and_quantity(int*, int*);
double get_discount(int);
void print_total_price(int, int, double);

/* Main Function */
int main(int argc, char* argv[]) {
	int item_price, quantity;
	double discount;
	printf("Welcome To Temple Store\n");
	if (check_price_and_quantity(&item_price, &quantity)) {
		discount = get_discount(quantity);
		print_total_price(item_price, quantity, discount);
	}
	printf("\nThank you for using Temple Store\n");
	exit(0);
}

/* 
   Ask the user for price and quantity
   End the program if we get invalid input
*/
int check_price_and_quantity(int *item_price, int *quantity) {
	printf("\n\tEnter item price: ");
	scanf("%d", item_price);
	if (*item_price <= 0) {
		printf("\n\tThis is not a valid item price.\n\tPlease run the program again.\n");
		return 0;
	}
	printf("\tEnter quantity: ");
	scanf("%d", quantity);
	if (*quantity <= 0) {
		printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again.\n");
		return 0;
	}
	return 1;
}

/* Return the discount from the quantity purchased */
double get_discount(int quantity) {
	if (quantity >= 50 && quantity <= 99)   return 0.1;
	if (quantity >= 100 && quantity <= 149) return 0.15;
	if (quantity >= 150)                    return 0.25;
	return 0;
}

/* Print the total price of the purchase */
void print_total_price(int item_price, int quantity, double discount) {
	printf("\n\tThe item price is: $%d\n", item_price);
	printf("\tThe order is: %d item(s)\n", quantity);
	printf("\tThe cost is: $%d\n", item_price * quantity);
	printf("\tThe discount is: %.1f%%\n", discount * 100);
	printf("\tThe discount amount is: $%.1f\n", discount * (item_price * quantity));
	printf("\tThe total is: $%.1f\n", (item_price * quantity) - (discount * (item_price * quantity)));
}
