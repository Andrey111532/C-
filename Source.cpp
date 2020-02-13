#include<string>
#include<iostream>
#include<fstream>
#include <stdlib.h>
using namespace std;
#define LINES 100 // максимальное количество строк в файле

class Animal {
	string name;
	int t;			//temperature
protected:
	Animal() {
		name = "empty";
		t = -273;
	}
	Animal(string name, int t) {
		this->name = name;
		this->t = t;
	}
	string getName() {
		return name;
	}
	int getTemperature() {
		return t;
	}
	void setName(string name) {
		this->name = name;
	}
	void setTemperature(int t) {
		this->t = t;
	}
	virtual void moving() = 0;
	virtual void saying() = 0;

};
class Cat :public Animal {
	string colour;
	int wool_lenght;
public:
	Cat() {
		setTemperature(38);
		colour = "white";
		wool_lenght = 0;
	}
	Cat(string name, string colour, int wool_lenth) {
		setTemperature(38);
		this->colour = colour;
		this->wool_lenght = wool_lenght;
	}
	void moving() {
		cout << "Running";
	}
	void saying() {
		cout << "Meow";
	}
};
class Whale :public Animal {
	string type;
	int lenth;
public:
	Whale() {
		setTemperature(37);
		type = "empty";
		lenth = 0;
	}
	Whale(string name, string type, int lenth) {
		setName(name);
		setTemperature(37);
		this->type = type;
		this->lenth = lenth;
	}
	void saying() {
		cout << "Ну допустим .... МУ";
	}
	void moving() {
		cout << "swiming";
	}

};

void main() {



	/*ofstream fout;
	fout.open("test.txt");
	fout << "Hello World";
	fout.close();*/

//	setlocale(LC_ALL, "RUS");
//	system("chcp 1251");
//	system("cls");
//	char line[LINES][100];
//	char str[30];
//	char s[] = "|                              |                |                              |";
//	 Ввод данных для размещаемой строки
//	cout << "ФИО: ";
//	cin.getline(str, 30); // вводим ФИО
//	for (int i = 0; str[i] != '\0'; i++) // копируем в строку без 0
//		s[i + 2] = str[i];               // начиная с указанной позиции
//	cout << "Дата: ";
//	cin.getline(str, 30);
//	for (int i = 0; str[i] != '\0'; i++)
//		s[i + 33] = str[i];
//	cout << "Хобби: ";
//	cin.getline(str, 30);
//	for (int i = 0; str[i] != '\0'; i++)
//		s[i + 50] = str[i];
//
//	fstream inOut;
//	inOut.open("file.txt", ios::in); // открываем файл для ввода
//									  Считываем из файла имеющиеся данные
//	int count = 0;
//	while (inOut.getline(line[count], 100)) count++;
//	inOut.close(); // закрываем файл
//
//	inOut.open("file.txt", ios::out); // открываем файл для вывода
//	inOut << "--------------------------------------------------------------------------------" << endl;
//	inOut << "|   ФИО                        |  Дата          | Хобби                        |" << endl;
//	inOut << "--------------------------------------------------------------------------------" << endl;
//	inOut << s << endl; // выводим сформированную строку
//	inOut << "--------------------------------------------------------------------------------" << endl;
//	 Выводим обратно в файл все строки кроме "шапки" (первые 3 строки)
//	for (int j = 3; j < count; j++)
//	{
//		inOut << line[j] << endl;
//	}
//	inOut.close();
//	cin.get();
//	return;
//}

	
//void main() {
//
//	/*1.	Дано целое число N(> 0) и строка S.
//	Преобразовать строку S в строку длины N следующим образом :
//	если длина строки S больше N, то отбросить первые символы,
//	если длина строки S меньше N, то в ее начало добавить символы «.»(точка).*/
//
//	int N=0;
//	string S="Vasya";
//	cin >> N;
//	if (size(S) > N) {
//		S.erase(0, 2);
//	}
//	else if (size(S) < N) {
//		S.insert(0, ".");
//	}
//
//	
//
//	cout << S << endl;
//
//	system("pause");
//}



//void main() {
//	/*2.	Даны целые положительные числа N1 и N2 и строки S1 и S2.
//	Получить из этих строк новую строку, содержащую первые N1 символов строки S1
//	и последние N2 символов строки S2(в указанном порядке).*/
//	int N1 = 0, N2 = 0;
//	string S3;
//	string S1 = "Vasya", S2 = "Lexa";
//	cin >> N1 >> N2;
//	S3 = S1.substr(0, N1);
//	S3 += S2.substr(size(S2) - N2);
//	cout << S3;
//
//	system("pause");
//}


////3.	Дан символ C и строка S.Удвоить каждое вхождение символа C в строку S.
//void main() {
//	char C='a';
//	string S="Vasya";
//	string S2;
//	int sz = size(S);
//	for (int i = 0; i < sz; i++)
//	{
//		S2 += S[i];
//		if (S[i] == C)
//		{
//			S2 += S[i];
//		}
//
//	}
//	cout << S2 << endl;
//     
//
//	system("pause");
//}



////4.	Дан символ C и строки S,
////S0.Перед каждым вхождением символа C в строку S вставить строку S0.
//void main() {
//	char C='c';
//	string S="bcbc", S0="lexa";
//	/*int sz = size(S);*/
//	for (int i = 0; i < size(S); i++) {
//		if (S[i] == C) {
//			S.insert(i, S0);
//			i += size(S0);
//		}
//	}
//
//	cout << S << endl;
//
//
//	system("pause");
//}



////5.	Дан символ C и строки S, S0.
////После каждого вхождения символа C в строку S вставить строку S0.
//void main() {
//	char C='c';
//	string S="bcbc", S0="lexa";
//	for (int i = 0; i < size(S); i++) {
//		if (S[i] == C) {
//			S.insert(i+1, S0);
//			i += size(S0);
//		}
//	}
//
//	cout << S << endl;
//
//
//	system("pause");
//}


////6.	Даны строки S и S0.Проверить,
////содержится ли строка S0 в строке S.
////Если содержится, то вывести True, если не содержится, то вывести False.
//void main() {
//	string S="lexaEgypt", S0="lexa";
//	if (!S.find(S0))
//		cout << "cool";
//	else cout << "not";
//
//	system("pause");
//}


//7.	Даны строки S и S0.Найти количество вхождений строки S0 в строку S.

//void main() {
//	int count = 0;
//	string S="lexaEglexayptlexalexa", S0="lexa";
//	for (int i = 0; i < size(S); i++) {
//		if (S[i] == S0[0])
//			if (S.substr(i, size(S0)) == S0)
//			{
//				count++;
//				i += size(S0) - 1;
//			}
//	}
//	cout << count << endl;
//		system("pause");
//	}

////8.	Даны строки S и S0.Удалить из строки S первую подстроку, совпадающую с S0.Если совпадающих подстрок нет, то вывести строку S без изменений.
//void main() {
//	string S="lexagolexa", S0="lexa";
//	if (!S.find(S0)) {
//		S.erase(0, size(S0));
//		cout << S<<endl;
//	}
//	else cout << S<<endl;
//
//	system("pause");
//}

//9.	Даны строки S и S0.Удалить из строки S все подстроки, 
//совпадающие с S0.Если совпадающих подстрок нет,
//то вывести строку S без изменений.

//void main() {
//		int count = 0;
//	
//
//
//	system("pause");
//}