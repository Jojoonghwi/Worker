#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
	char name[100];
public:
	//생성자
	Employee(const char * name)
	{
		strcpy(this->name, name);
	}
	//사원 이름 출력 함수
	void ShowYourName() const
	{
		cout << "이름 : " << name << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	//생성자
	PermanentWorker(const char * name, int money) : Employee(name), salary(money)
	{}
	//월급을 반환하는 함수
	int GetSalary() const //const: 수정 못하게끔
	{
		return salary;
	}
	//정규직 사원을 출력하는 함수
};

class EmployeeHandler
{
private:
	Employee * empList[50];
	int empNum;
public:
	//생성자
	//사원등록 함수
	//전체사원 급여정보 출력 함수
	//이번달 총 월급 합계 함수
	//소멸자
};

int main(void)
{
	EmployeeHandler handler;
	//handler.AddEmpolyee(new PermanentWorker("홍길동", 200));
	//handler.ShowAllSalaryInfo();
	//handler.ShowTotalSalary

	return 0;
}