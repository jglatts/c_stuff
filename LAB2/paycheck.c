#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int get_employee_info(int*, int*, int*);
void print_paycheck(int, int, int);

/* Main Function */
int main(int argc, char* argv[]) {
	int emp_num, salary, weekly_time;	// vars to hold employee info
	
	printf("Welcome To \"TEMPLE HUMAN RESOURCES\"\n\n");
	// check if the given employee info is valid
	if (get_employee_info(&emp_num, &salary, &weekly_time)) {
		print_paycheck(emp_num, salary, weekly_time);	
	}
	printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
	
	exit(0);
}

/* Scan in the employee info and check if it's valid */
int get_employee_info(int *emp_num, int *salary, int *weekly_time) {
	printf("\tEnter Employee Number: ");
	scanf("%d", emp_num);
	if (*emp_num <= 0) {
		printf("\n\tThis is not a valid employee number.\n\tPlease run the program again.\n");
		return 0;
	}
	
	printf("\tEnter Hourly Salary: ");
	scanf("%d", salary);
	if (*salary <= 0) {
		printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again.\n");
		return 0;
	}
	
	printf("\tEnter Weekly Time: ");
	scanf("%d", weekly_time);
	if (*weekly_time <= 0) {
		printf("\n\tThis is not a weekly time.\n\tPlease run the program again.\n");
		return 0;
	}

	return 1;
}

/* Prints the paycheck to stdout */
void print_paycheck(int emp_num, int salary, int weekly_time) {
	double otime_pay, reg_pay; 

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
}

