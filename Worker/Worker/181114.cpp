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
	//사원 이름 출력 함수
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	//생성자
	//월급을 반환하는 함수
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