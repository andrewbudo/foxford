#include <iostream>
#include <vector>
using namespace std;

struct Alarm {
	Alarm() {}
	Alarm(int d, int h, int m) : day(d), hour(h), minutes(m) {
		time_in_minutes = d * 24 * 60 + h * 60 + m;
	}
	int day;
	int hour;
	int minutes;
	int time_in_minutes;
};

int main() {
	int current_day;
	int current_hour;
	int current_minutes;
	cin >> current_day >> current_hour >> current_minutes;

	const int current_time_in_minutes = current_day * 24 * 60 + current_hour * 60 + current_minutes;


	int alarmCounts;
	cin >> alarmCounts;

	vector<Alarm> alarm_container;
	for (int i = 0; i < alarmCounts; i++)
	{
		int day, hour, minutes;
		cin >> day >> hour >> minutes;
		if (day == 0) {
			for (int j = 1; j <= 7; j++)
			{
				Alarm alarm(j, hour, minutes);
				alarm_container.push_back(alarm);
			}
		}
		else {
			Alarm alarm(day, hour, minutes);
			alarm_container.push_back(alarm);
		}
	}

	int min_interval = 2147483647;
	Alarm alarm;
	bool flag = false;
	for (Alarm a : alarm_container) {
		int delta = a.time_in_minutes - current_time_in_minutes;
		if (delta >= 0 && delta < min_interval) {
			min_interval = delta;
			alarm = a;
			flag = true;
		}
	}

	if (!flag) {
		int minutes_in_week = 7 * 24 * 60;
		for (Alarm a : alarm_container) {
			int delta = a.time_in_minutes + minutes_in_week - current_time_in_minutes;
			if (delta >= 0 && delta < min_interval) {
				min_interval = delta;
				alarm = a;
				flag = true;
			}
		}
	}

	if (flag) {
		cout << alarm.day << " " << alarm.hour << " " << alarm.minutes << "\n";
	}
	

	return 0;
}

/* Budo Test
7 10 20
1
6 0 0
*/