#include <stdio.h>

/* Function Prototypes */
int print_welcome_msg();
void print_paycheck();

/* Global Variables For Paycheck */
int emp_num, salary, weekly_time, otime_amount;
double otime_pay, net_pay, reg_pay;

/* Main Function */
int main(int argc, char* argv[]) {
	if (print_welcome_msg()) {
		print_paycheck();
	}
	return 0;
}

/* Prints the welcome message to stdout */
int print_welcome_msg() {
	printf("Welcome To \"TEMPLE HUMAN RESOURCES\"\n\n");
	printf("\tEnter Employee Number: ");
	scanf("%d", &emp_num);
	if (emp_num <= 0) {
		printf("\n\tThis is not a valid empolyee number.\n\tPlease run the program again.\n");
		printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");	// this needs to be in quotes
		return 0;
	}
	printf("\tEnter Hourly Salary: ");
	scanf("%d", &salary);
	if (salary <= 0) {
		printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again.\n");
		printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
		return 0;
	}
	printf("\tEnter Weekly Time: ");
	scanf("%d", &weekly_time);
	if (weekly_time <= 0) {
		printf("\n\tThis is not a weekly time.\n\tPlease run the program again.\n");
		printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
		return 0;
	}
	return 1;
}

/* Prints the paycheck to stdout */
void print_paycheck() {
	printf("\t=================================\n");
	printf("\tEmployee Number: %d\n", emp_num);
	printf("\tHourly Salary: $%d\n", salary);
	printf("\tWeekly Time: %d\n", weekly_time);
	if (weekly_time > 40) {
		reg_pay = 40 * salary;
		otime_pay = (1.5 * salary) * (weekly_time - 40);
	}
	else reg_pay = weekly_time * salary;
	printf("\tRegular Pay: $%.1f\n", reg_pay);
	printf("\tOvertime Pay: $%.1f\n", otime_pay);
	printf("\tNet Pay: $%.1f\n", reg_pay + otime_pay);
	printf("\t=================================\n"); 
	printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
}

