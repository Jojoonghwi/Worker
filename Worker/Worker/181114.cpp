#include <iostream>
#include <cstring>

using namespace std;

/*
- 정규직은 사원이다						(상속)
- 사원명, 월급을 관리하는 클래스 디자인	(캡슐화)
- 사원을 관리하는 클래스				(다형성)
- 사원들 월급의 총 합					(virtual)
- 영업직, 임시직의 엔터티 클래스를 작성하세요
- 영업직의 급여는 기본급에 성과급을 포함할 수 있도록 디자인
- 임시직 시급으로 계산해서 지급될 수 있도록 디자인
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

class SalesEmployee : public Employee
{
private:
	int salary;
	int incentive;
public:
	//생성자
	SalesEmployee(const char * name, int money, int inc) : Employee(name), salary(money), incentive(inc)
	{}
	//월급을 반환하는 함수
	int GetSalary() const //const: 수정 못하게끔
	{
		return (salary+incentive);
	}
	//정규직 사원을 출력하는 함수
	void ShowEmployeeInfo() const
	{
		cout << "---영업직---" << endl;
		ShowYourName();
		cout << "월급 + 인센티브 : " << GetSalary() << endl << endl;
	}
};

class TemporaryEmployee : public Employee
{
private:
	int pay;
public:
	//생성자
	TemporaryEmployee(const char * name, int hour) : Employee(name), pay(hour)
	{}
	//월급을 반환하는 함수
	int GetSalary() const //const: 수정 못하게끔
	{
		return (7530*pay);
	}
	//정규직 사원을 출력하는 함수
	void ShowEmployeeInfo() const
	{
		cout << "---알바생---" << endl;
		ShowYourName();
		cout << "최저시급 : 7530원" << endl;
		cout << "일한시간 : " << pay << endl;
		cout << "시급 : 7530x" <<pay<<"="<<GetSalary() << endl << endl;
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
		cout << "---정규직---" << endl;
		ShowYourName();
		cout << "월급 : " << GetSalary() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee * empList1[50]; //다형성
	//SalesEmployee * empList2[50];
	//TemporaryEmployee * empList3[50];
	int empNum1;
public:
	//생성자
	EmployeeHandler() : empNum1(0)//empNum1초기화
	{

	}
	//사원등록 함수
	void AddEmployee(Employee * emp)
	{
		empList1[empNum1++] = emp;
	}
	//전체사원 월급 정보 출력 함수
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum1; i++)
			empList1[i]->ShowEmployeeInfo();
	}
	//이번달 총 월급 합계 함수
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum1; i++)
			sum += empList1[i]->GetSalary();

		cout << "월급 합계 : " << sum << endl;
		empList1[0]->GetSalary();
	}
	//소멸자
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum1; i++)
			delete empList1[i];
	}
};

int main(void)
{
	EmployeeHandler handler;
	handler.AddEmployee(new PermanentWorker("조중휘", 50000000));
	handler.AddEmployee(new SalesEmployee("홍길동", 3000000, 500000));
	handler.AddEmployee(new TemporaryEmployee("김연아", 200));
	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();

	return 0;
}