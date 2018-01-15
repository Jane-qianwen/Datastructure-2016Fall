#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

bool Gregorian_is_leapyear(int y);
bool SHT_is_leapyear(string a);
int days_until_Gregoriandate(int y,int m,int d);
int get_leapmonth(string a);
int days_until_SHTdate(int y,int m,int d);
string int_to_string(int a);
string Gregorian_to_SHT(int y,int m,int d,int sign);

int main(int argc, char const *argv[])
{
	//initial the variables
	string input_year = "";
	string input_month="";
	string input_day="";
	int year = 0;
	int month = 0;
	int day = 0;

	int Gregorian_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int Gregorian_months_leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	string Gregorian_months_name[13]={"none","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	string SHT_months_name[13]={"none","Sist","SIST","Spst","SPST","Slst","SLST","Sem","SEM","Sials","SIAIS","Ihuman","IHUMAN"};
	//string SHT_leap_months[7]={"Sist","Spst","Slst","Sem","Sials","Ihuman","none"};
	//string SHT_leap_months[6]={"SIST","SPST","SLST","SEM","SIAIS","IHUMAN"};
	if (argc == 2)
	//eg:./calendar 2005 输出年历,得到year
	{
		input_year = argv[1];
		year = atoi(input_year.c_str());
		//print_year_calendar(input_year);
	}
	else if (argc == 3)
	//eg:./calendar 6 1989 输出月历，得到month和year
	{
		input_month=argv[1];
		month = atoi(input_month.c_str());
		input_year=argv[2];
		year = atoi(input_year.c_str());
		//print_month_calendar(string year,int month);
	}
	else
	//日历转换 eg:./calendar Jan 1, 123 or SIST 2D, 1236 
	{
		for(int m=1;m<13;m++)
		{
			if (argv[1]==Gregorian_months_name[m])
			//input is Gregorian Calendar
			{

				//get the month of Gregorian Calendar
				month = m;
				//get the day of Gregorian Calendar
				input_day = argv[2];
				//erase ,
				input_day.erase(input_day.end()-1);
				day = atoi(input_day.c_str());
				//get the year of the Gregorian Calendar
				input_year = argv[3];
				year = atoi(input_year.c_str());
				//conversion
				//cout << days_until_Gregoriandate(9999,1,1)<<endl;
				//cout << days_until_SHTdate(11,6,1)<<endl;
				Gregorian_to_SHT(year,month,day,1);
				break;
			}
			else if (argv[1]==SHT_months_name[m])
			//input is SHT Calendar
			{
				//get the year of SHT Calendar
				input_year = argv[3];
				year = atoi(input_year.c_str());
				//get the day of SHT Calendar
				day = strtoul(argv[2], NULL, 16); 

				//get the month of SHT Calendar
				//SHT_year is a normal year,6 months
				if (SHT_is_leapyear(input_year)==0)
				{
					month = (m+1)/2;
				}
				else
				//SHT_year is a leap year,7 months
				{
					//get the month of SHT Calendar
					//only SIST and SEM will be new month
					if (m==2)
					{
						month = 10;//need more to comfirm its month name
					}
					else if (m==8)
					{
						month= 40;
					}
					else 
					{
						month = (m+1)/2;
					}
				}
				//SHT_to_Gregorian(year,month,day);
				break;
			}
		}	
	}
	return 0;	
}

int get_digitsum(string a)
{
	int digit_sum_year = 0;
	for (int i=0;i<a.size();i++)
	{
		char digit = a[i];
		digit_sum_year = digit_sum_year + (digit - '0');
	}
	return digit_sum_year;
}

bool SHT_is_leapyear(string a)
//判断in SHT Calendar是否是闰年,若是则返回1,反之返回0.
{
	if ((get_digitsum(a) + atoi(a.c_str()))%13 ==0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

bool Gregorian_is_leapyear(int y)
//判断in Gregorian Calendar是否是闰年,若是则返回1,反之返回0.
{
	if ((((y%4)==0)&&((y%100)!=0))||(((y%400)==0)&&((y%4000)!=0)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int get_leapmonth(string a)
{
	int m = ((atoi(a.c_str())-get_digitsum(a))%6+1);
	return m;
}

int days_until_Gregoriandate(int y,int m,int d)
{
	//start from 1.1.1
	int Gregorian_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int Gregorian_months_leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int y1=1;
	int m1= 1;
	int d1 = 1;
	int days = 0;
	for (int y1=1;y1<y;y1++)
	//add from years
	{
		if (Gregorian_is_leapyear(y1)==0)
		{
			days=days+365;
		}
		else
		{
			days=days+366;
		}	
	}
	for (int m1=1;m1<m;m1++)
	//add from months
	{
		if (Gregorian_is_leapyear(y)==0)
		{
			days=days+Gregorian_months[m1-1];
		}
		else
		{
			days=days+Gregorian_months_leap[m1-1];
		}
	}
	while (d1<=d)
	//add from days
	{
		d1++;
		days=days+1;
	}
	return days;
}

int days_until_SHTdate(int y,int m,int d)
//notice the difference eg:Sist A, 120 and SIST A, 120 ,month name means the input month is SIST,SEM or not
{
	//start from 1.1.1
	int y1=1;
	int m1= 1;
	int d1 = 1;
	int days = 0;
	string add_year = "";
	string year = int_to_string(y);

	for (y1=1;y1<y;y1++)
	//add from years
	{
		for (int i=1;i<=6;i++)
		{
			days=days+(60 + (10*y1 - i)%3);
		}
		add_year = int_to_string(y1);
		if (SHT_is_leapyear(add_year)==0)
		//this SHT year is a normal year
		{
			days = days + 0;
		}
		else
		//this SHT year is a leap year
		{
			if (get_leapmonth(add_year)==1)
			{
				days = days + (60 + (10*y1 - 1)%3);
			}
			else if (get_leapmonth(add_year)==4)
			{
				days = days + (60 + (10*y1 - 4)%3);
			}
		}	
	}
	//add from months
	if (SHT_is_leapyear(year)==0)
	//this input SHT year is a normal year
	{
		for (m1=1;m1<m;m1++)
		{
			days = days + (60 + (10*y - m1)%3);
		}
	}
	else
	//this input SHT year is a leap year
	{
		if (m<=get_leapmonth(year))
		{
			for (m1=1;m1<m;m1++)
			{
				days = days + (60 + (10*y - m1)%3);
			}
		}
		else
		{
			if (m==10)
			{
				days =  days + (60 + (10*y - 1)%3);
			}
			else if (m==40)
			{
				for (m1=1;m1<=4;m1++)
				{
					days = days + (60 + (10*y - m1)%3);
				}
			}
			else
			{
				for (m1=1;m1<m;m1++)/////////////////////////////////erase a =
				{
					days = days + (60 + (10*y - m1)%3);
				}
				if (get_leapmonth(year)==1)
				{
					days =  days + (60 + (10*y - 1)%3);
				}
				else if (get_leapmonth(year)==4)
				{
					days =  days + (60 + (10*y - 4)%3);
				}
			}
		}
	}
	while (d1<=d)
	//add from days
	{
		d1++;
		days=days+1;
	}
	return days;	
}

string int_to_string(int a)
{
	if (a<=9)
	{
		char s[1];
		sprintf(s,"%d",a);
		string b = s;
		return b;
	}
	else if (a>=10&&a<=99)
	{
		char s[2];
		sprintf(s,"%d",a);
		string b = s;
		return b;
	}
	else if (a>=100&&a<=999)
	{
		char s[3];
		sprintf(s,"%d",a);
		string b = s;
		return b;
	}
	else if (a>=1000&&a<=9999)
	{
		char s[4];
		sprintf(s,"%d",a);
		string b = s;
		return b;
	}
}
string Gregorian_to_SHT(int y,int m,int d,int sign)
{
	string SHT_months_name[13]={"none","Sist","SIST","Spst","SPST","Slst","SLST","Sem","SEM","Sials","SIAIS","Ihuman","IHUMAN"};
	int past_days_Gregorian = days_until_Gregoriandate(y,m,d);
	//SHT_Calendar starts from 1.1.1
	int SHT_y = 1;
	int SHT_m=1;
	int SHT_d =1;
	//get the year of the SHT date
	while (days_until_SHTdate(SHT_y,1,1)<=past_days_Gregorian)
	{

		SHT_y = SHT_y +1;
	}
	SHT_y = SHT_y-1;
	string SHT_year = int_to_string(SHT_y);
	if (SHT_is_leapyear(SHT_year)==0)
	//convert to  SHT ,it's a normal year
	{
		//get the month of the SHT date
		while (days_until_SHTdate(SHT_y,SHT_m,1)<=past_days_Gregorian)
		{
			SHT_m = SHT_m + 1;
		}	
		SHT_m = SHT_m - 1;
	}
	else 
	//convert to  SHT ,it's a leap year
	{
		//get the month of the SHT date
		if (days_until_SHTdate(SHT_y,10,1)>past_days_Gregorian)
		{
			SHT_m = 1;
		}
		else if ((days_until_SHTdate(SHT_y,10,1)<=past_days_Gregorian)&&(days_until_SHTdate(SHT_y,2,1)>past_days_Gregorian))
		{
			SHT_m = 10;
		}
		else if ((days_until_SHTdate(SHT_y,40,1)<=past_days_Gregorian)&&(days_until_SHTdate(SHT_y,5,1)>past_days_Gregorian))
		{
			SHT_m = 40;
		}
		else if ((days_until_SHTdate(SHT_y,4,1)<=past_days_Gregorian)&&(days_until_SHTdate(SHT_y,40,1)>past_days_Gregorian))
		{
			SHT_m = 4;
		}
		else if ((days_until_SHTdate(SHT_y,6,1)<=past_days_Gregorian)&&(days_until_SHTdate(SHT_y,6,63)>=past_days_Gregorian))
		{
			SHT_m = 6;
		}
		else
		{
			while (days_until_SHTdate(SHT_y,SHT_m,1)<=past_days_Gregorian)
			{
				SHT_m = SHT_m + 1;
			}
			SHT_m = SHT_m - 1;
		}
	}
	//get the day of the SHT date
	while (days_until_SHTdate(SHT_y,SHT_m,SHT_d)!=past_days_Gregorian)
	{
		SHT_d = SHT_d + 1;
	}
	//conversion:day
	char hex_day[2];
	sprintf(hex_day,"%X",SHT_d);
	string SHT_day = hex_day;
	string SHT_month = "";
	if (sign ==1)
	//need to cout the conversion
	{
		//conversion : month
		if (SHT_m ==10)
		{
			SHT_month = "SIST";
		}
		else if (SHT_m==40)
		{
			SHT_month = "SEM";
		}
		else 
		{
			SHT_month = SHT_months_name[2*SHT_m-1];
		}
		cout << SHT_month<<" "<<SHT_day<<","<<" "<<SHT_y<<endl;;
		return "done";
	}
	else 
	//return the hexdecimal day
	{
		return SHT_day;
	}
}

//void firstday(int year)
//得到该年的第一天是星期几
//{
//	int a=((year-1)+(year-1)/4-(year-1)/100+(year-1)/400+1)%7;
//}