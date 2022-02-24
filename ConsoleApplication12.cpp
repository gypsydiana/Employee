#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {

private:
	string organization;
	string position;
	double experience;
	string name;
	char gender;
	int age;
	double salary;
	static int count;
public:
	Employee() { // конструктор инициализированный
		string organization{};
		string position{};
		double experience=0;
		string name{};
		char gender{};
		int age=0;
		double salary=0;
		count++; // увеличиваем количество созданных объектов
	}	
	Employee(string organization, string position, double experience, string name, char gender, int age, double salary) {//установка всех полей
		this->age = age;
		this->experience = experience;
		this->salary = salary;
		this->organization = organization;
		this->position = position;
		this->name = name;
		this->gender = gender;
		count++; // увеличиваем количество созданных объектов
	}

	void Vvod() {
		cout << "Введите имя ";
		cin >> name;
		cout << "Введите пол ";
		cin >> gender;
		cout << "Введите возраст ";
		cin >> age;
		cout << "Введите место работы ";
		cin >> organization;
		cout << "Введите должность ";
		cin >> position;
		cout << "Введите стаж ";
		cin >> experience;
		cout << "Введите зарплату ";
		cin >> salary;
	}
	int GetAge() {
		return age;
	}
	double GetExperience() {
		return experience;
	}
	double GetSalary() {
		return salary;
	}
	string GetOrganization() {
		return organization;
	}
	string GetPosition() {
		return position;
	}
	string GetName() {
		return name;
	}
	char GetGender() {
		return gender;
	}
	static void showCount(){//вывод количества работников
		cout << "Количество работников: " << count << endl;
	}
	void ShowWork() {//получение информации о месте работы, занимаемой должности, стаже работы, заработной плате
		setlocale(LC_ALL, "Russian");
		cout << "Место работы - "<< organization << endl;
		cout << "Занимаемая должность - " << position << endl;
		cout << "Стаж работы - " << experience << endl;
		cout << "Заработная плата - " << salary << endl;
		cout << endl;
	}
	void ShowPrivate() {//вывод личных данных
		setlocale(LC_ALL, "Russian");
		cout << "Имя - " << name << endl;
		cout << "Пол м/ж - " << gender << endl;
		cout << "Возраст - " << age << endl;
	}
	void AccrualofSalary(double raise_salary) {//начисление заработной платы
		salary += raise_salary;
		cout << salary << endl;
		cout << endl;
	}
    bool operator< (Employee &other){// перегрузка оператора сравнения 
		return this->salary < other.salary;
	}
	bool operator== (Employee &other) {// перегрузка оператора сравнения 
		return this->salary == other.salary;
	}
	void Comparison(Employee &second) {//сравнение двух объектов
		if (*this < second) {
			cout << "Второй человек богаче, его имя:" << second.name << endl;
		}
		else if (*this == second) {
			cout << "Первый человек и второй человек богаче, их имена:" << second.name <<' '<<this->name<< endl;
		}
		else {
			cout << "Первый человек богаче, его имя:" << this->name<< endl;
		}
	}
	Employee &operator =(Employee &other) {//перегрузка оператора присваивания
		this->position = other.position;
		return *this;
	}	
	~Employee() { // деструктор
		count--; // уменьшаем количество созданных объектов
	}

};


int Employee::count=0;// инициализация статического члена класса

int main() {
	setlocale(LC_ALL, "Russian");//указатель языкового стандарта в случае ввода слова на кириллице
//создание объектов
	Employee emp1("reu", "student", 1, "Adelan_Calakhova", 'w', 18, 7000);
	Employee emp2("reu", "teacher", 32, "Teya_Yanovna", 'w', 90, 100000);
	Employee emp3("reu", "student", 2, "Diana_Gallinger", 'w', 18, 3000);
	Employee emp4("reu", "student", 3, "Roman_Shirokov", 'm', 18, 4000);
	const int len = 4;
	Employee mas[len] = { emp1, emp2, emp3, emp4 };// Создание массива объектов класса EMPLOYEE.
	emp1.showCount();
	cout << endl;
	cout << "Личные данные и информация о работе " << endl;
	cout << endl;
	for (int i = 0; i < len; i++) {
		mas[i].ShowPrivate();
		mas[i].ShowWork();
	}
	double raise_salary;
	cout << "Введите начисление зарплаты ";
	cin >> raise_salary;
	cout << endl;
	cout << "Зарплата 1 человека ";
	mas[0].AccrualofSalary(raise_salary);
	cout << "Зарплата 2 человека ";
	mas[1].AccrualofSalary(raise_salary);
	cout << "Зарплата 3 человека ";
	mas[2].AccrualofSalary(raise_salary);
	cout << "Зарплата 4 человека ";
	mas[3].AccrualofSalary(raise_salary);
	cout << endl;
	mas[0] = mas[1];
	mas[0].Comparison(mas[1]);
	cout << endl;
	for (int i = 0; i < len; i++) {
		mas[i].ShowPrivate();
		mas[i].ShowWork();
	}
	cout << endl;
	return 0;
}
