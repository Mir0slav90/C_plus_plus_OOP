#include<iostream>
#include<string>
using namespace std;

struct Cars
{
	string brand;
	string color;
	string vin;
	int power;
	Cars();
	Cars(string, string, string, int);
	void read();
	void print();
	int compare(Cars c);

};

Cars :: Cars()
{
	brand = ' ';
	color = ' ';
	vin = ' ';
	power = 0;
}
Cars :: Cars(string b, string c, string v, int p)
{
	brand = b;
	color = c;
	vin = v;
	power = p;
}
void Cars :: read()
{
	cout << "Марка и модел на автомобил: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, brand);

	cout << "Цвят на автомобила: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, color);

	cout << "Номер на двигателя на автомобила: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, vin);

	cout << "Мощност на автомобила(к.с.): ";
	cin >> power;
}
void Cars :: print()
{
	cout << "Марка: " << brand << endl;
	cout << "Цвят: " << color << endl;
	cout << "Номер на двигателя: " << vin << endl;
	cout << "Мощност: " << power << "k.c.\n";
}
int Cars :: compare(Cars c)
{	//Comparing cars by power

	if (power < c.power) return -1;
	else
		if (power > c.power) return 1;
		else return 0;
}

Cars* pointer = NULL;
int count_cars = 0;

void add_car()
{	//Аdds data for a new car

	Cars* pointer_two = pointer;
	count_cars++;
	pointer = new Cars[count_cars];

	if (!pointer)
	{
		cout << "Неуспешно заделена памет!\n";
		count_cars--;
		return;
	}
	for (int i = 0; i < count_cars - 1; i++)
		pointer[i] = pointer_two[i];

	delete[] pointer_two;
	pointer_two = NULL;
	pointer[count_cars - 1].read();

}
void print_all_cars()
{	//Prints the data for all cars

	for (int i = 0; i < count_cars; i++)
		pointer[i].print();
}
int check(string id)
{	//Search for a car by engine number

	for (int i = 0; i < count_cars; i++)
		if (pointer[i].vin == id)
			return i;
	return -1;
}
void find_car()
{	//Searches for a car and if found, prints its details

	string id;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, id);
	int index = check(id);

	if (index != -1)
		pointer[index].print();
	else
		cout << "Не е открит такъв автомобил.\n";
}
void delete_car()
{
	string id;
	cout << "Въведете номер на двигателя: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, id);

	if (check(id) != -1)
	{
		Cars* pointer_two = pointer;
		count_cars--;
		pointer = new Cars[count_cars];
		if (!pointer)
		{
			cout << "Неуспешно заделена памет\n";
			count_cars++;
			return;
		}
		for (int i = 0, j = i; i <= count_cars; i++)
			if (pointer_two[i].vin != id)
				pointer[j++] = pointer_two[i];

		delete[] pointer_two;
		pointer_two = NULL;

	}
	else
		cout << "Не е открит такъв автомобил\n";
}
int main()
{
	system("chcp 1251");
	int choice;

	do
	{
		cout << "1. Добавяне на нов автомобил.\n";
		cout << "2. Отпечатва всички автомобили.\n";
		cout << "3. Отпечатва автомобил по VIN на двигателя.\n";
		cout << "4. Изтрива автомобил по VIN на двигателя.\n";
		cout << "0. Изход от птограмата.\n";
		cin >> choice;

		switch (choice)
		{
		case 0: break;
		case 1: add_car(); break;
		case 2: print_all_cars(); break;
		case 3: find_car(); break;
		case 4: delete_car(); break;
		default:  cout << "Некоректен избор.\n"; break;
		}
	} while (choice);

	return 0;
}