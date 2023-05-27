#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

struct airplane_name
{
	int id;
	int fuel;
	int time;
	airplane_name* next;
	airplane_name(int id_ = 0, int fuel_ = 0) : id(id_), fuel(fuel_), time(0), next(NULL) {};
};

class landing_queue
{
public:
	airplane_name* lfront;
	airplane_name* lback;
	int landing_total_time;
	int saving_fuel;
	int crush;
	int lsize;
	landing_queue() : lfront(0), lback(0), lsize(0), landing_total_time(0), saving_fuel(0), crush(0) {}
	int lget_id();
	int lget_front();
	int lget_fuel();
	void landingpush(int, int);
	void landingpop();
	bool lIsEmpty();
	void landing_queue_update(landing_queue);
	int emergency_check(landing_queue);
	void lprintin(landing_queue);
};

void landing_queue::landingpush(int id_, int fuel_)
{
	if (lIsEmpty())
	{
		lfront = new airplane_name(id_, fuel_);
		lback = lfront;
		lsize++;
		return;
	}

	else
	{
		airplane_name* newNode = new airplane_name(id_, fuel_);
		lback->next = newNode;
		lback = newNode;
		lsize++;
	}
}

void landing_queue::landingpop()
{
	airplane_name* deletnode = lfront;
	landing_total_time += lfront->time;
	saving_fuel += lfront->fuel;
	lfront = lfront->next;

	delete deletnode;
	deletnode = 0;
	lsize--;
}

bool landing_queue::lIsEmpty()
{
	return (lsize == 0);
}

int landing_queue::lget_id()
{
	if (lIsEmpty())
	{
		return -1;
	}
	return lback->id;
}

int landing_queue::lget_front()
{
	if (lIsEmpty())
	{
		return -1;
	}
	return lfront->id;
}

int landing_queue::lget_fuel()
{
	if (lIsEmpty())
	{
		return -1;
	}
	return lback->fuel;
}

int landing_queue::emergency_check(landing_queue input)
{
	if (input.lfront != NULL)
	{
		if (input.lfront->fuel == 0)
		{
			return input.lfront->id;
		}
	}

	return -1;
}

void landing_queue::lprintin(landing_queue input)
{
	airplane_name* current = input.lfront;

	if (current == NULL) cout << "(-1 , -1)";

	while (current != NULL)
	{
		cout << "(" << current->id << "," << current->fuel << ")" << " ";
		current = current->next;
	}

	cout << "\n";
}

void landing_queue::landing_queue_update(landing_queue input)
{
	airplane_name* current = input.lfront;

	while (current != NULL)
	{
		if (current->fuel < 0)
		{
			crush++;
		}
		current->fuel--;
		current->time++;
		current = current->next;
	}

}

// takeoff
class takeoff_queue
{
public:
	airplane_name* tfront;
	airplane_name* tback;
	int takeoff_total_time;
	int tsize;
	takeoff_queue() : tfront(0), tback(0), tsize(0), takeoff_total_time(0) {}
	int tget_id();
	int tget_front();
	void takeoffpush(int);
	void takeoffpop();
	bool tIsEmpty();
	void tprintin(takeoff_queue);
	void takeoff_queue_update(takeoff_queue);
};

void takeoff_queue::takeoffpush(int id_)
{
	if (tIsEmpty())
	{
		tfront = new airplane_name(id_);
		tback = tfront;
		tsize++;
	}

	else
	{
		airplane_name* newNode = new airplane_name(id_);
		tback->next = newNode;
		tback = newNode;
		tsize++;
	}
}

void takeoff_queue::takeoffpop()
{
	airplane_name* deletnode = tfront;
	takeoff_total_time += tfront->time;
	tfront = tfront->next;

	delete deletnode;
	deletnode = 0;
	tsize--;
}

bool takeoff_queue::tIsEmpty()
{
	return (tsize == 0);
}

int takeoff_queue::tget_id()
{
	if (tIsEmpty())
	{
		return -1;
	}
	return tback->id;
}

int takeoff_queue::tget_front()
{
	if (tIsEmpty())
	{
		return -1;
	}
	return tfront->id;
}

void takeoff_queue::tprintin(takeoff_queue input)
{
	airplane_name* current = input.tfront;

	if (current == NULL) cout << "-1";

	while (current != NULL)
	{
		cout << current->id << " , ";
		current = current->next;
	}

	cout << "\n";
}

void takeoff_queue::takeoff_queue_update(takeoff_queue input)
{
	airplane_name* current = input.tfront;

	while (current != NULL)
	{
		current->time++;
		current = current->next;
	}

}

// emergency 
class emergency_queue
{
public:
	airplane_name* efront;
	airplane_name* eback;
	int esize;
	int emergency_number;
	emergency_queue() : efront(0), eback(0), esize(0), emergency_number(0) {}
	int eget_id();
	int eget_front();
	void emergencypush(int);
	void emergencypop();
	bool eIsEmpty();
	void eprintin(emergency_queue);
};

int emergency_queue::eget_id()
{
	if (eIsEmpty())
	{
		return -1;
	}
	return eback->id;
}

int emergency_queue::eget_front()
{
	if (eIsEmpty())
	{
		return -1;
	}
	return efront->id;
}

bool emergency_queue::eIsEmpty()
{
	return (esize == 0);
}

void emergency_queue::emergencypush(int id_)
{
	if (eIsEmpty())
	{
		efront = new airplane_name(id_);
		eback = efront;
		esize++;
		emergency_number++;
	}

	else
	{
		airplane_name* newNode = new airplane_name(id_);
		eback->next = newNode;
		eback = newNode;
		esize++;
		emergency_number++;
	}
}

void emergency_queue::emergencypop()
{
	airplane_name* deletnode = efront;
	efront = efront->next;

	delete deletnode;
	deletnode = 0;
	esize--;
}

void emergency_queue::eprintin(emergency_queue input)
{
	airplane_name* current = input.efront;

	if (current == NULL) cout << "-1";

	while (current != NULL)
	{
		cout << current->id << " , ";
		current = current->next;
	}

	cout << "\n";
}

void show_anwser(int, float, float, float, int, int);

int main()
{
	landing_queue RT1, RT2, RT3, RT4, RT5, RT6;
	takeoff_queue T1, T2, T3, T4;
	emergency_queue emergenecy;
	landing_queue ltemp;
	takeoff_queue ttemp;
	emergency_queue etemp;
	float takeoff_time = 0;
	float landing_time = 0;
	float total_saving_fuel = 0;
	int total_crush = 0;
	int landing = 1;
	int takeoff = 0;
	int stumulate_times = 0;
	srand(time(NULL));

	cout << "stimulate times : "; cin >> stumulate_times;
	cout << "\n";

	cout << "\n---------------------------------------------------------------\n\n";
	for (int i = 0; i < stumulate_times; i++)
	{
		if (i >= 0 && i <= 4)
		{
			cout << "T = " << i + 1 << endl;
			// landing in

			int nlanding = rand() % 5;
			cout << "landing plane : ";
			for (int j = 0; j < nlanding; j++)
			{
				int fuel = rand()%10 + 1;

				int sum_landing1 = RT1.lsize + RT2.lsize;
				int sum_landing2 = RT3.lsize + RT4.lsize;
				int sum_landing3 = RT5.lsize + RT6.lsize;
				cout << "(" << landing << "," << fuel << ")" << " , ";

				if (sum_landing1 <= sum_landing2 && sum_landing1 <= sum_landing3)
				{
					if (RT1.lsize <= RT2.lsize) RT1.landingpush(landing, fuel);
					else RT2.landingpush(landing, fuel);
				}

				else if (sum_landing2 <= sum_landing1 && sum_landing2 <= sum_landing3)
				{
					if (RT3.lsize <= RT4.lsize) RT3.landingpush(landing, fuel);
					else RT4.landingpush(landing, fuel);
				}

				else if (sum_landing3 <= sum_landing1 && sum_landing3 <= sum_landing2)
				{
					if (RT5.lsize <= RT6.lsize) RT5.landingpush(landing, fuel);
					else RT6.landingpush(landing, fuel);
				}

				landing = landing + 2;

			}

			cout << "\n";

			// takeoff in

			int ntakeoff = rand() % 4;
			cout << "takeoff plane : ";
			for (int j = 0; j < ntakeoff; j++)
			{
				cout << takeoff << " , ";

				if (T1.tsize <= T2.tsize && T1.tsize <= T3.tsize && T1.tsize <= T4.tsize) T1.takeoffpush(takeoff);
				else if (T4.tsize <= T1.tsize && T4.tsize <= T2.tsize && T4.tsize <= T3.tsize) T4.takeoffpush(takeoff);
				else if (T3.tsize <= T1.tsize && T3.tsize <= T2.tsize && T3.tsize <= T4.tsize) T3.takeoffpush(takeoff);
				else if (T2.tsize <= T1.tsize && T2.tsize <= T3.tsize && T2.tsize <= T4.tsize) T2.takeoffpush(takeoff);

				takeoff = takeoff + 2;

			}

			cout << "\n";
			// emergency check
			if (ltemp.emergency_check(RT1) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT1));
				RT1.landingpop();
			}
			else if (ltemp.emergency_check(RT2) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT2));
				RT2.landingpop();
			}
			else if (ltemp.emergency_check(RT3) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT3));
				RT3.landingpop();
			}
			else if (ltemp.emergency_check(RT4) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT4));
				RT4.landingpop();
			}
			else if (ltemp.emergency_check(RT5) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT5));
				RT5.landingpop();
			}
			else if (ltemp.emergency_check(RT6) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT6));
				RT6.landingpop();
			}
			cout << "emergency : ";
			etemp.eprintin(emergenecy);

			//runway in
			cout << "\n---------------------------------------------------------------\n";

			//runway1
			if (!emergenecy.eIsEmpty())
			{
				cout << "Runway1 (" << emergenecy.eget_front() << ")" << endl;
				emergenecy.emergencypop();
			}
			else if (!T1.tIsEmpty())
			{
				cout << "Runway1 (" << T1.tget_front() << ")" << endl;
				T1.takeoffpop();
			}
			else cout << "Runway1 (-1)" << endl;
			cout << " T : ";
			ttemp.tprintin(T1);
			cout << "\n";

			//runway2
			if (!emergenecy.eIsEmpty())
			{
				cout << "Runway2 (" << emergenecy.eget_front() << ")" << endl;
				emergenecy.emergencypop();
			}
			else if (!RT1.lIsEmpty() || !RT2.lIsEmpty())
			{
				if (RT1.lsize >= RT2.lsize)
				{
					cout << "Runway2 (" << RT1.lget_front() << ")" << endl;
					RT1.landingpop();
				}
				else
				{
					cout << "Runway2 (" << RT2.lget_front() << ")" << endl;
					RT2.landingpop();
				}
			}

			else if (!T2.tIsEmpty())
			{
				cout << "Runway2 (" << T2.tget_front() << ")" << endl;
				T2.takeoffpop();
			}
			else cout << "Runway2 (-1)" << endl;
			cout << "L1 : ";
			ltemp.lprintin(RT1);
			cout << "L2 : ";
			ltemp.lprintin(RT2);
			cout << " T : ";
			ttemp.tprintin(T2);
			cout << "\n";

			//runway3
			if (!emergenecy.eIsEmpty())
			{
				cout << "Runway3 (" << emergenecy.eget_front() << ")" << endl;
				emergenecy.emergencypop();
			}
			else if (!RT3.lIsEmpty() || !RT4.lIsEmpty())
			{
				if (RT3.lsize >= RT4.lsize)
				{
					cout << "Runway3 (" << RT3.lget_front() << ")" << endl;
					RT3.landingpop();
				}
				else
				{
					cout << "Runway3 (" << RT4.lget_front() << ")" << endl;
					RT4.landingpop();
				}
			}

			else if (!T3.tIsEmpty())
			{
				cout << "Runway3 (" << T3.tget_front() << ")" << endl;
				T3.takeoffpop();
			}
			else cout << "Runway3 (-1)" << endl;
			cout << "L1 : ";
			ltemp.lprintin(RT3);
			cout << "L2 : ";
			ltemp.lprintin(RT4);
			cout << " T : ";
			ttemp.tprintin(T3);
			cout << "\n";

			//T4
			if (!emergenecy.eIsEmpty())
			{
				cout << "Runway4 (" << emergenecy.eget_front() << ")" << endl;
				emergenecy.emergencypop();
			}
			else if (!RT5.lIsEmpty() || !RT6.lIsEmpty())
			{
				if (RT5.lsize >= RT6.lsize)
				{
					cout << "Runway4 (" << RT5.lget_front() << ")" << endl;
					RT5.landingpop();
				}
				else
				{
					cout << "Runway4 (" << RT6.lget_front() << ")" << endl;
					RT6.landingpop();
				}
			}

			else if (!T4.tIsEmpty())
			{
				cout << "Runway4 (" << T4.tget_front() << ")" << endl;
				T4.takeoffpop();
			}
			else cout << "Runway4 (-1)" << endl;
			cout << "L1 : ";
			ltemp.lprintin(RT5);
			cout << "L2 : ";
			ltemp.lprintin(RT6);
			cout << " T : ";
			ttemp.tprintin(T4);
			cout << "\n";
			cout << "---------------------------------------------------------------\n\n";
		}

		else
		{
			// landing in
			int nlanding = rand() % 5;
			for (int j = 0; j < nlanding; j++)
			{
				int fuel = rand()%10 + 1;

				int sum_landing1 = RT1.lsize + RT2.lsize;
				int sum_landing2 = RT3.lsize + RT4.lsize;
				int sum_landing3 = RT5.lsize + RT6.lsize;

				if (sum_landing1 <= sum_landing2 && sum_landing1 <= sum_landing3)
				{
					if (RT1.lsize <= RT2.lsize) RT1.landingpush(landing, fuel);
					else RT2.landingpush(landing, fuel);
				}

				else if (sum_landing2 <= sum_landing1 && sum_landing2 <= sum_landing3)
				{
					if (RT3.lsize <= RT4.lsize) RT3.landingpush(landing, fuel);
					else RT4.landingpush(landing, fuel);
				}

				else if (sum_landing3 <= sum_landing1 && sum_landing3 <= sum_landing2)
				{
					if (RT5.lsize <= RT6.lsize) RT5.landingpush(landing, fuel);
					else RT6.landingpush(landing, fuel);
				}

				landing = landing + 2;

			}

			// takeoff in

			int ntakeoff = rand() % 4;
			for (int j = 0; j < ntakeoff; j++)
			{
				if (T1.tsize <= T2.tsize && T1.tsize <= T3.tsize && T1.tsize <= T4.tsize) T1.takeoffpush(takeoff);
				else if (T4.tsize <= T1.tsize && T4.tsize <= T2.tsize && T4.tsize <= T3.tsize) T4.takeoffpush(takeoff);
				else if (T3.tsize <= T1.tsize && T3.tsize <= T2.tsize && T3.tsize <= T4.tsize) T3.takeoffpush(takeoff);
				else if (T2.tsize <= T1.tsize && T2.tsize <= T3.tsize && T2.tsize <= T4.tsize) T2.takeoffpush(takeoff);

				takeoff = takeoff + 2;

			}

			// emergency check
			if (ltemp.emergency_check(RT1) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT1));
				RT1.landingpop();
			}
			else if (ltemp.emergency_check(RT2) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT2));
				RT2.landingpop();
			}
			else if (ltemp.emergency_check(RT3) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT3));
				RT3.landingpop();
			}
			else if (ltemp.emergency_check(RT4) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT4));
				RT4.landingpop();
			}
			else if (ltemp.emergency_check(RT5) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT5));
				RT5.landingpop();
			}
			else if (ltemp.emergency_check(RT6) != -1)
			{
				emergenecy.emergencypush(ltemp.emergency_check(RT6));
				RT6.landingpop();
			}

			//runway in

				//runway1
			if (!emergenecy.eIsEmpty())
			{
				emergenecy.emergencypop();
			}
			else if (!T1.tIsEmpty())
			{
				T1.takeoffpop();
			}

			//runway2
			if (!emergenecy.eIsEmpty())
			{
				emergenecy.emergencypop();
			}
			else if (!RT1.lIsEmpty() || !RT2.lIsEmpty())
			{
				if (RT1.lsize >= RT2.lsize)
				{
					RT1.landingpop();
				}
				else
				{
					RT2.landingpop();
				}
			}

			else if (!T2.tIsEmpty())
			{
				T2.takeoffpop();
			}

			//runway3
			if (!emergenecy.eIsEmpty())
			{
				emergenecy.emergencypop();
			}
			else if (!RT3.lIsEmpty() || !RT4.lIsEmpty())
			{
				if (RT3.lsize >= RT4.lsize)
				{
					RT3.landingpop();
				}
				else
				{
					RT4.landingpop();
				}
			}

			else if (!T3.tIsEmpty())
			{
				T3.takeoffpop();
			}

			//runway4
			if (!emergenecy.eIsEmpty())
			{
				emergenecy.emergencypop();
			}
			else if (!RT5.lIsEmpty() || !RT6.lIsEmpty())
			{
				if (RT5.lsize >= RT6.lsize)
				{
					RT5.landingpop();
				}
				else
				{
					RT6.landingpop();
				}
			}

			else if (!T4.tIsEmpty())
			{
				T4.takeoffpop();
			}
		}

		ltemp.landing_queue_update(RT1);
		ltemp.landing_queue_update(RT2);
		ltemp.landing_queue_update(RT3);
		ltemp.landing_queue_update(RT4);
		ltemp.landing_queue_update(RT5);
		ltemp.landing_queue_update(RT6);

		ttemp.takeoff_queue_update(T1);
		ttemp.takeoff_queue_update(T2);
		ttemp.takeoff_queue_update(T3);
		ttemp.takeoff_queue_update(T4);

	}


	total_saving_fuel = RT1.saving_fuel + total_saving_fuel + RT2.saving_fuel + RT3.saving_fuel + RT4.saving_fuel + RT5.saving_fuel + RT6.saving_fuel;
	takeoff_time = T1.takeoff_total_time + T2.takeoff_total_time + T3.takeoff_total_time + T4.takeoff_total_time;
	landing_time = RT1.landing_total_time + RT2.landing_total_time + RT3.landing_total_time + RT4.landing_total_time + RT5.landing_total_time + RT6.landing_total_time;
	total_crush = RT1.crush + RT2.crush + RT3.crush + RT4.crush + RT5.crush + RT6.crush;

	show_anwser(stumulate_times, takeoff_time, landing_time, total_saving_fuel, emergenecy.emergency_number, total_crush);
}

void show_anwser(int stumulate_times, float takeofftime, float landingtime, float savingfuel, int emergency_number, int crush)
{
	float avg_takeoff_time = takeofftime / stumulate_times;
	float avg_landing_time = landingtime / stumulate_times;
	float avg_saving_fuel = savingfuel / stumulate_times;

	cout << "                       | Total result |" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "AVG landing time : " << avg_landing_time << "(s)" << endl;
	cout << "AVG takeoff time : " << avg_takeoff_time << "(s)" << endl;
	cout << "AVG saving fuel : " << avg_saving_fuel << "(s)" << endl;
	cout << "Total emergency plane : " << emergency_number << endl;
	cout << "Total crush : " << crush << endl;

}
