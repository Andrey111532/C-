#include <iostream>

using namespace std;

class Man
{
	char* full_name;
	int age;
	char* email;
	char* phone;
	char* sex;
public:
	// Default
	Man()
	{
		full_name = new char[strlen("Kiril Svatoy II") + 1];
		age = 54;
		email = new char[strlen("black.papa@molitva.com") + 1];
		phone = new char[strlen("38(XX)XXX-XXX-X") + 1];
		sex = new char[strlen("M") + 1];

		strcpy_s(full_name, strlen("Kiril Svatoy II") + 1, "Kiril Svatoy II");
		strcpy_s(email, strlen("black.papa@molitva.com") + 1, "black.papa@molitva.com");
		strcpy_s(phone, strlen("38(XX)XXX-XXX-X") + 1, "38(XX)XXX-XXX-X");
		strcpy_s(sex, strlen("M") + 1, "M");
	}
	// NE DEFAULT
	Man(char* full_name,
		int age,
		char* email,
		char* phone,
		char* sex)
	{
		this->full_name = new char[strlen(full_name) + 1];
		this->age = age;
		this->email = new char[strlen(email) + 1];
		this->phone = new char[strlen(phone) + 1];
		this->sex = new char[strlen(sex) + 1];

		strcpy_s(this->full_name, strlen(full_name) + 1, full_name);
		strcpy_s(this->email, strlen(email) + 1, email);
		strcpy_s(this->phone, strlen(phone) + 1, phone);
		strcpy_s(this->sex, strlen(sex) + 1, sex);
	}
	//
	~Man()
	{
		delete[] full_name;
		delete[] email;
		delete[] phone;
		delete[] sex;
		age = 0;
	}

	// Print
	void PrintMan()
	{
		cout << "Full name: " << full_name << '\n';
		cout << "Age: " << age << '\n';
		cout << "Mail: " << email << '\n';
		cout << "Phone: " << phone << '\n';
		cout << "Sex: " << sex << '\n';
	}

	// Return
	char* Return_Full_Name()
	{
		return full_name;
	}
	int& ReturnAge()
	{
		return age;
	}
	char* Return_email()
	{
		return email;
	}
	char* Return_phone()
	{
		return phone;
	}
	char* Return_Sex()
	{
		return sex;
	}
};

class Calcinfo
{
	float base;
	float percent;
	float total;
	float bonus;
	float hour;
	float rate_of_hour;
public:
	Calcinfo()
	{
		base = 0;
		percent = 0;
		total = 0;
		bonus = 0;
		hour = 0;
		rate_of_hour = 0;
	}
	Calcinfo(float base,
		float percent,
		float total,
		float bonus,
		float hour,
		float rate_of_hour)
	{
		this->base = base;
		this->percent = percent;
		this->total = total;
		this->bonus = bonus;
		this->hour = hour;
		this->rate_of_hour = rate_of_hour;
	}
	~Calcinfo()
	{
		base = 0;
		percent = 0;
		total = 0;
		bonus = 0;
		hour = 0;
		rate_of_hour = 0;
	}
	// Print
	void PrintCalcinfo()
	{
		cout << "Base: " << base << '\n';
		cout << "Percent: " << percent << '\n';
		cout << "Total: " << total << '\n';
		cout << "Bonus: " << bonus << '\n';
		cout << "Hour: " << hour << '\n';
		cout << "Rate of hour: " << rate_of_hour << '\n';
	}

	// Return
	float& Return_Base()
	{
		return base;
	}
	float& Return_Percent()
	{
		return percent;
	}
	float& Return_Total()
	{
		return total;
	}
	float& Return_Bonus()
	{
		return bonus;
	}
	float& Return_Hour()
	{
		return hour;
	}
	float& Return_RateOfHour()
	{
		return rate_of_hour;
	}


};


class Employed : public Man, public Calcinfo
{
	int id;
	char* position;

public:
	static int count;
	Employed()
	{
		count++;
		id = count;
		position = nullptr;
	}
	Employed(char* position)
	{
		if (this->position == nullptr)
			delete[] this->position;

		count++;
		id = count;
		this->position = new char[strlen(position) + 1];
		strcpy_s(this->position, strlen(position) + 1, position);
	}
	~Employed()
	{
		delete[] position;
		position = nullptr;
	}

	void PrintEmployed()
	{
		PrintMan();
		PrintCalcinfo();
		cout << "Position: " << position << '\n';
	}

	char* Return_Position()
	{
		return position;
	}

	void YaNePredumal(char* str)
	{
		if (position == nullptr)
			position = new char[strlen(str) + 1];
		strcpy_s(position, strlen(str) + 1, str);
	}


};
int Employed::count = 0;

//class List
//{
//	myData* head;
//	myData* tail;
//
//public:
//	List()
//	{
//
//	}
//
//
//};

struct myData
{
	Employed information;
	myData* next;

};



void main()
{
	int sz = 200;
	char* str = new char[sz];
	cout << "---> ";
	gets_s(str, sz);
	Employed X;

	X.YaNePredumal(str);
	X.PrintEmployed();
	cout << "=================" << '\n';
	Employed Y;
	Y.YaNePredumal(str);
	Y.PrintEmployed();
	system("pause");
}