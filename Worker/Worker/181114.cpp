#include <iostream>
#include <cstring>

using namespace std;

/*
- �������� ����̴�						(���)
- �����, ������ �����ϴ� Ŭ���� ������	(ĸ��ȭ)
- ����� �����ϴ� Ŭ����				(������)
- ����� ������ �� ��					(virtual)
- ������, �ӽ����� ����Ƽ Ŭ������ �ۼ��ϼ���
- �������� �޿��� �⺻�޿� �������� ������ �� �ֵ��� ������
- �ӽ��� �ñ����� ����ؼ� ���޵� �� �ֵ��� ������
- ������ �λ���� ���α׷� �ۼ�
*/



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
	//�޿��� ��ȯ�ϴ� �����Լ�
	virtual int GetSalary() const
	{
		return 0;
	}
	//��� ������ ����ϴ� �����Լ�
	virtual void ShowEmployeeInfo() const
	{

	}
};

class SalesEmployee : public Employee
{
private:
	int salary;
	int incentive;
public:
	//������
	SalesEmployee(const char * name, int money, int inc) : Employee(name), salary(money), incentive(inc)
	{}
	//������ ��ȯ�ϴ� �Լ�
	int GetSalary() const //const: ���� ���ϰԲ�
	{
		return (salary+incentive);
	}
	//������ ����� ����ϴ� �Լ�
	void ShowEmployeeInfo() const
	{
		cout << "---������---" << endl;
		ShowYourName();
		cout << "���� + �μ�Ƽ�� : " << GetSalary() << endl;
	}
};

class TemporaryEmployee : public Employee
{
private:
	int pay;
public:
	//������
	TemporaryEmployee(const char * name, int hour) : Employee(name), pay(hour)
	{}
	//������ ��ȯ�ϴ� �Լ�
	int GetSalary() const //const: ���� ���ϰԲ�
	{
		return (5580*pay);
	}
	//������ ����� ����ϴ� �Լ�
	void ShowEmployeeInfo() const
	{
		cout << "---�ӽ���---" << endl;
		ShowYourName();
		cout << "�ñ� : " << GetSalary() << endl;
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
	void ShowEmployeeInfo() const
	{
		cout << "---������---" << endl;
		ShowYourName();
		cout << "���� : " << GetSalary() << endl;
	}
};

class EmployeeHandler
{
private:
	Employee * empList1[50]; //������
	//SalesEmployee * empList2[50];
	//TemporaryEmployee * empList3[50];
	int empNum1;
public:
	//������
	EmployeeHandler() : empNum1(0)//empNum1�ʱ�ȭ
	{

	}
	//������ �Լ�
	void AddEmployee(Employee * emp)
	{
		empList1[empNum1++] = emp;
	}
	//��ü��� ���� ���� ��� �Լ�
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum1; i++)
			empList1[i]->ShowEmployeeInfo();
	}
	//�̹��� �� ���� �հ� �Լ�
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum1; i++)
			sum += empList1[i]->GetSalary();

		cout << "���� �հ� : " << sum << endl;
		empList1[0]->GetSalary();
	}
	//�Ҹ���
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum1; i++)
			delete empList1[i];
	}
};

int main(void)
{
	EmployeeHandler handler;
	handler.AddEmployee(new PermanentWorker("ȫ�浿", 2000000));
	handler.AddEmployee(new SalesEmployee("������", 3000000, 500000));
	handler.AddEmployee(new TemporaryEmployee("�迬��", 200));
	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();

	return 0;
}