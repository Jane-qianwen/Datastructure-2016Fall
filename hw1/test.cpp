#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
string hello (int a);

int main(int argc, char const *argv[])
{
	cout << hello(1)<<endl;
	return 0;
}
string hello (int a)
{
	string b = "23";
	if (a==1)
	{
		return "done";
	}
	else
	{
		return b;
	}
}




string print_month(int year,int month)
{
	int Gregorian_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int Gregorian_months_leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	string month_calendar="";
	if (month==1)
	{
		month_calendar .append("January                 ");
		month_calendar.append("\n");
		//cout << "January                 "<<endl;
	}
	else if(month ==2)
	{
		month_calendar .append("February                ");
		month_calendar.append("\n");
		//cout <<"February                "<<endl;
	}
	else if (month ==3)
	{
		month_calendar .append("March                   ");
		month_calendar.append("\n");
		//cout <<"March                   "<<endl;
	}
	else if (month ==4)
	{
		month_calendar .append("April                   ");
		month_calendar.append("\n");
		//cout <<"April                   "<<endl;
	}
	else if (month==5)
	{
		month_calendar .append("May                     ");
		month_calendar.append("\n");
		//cout <<"May                     "<<endl;
	}
	else if (month==6)
	{
		month_calendar .append("June                    ");
		month_calendar.append("\n");
		//cout <<"June                    "<<endl;
	}
	else if (month==7)
	{
		month_calendar .append("July                    ");
		month_calendar.append("\n");
		//cout <<"July                    "<<endl;
	}
	else if (month==8)
	{
		month_calendar .append("August                  ");
		month_calendar.append("\n");
		//cout <<"August                  "<<endl;
	}
	else if(month==9)
	{
		month_calendar .append("September               ");
		month_calendar.append("\n");
		//cout <<"September               "<<endl;
	}
	else if (month==10)
	{
		month_calendar .append("October                 ");
		month_calendar.append("\n");
		//cout <<"October                 "<<endl;
	}
	else if (month ==11)
	{
		month_calendar .append("November                ");
		month_calendar.append("\n");
		//cout <<"November                "<<endl;
	}
	else
	{
		month_calendar .append("December                ");
		month_calendar.append("\n");
		//cout <<"December                "<<endl;
	}
	month_calendar.append("┌──┬──┬──┬──┬──┬──┬──┐  ");
	month_calendar.append("\n");
	month_calendar.append("│Su│Mo│Tu│We│Th│Fr│Sa│  ");
	month_calendar.append("\n");
	month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
	month_calendar.append("\n");
	int max_days =  0;
	int past_days_Gregorian = days_until_Gregoriandate(year,month,1);
	int firstday = past_days_Gregorian % 7;
	if (Gregorian_is_leapyear(year)==1)
	{
		max_days = Gregorian_months_leap[month-1];
	}
	else
	{
		max_days = Gregorian_months[month-1];
	}
	int days = 1;
	int convert_days = 1;
	if (firstday==0)
	{
		//print the first line
		month_calendar.append("│");
		month_calendar.apend(print_one_day(days));
		//cout<<"│"<<print_one_day(days);
		days = days+1;
		int tmp=1;
		while (tmp<=6)
		{
			month_calendar.append("│");
			month_calendar.apend(print_one_day(days));
			//cout << "│"<<print_one_day(days);
			days = days+1;
			tmp =tmp+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout<<"│"<<"  "<<endl;
		///print the second line
		month_calendar.append("│");
		month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
		//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
		convert_days = convert_days + 1;
		while(convert_days<=days-1)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days +1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
	}
	else if (firstday==1)
	{
		//print the first line
		month_calendar.append("│  │");
		month_calendar.append(print_one_day(days));
		//cout<<"│  │"<<print_one_day(days);
		days = days+1;
		int tmp=1;
		while (tmp<=5)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout << "│"<<print_one_day(days);
			days = days+1;
			tmp = tmp+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout<<"│"<<"  "<<endl;
		///print the second line
		month_calendar.append("│  │");
		month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
		//cout <<"│  │"<<Gregorian_to_SHT(year,month,convert_days,2);
		convert_days = convert_days + 1;
		while(convert_days<=days-1)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days +1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
	}
	else if (firstday==2)
	{
		//print the first line
		month_calendar.append("│  │  │");
		month_calendar.append(print_one_day(days));
		//cout<<"│  │  │"<<print_one_day(days);
		days = days+1;
		int tmp=1;
		while (tmp<=4)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout << "│"<<print_one_day(days);
			days = days+1;
			tmp = tmp+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout<<"│"<<"  "<<endl;
		///print the second line
		month_calendar.append("│  │  │");
		month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
		//cout <<"│  │  │"<<Gregorian_to_SHT(year,month,convert_days,2);
		convert_days = convert_days + 1;
		while(convert_days<=days-1)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days +1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
	}
	else if (firstday==3)
	{
		//print the first line
		month_calendar.append("│  │  │  │");
		month_calendar.append(print_one_day(days));
		//cout<<"│  │  │  │"<<print_one_day(days);
		days = days+1;
		int tmp=1;
		while (tmp<=3)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout << "│"<<print_one_day(days);
			days = days+1;
			tmp = tmp + 1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout<<"│"<<"  "<<endl;
		///print the second line
		month_calendar.append("│  │  │  │");
		month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
		//cout <<"│  │  │  │"<<Gregorian_to_SHT(year,month,convert_days,2);
		convert_days = convert_days + 1;
		while(convert_days<=days-1)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days +1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout << "├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
	}
	else if (firstday==4)
	{
		//print the first line
		month_calendar.append("│  │  │  │  │");
		month_calendar.append(print_one_day(days));
		//cout<<"│  │  │  │  │"<<print_one_day(days);
		days = days+1;
		int tmp=1;
		while (tmp<=2)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout << "│"<<print_one_day(days);
			days = days+1;
			tmp = tmp + 1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout<<"│"<<"  "<<endl;
		///print the second line
		month_calendar.append("│  │  │  │  │");
		month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
		//cout <<"│  │  │  │  │"<<Gregorian_to_SHT(year,month,convert_days,2);
		convert_days = convert_days + 1;
		while(convert_days<=days-1)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days +1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
	}
	else if (firstday==5)
	{
		//print the first line
		month_calendar.append("│  │  │  │  │  │");
		month_calendar.append(print_one_day(days));
		//cout<<"│  │  │  │  │  │"<<print_one_day(days);
		days = days+1;
		int tmp=1;
		while (tmp<=1)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout << "│"<<print_one_day(days);
			days = days+1;
			tmp = tmp + 1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout<<"│"<<"  "<<endl;
		///print the second line
		month_calendar.append("│  │  │  │  │  │");
		month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
		//cout <<"│  │  │  │  │  │"<<Gregorian_to_SHT(year,month,convert_days,2);
		convert_days = convert_days + 1;
		while(convert_days<=days-1)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days +1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
	}
	else
	{
		//print the first line
		month_calendar.append("│  │  │  │  │  │  │");
		month_calendar.append(print_one_day(days));
		//cout<<"│  │  │  │  │  │  │"<<print_one_day(days);
		days = days+1;
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout<<"│"<<"  "<<endl;
		///print the second line
		month_calendar.append("│  │  │  │  │  │  │");
		month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
		//cout <<"│  │  │  │  │  │  │"<<Gregorian_to_SHT(year,month,convert_days,2);
		convert_days = convert_days + 1;
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
	}
	//print the 2-4 lines of the month calendar
	int line=2;
	while (line<=4)
	{
		int m = 1;
		while(m<=7)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout <<"│"<<print_one_day(days);
			days = days + 1;
			m=m+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		int n = 1;
		while (n<=7)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days + 1;
			n=n+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
		line = line + 1;
	}
	//print line5/6
	if ((max_days-days+1)>=7)
	{
		int m = 1;
		while(m<=7)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout <<"│"<<print_one_day(days);
			days = days + 1;
			m=m+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		int n = 1;
		while (n<=7)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days + 1;
			n=n+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout <<"│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
		int blank =  7-(max_days-days+1);
		while (days<=max_days)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout <<"│"<<print_one_day(days);
			days =days+1;
		}
		int i = 1;
		while (i<=blank)
		{
			month_calendar.append("│  ");	
			//cout << "│"<<"  ";
			i = i+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout << "│"<<"  "<<endl;
		while (convert_days<=max_days)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days +1;
		}
		i = 1;
		while (i<=blank)
		{
			month_calendar.append("│  ");
			//cout << "│"<<"  ";
			i = i+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout << "│"<<"  "<<endl;
		month_calendar.append("└──┴──┴──┴──┴──┴──┴──┘  ");
		month_calendar.append("\n");
		month_calendar.append("\n");
		//cout <<"└──┴──┴──┴──┴──┴──┴──┘  "<<endl<<endl;
	}
	else
	{
		int blank = 7-(max_days-days+1);
		while (days<=max_days)
		{
			month_calendar.append("│");
			month_calendar.append(print_one_day(days));
			//cout <<"│"<<print_one_day(days);
			days =days +1;
		}
		int i = 1;
		while (i<=blank)
		{
			month_calendar.append("│  ");
			//cout << "│"<<"  ";
			i=i+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout << "│"<<"  "<<endl;
		while (convert_days<=max_days)
		{
			month_calendar.append("│");
			month_calendar.append(Gregorian_to_SHT(year,month,convert_days,2));
			//cout <<"│"<<Gregorian_to_SHT(year,month,convert_days,2);
			convert_days = convert_days +1;
		}
		i = 1;
		while (i<=blank)
		{
			month_calendar.append("│  ");
			//cout << "│"<<"  ";
			i=i+1;
		}
		month_calendar.append("│  ");
		month_calendar.append("\n");
		//cout << "│"<<"  "<<endl;
		month_calendar.append("├──┼──┼──┼──┼──┼──┼──┤  ");
		month_calendar.append("\n");
		//cout <<"├──┼──┼──┼──┼──┼──┼──┤  "<<endl;
		month_calendar.append("│  │  │  │  │  │  │  │  ");
		month_calendar.append("\n");
		//cout <<"│  │  │  │  │  │  │  │  "<<endl;
		month_calendar.append("│  │  │  │  │  │  │  │  ");
		month_calendar.append("\n");
		//cout <<"│  │  │  │  │  │  │  │  "<<endl;
		month_calendar.append("└──┴──┴──┴──┴──┴──┴──┘  ");
		month_calendar.append("\n");
		month_calendar.append("\n");
		//cout <<"└──┴──┴──┴──┴──┴──┴──┘  "<<endl<<endl;

	}
	return month_calendar;
}