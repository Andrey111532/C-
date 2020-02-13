#include<iostream>
using namespace std;
class Airplan {
private:
	char *name;
	char *type;
	int capacity_passanger;
	int capacity_cargo;
	int passangers_count;
	int cargo_weight;
	
public:
	Airplan() {
		name = new char[7];
		strcpy_s(name, 7, "noName");
		type = new char[7];
		strcpy_s(type, 7, "noName");
		capacity_passanger = -1;
		capacity_cargo = -1;
		passangers_count = 0;
		cargo_weight = 0;
	}
	Airplan(const char*name, const char*type, int capacity_passanger,
		int capacity_cargo, int passangers_count, int cargo_weight) {
		this->name = new char[strlen(name)+1];
		strcpy_s (this->name, strlen(name) + 1, name);
		this->type = new char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type) + 1, type);
		this->capacity_passanger = capacity_passanger;
		this->capacity_cargo = capacity_cargo;
		this->passangers_count = passangers_count;
		this->cargo_weight = cargo_weight;
	}
	~Airplan() {
		delete[] name;
		delete[] type;
	}
	Airplan(const Airplan &obj) {
		if (this->name != nullptr)delete[] this -> name;
		this->name = new char[strlen(obj.name) + 1];
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
		if (this->type != nullptr)delete[] this->type;
		this->type = new char[strlen(obj.type) + 1];
		strcpy_s(this->type, strlen(obj.type) + 1, obj.type);
		this->capacity_passanger = obj.capacity_passanger;
		this->capacity_cargo = obj.capacity_cargo;
		this->passangers_count = obj.passangers_count;
		this->cargo_weight = obj.cargo_weight;
	}

	Airplan &operator=(const Airplan &obj) {
		if (this->name != nullptr)delete[] this->name;
		this->name = new char[strlen(obj.name) + 1];
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
		if (this->type != nullptr)delete[] this->type;
		this->type = new char[strlen(obj.type) + 1];
		strcpy_s(this->type, strlen(obj.type) + 1, obj.type);
		this->capacity_passanger = obj.capacity_passanger;
		this->capacity_cargo = obj.capacity_cargo;
		this->passangers_count = obj.passangers_count;
		this->cargo_weight = obj.cargo_weight;
		return *this;
	}

	void setName(const char* name) {
		delete[]this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void setType(const char *type) {
		delete[]this->type;
		this->type = new char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type) + 1, type);
	}
	void setCapacity_p(int capacity_p) {
		this->capacity_passanger = capacity_p;
	}
	void setCapacity_c(int capacity_c) {
		this->capacity_cargo = capacity_c;
	}
	void setPassangers_count(int passangers_count) {
		this->passangers_count = passangers_count;
	}
	void setCargo_weight(int cargo_weight) {
		this->cargo_weight = cargo_weight;
	}

	char* getName() {
		return name;
	}
	char* getType() {
		return type;
	}
	int getCapacity_p() {
		return capacity_passanger;
	}
	int getCapacity_c() { 
		return capacity_cargo;
	}
	int getPassangers_count() {
		return passangers_count;
	}
	int getCargo_weight() {
		return cargo_weight;
	}

	bool operator==(const Airplan&obj) {
		return !strcmp(this->type, obj.type);
	}
	bool operator>=(const Airplan&obj) {
		return this->capacity_passanger >= obj.capacity_passanger;
	}
	bool operator<=(const Airplan&obj) {
		return this->capacity_passanger <= obj.capacity_passanger;
	}
	bool operator>(const Airplan&obj) {
		return this->capacity_passanger > obj.capacity_passanger;
	}
	bool operator<(const Airplan&obj) {
		return this->capacity_passanger < obj.capacity_passanger;
	}
	bool operator!=(const Airplan&obj) {
		return this->capacity_passanger != obj.capacity_passanger;
	}

	void operator++() {
		this->passangers_count++;
	}
	void operator--() {
		this->passangers_count--;
	}

	void to_bin(FILE *f) {
		int sz = strlen(name) + 1;
		fwrite(name, sizeof(char), sz, f);
		sz = strlen(type) + 1;
		fwrite(type, sizeof(char), sz, f);
		fwrite(&capacity_passanger, sizeof(int), 1, f);
		fwrite(&capacity_cargo, sizeof(int), 1, f);
		fwrite(&passangers_count, sizeof(int), 1, f);
		fwrite(&cargo_weight, sizeof(int), 1, f);
	}
	void from_bin(FILE *f) {
		int tmp;
		fread_s(&tmp, sizeof(int), sizeof(int), 1, f);
		delete[]name;
		name = new char[tmp];
		fread_s(name, tmp, sizeof(char), tmp, f);
		//------
		fread_s(&tmp, sizeof(int), sizeof(int), 1, f);
		delete[]type;
		type = new char[tmp];
		fread_s(type, tmp, sizeof(char), tmp, f);
		//-----
		fread_s(&capacity_passanger, sizeof(int), sizeof(int), 1, f);
		fread_s(&capacity_cargo, sizeof(int), sizeof(int), 1, f);
		fread_s(&passangers_count, sizeof(int), sizeof(int), 1, f);
		fread_s(&cargo_weight, sizeof(int), sizeof(int), 1, f);
	}
};

class Airport {
private:
	Airplan *arr;
	int count;
public:
	Airport() {
		arr = nullptr;
		count = 0;
	}
	Airport(const char*filename) {
		FILE *f;
		if (fopen_s(&f, filename, "r") != 0) {
			arr = nullptr;
			count = 0;
			return;
		}
		fread_s(&count, sizeof(int), sizeof(int), 1, f);
		arr = new Airplan[count];
		for (int i = 0; i < count; i++)
			arr[i].from_bin(f);
		fclose(f);
	}
	~Airport() {
		delete[] arr;
	}

	void addAirplan(const Airplan x) {
		Airplan *nar = new Airplan[count + 1];
		for (int i = 0; i < count; i++)
			nar[i] = arr[i];
		nar[count] = x;
		count++;
		delete[]arr;
		arr = nar;
	}
	void delAirplan(int index) {
		if (index < 0 || index >= count)return;
		Airplan *nar = new Airplan[count - 1];
		for (int i_old = 0,i_new=0; i_old < count; i_old++) 
			if (i_old!=index) {
				nar[i_new] = arr[i_old];
				i_new++;
			}
		delete[]arr;
		arr = nar;
	}
};