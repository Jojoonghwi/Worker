#include <iostream>
#include <cstring>

using namespace std;

/*
- 정규직은 사원이다						(상속)
- 사원명, 월급을 관리하는 클래스 디자인	(캡슐화)
- 사원을 관리하는 클래스				(다형성)
- 사원들 월급의 총 합					(virtual)
- 간단한 인사관리 프로그램 작성
*/

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
	//급여를 반환하는 가상함수
	virtual int GetSalary() const
	{
		return 0;
	}
	//사원 정보를 출력하는 가상함수
	virtual void ShowEmployeeInfo() const
	{

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
	void ShowEmployeeInfo() const
	{
		ShowYourName();
		cout << "월급 : " << GetSalary() << endl;
	}
};

class EmployeeHandler
{
private:
	Employee * empList[50]; //다형성
	int empNum;
public:
	//생성자
	EmployeeHandler() : empNum(0)//empNum초기화
	{

	}
	//사원등록 함수
	void AddEmployee(Employee * emp)
	{
		empList[empNum++] = emp;
	}
	//전체사원 월급 정보 출력 함수
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowEmployeeInfo();
	}
	//이번달 총 월급 합계 함수
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetSalary();

		cout << "월급 합계 : " << sum << endl;
		empList[0]->GetSalary();
	}
	//소멸자
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	EmployeeHandler handler;
	handler.AddEmployee(new PermanentWorker("홍길동", 200));
	handler.AddEmployee(new PermanentWorker("조중휘", 300));
	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();

	return 0;
}