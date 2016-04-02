/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
}*temp1,*temp2;

int checkleap (int year) 
{
	int check = 0;
	if (year % 100 == 0) 
	{
		if (year % 400 == 0) 
			check = 1;
		else 
			check = 0;
	}
	else if (year % 4 == 0) 
		check = 1;
	return check;
}

int between_days(struct node *date1head, struct node *date2head){
	int result = 0, day1=0, day2=0, month1=0, month2=0, year1=0, year2=0, count, i;
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (date1head == NULL || date2head == NULL)
		return -1;
	count = 0;
	while (count < 2)
	{
		day1 = day1 * 10 + date1head->data;
		day2 = day2 * 10 + date2head->data;
		count++;
	}
	while (count < 4)
	{
		month1 = month1 * 10 + date1head->data;
		month2 = month2 * 10 + date2head->data;
		count++;
	}
	while (count < 8)
	{
		year1 = year1 * 10 + date1head->data;
		year2 = year2 * 10 + date2head->data;
		count++;
	}
	if (year1 == year2&&month1 == month2)
		return abs(day1 - day2) - 1;
	if (month1 == 2)
		result = days[month1 - 1] - day1 - 1 + checkleap(year1);
	else
		result = days[month1 - 1] - day1 - 1;
	if (month1 == 12)
	{
		month1 = 0;
		year1++;
	}
	while (year1 <= year2)
	{
		for (i = month1; i < 12; i++)
		{

			if ((year1 == year2) && (i == month2 - 1))
			{
				result += day2;
				break;
			}
			if (i == 1)
				result = result + days[i] + checkleap(year1);
			else
				result += days[i];
		}

		month1 = 0;
		year1++;
	}
	return result;
}