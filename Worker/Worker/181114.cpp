#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
	char name[100];
public:
	//������
	Employee(const char * name)
	{
		strcpy(this->name, name);
	}
	//��� �̸� ��� �Լ�
	void ShowYourName() const
	{
		cout << "�̸� : " << name << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	//������
	PermanentWorker(const char * name, int money) : Employee(name), salary(money)
	{}
	//������ ��ȯ�ϴ� �Լ�
	int GetSalary() const //const: ���� ���ϰԲ�
	{
		return salary;
	}
	//������ ����� ����ϴ� �Լ�
};

class EmployeeHandler
{
private:
	Employee * empList[50];
	int empNum;
public:
	//������
	//������ �Լ�
	//��ü��� �޿����� ��� �Լ�
	//�̹��� �� ���� �հ� �Լ�
	//�Ҹ���
};

int main(void)
{
	EmployeeHandler handler;
	//handler.AddEmpolyee(new PermanentWorker("ȫ�浿", 200));
	//handler.ShowAllSalaryInfo();
	//handler.ShowTotalSalary

	return 0;
}