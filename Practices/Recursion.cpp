#include <iostream>
#include <string>

using namespace std;

int binarySearch(int* arr, int num)
{
	if (arr[0] == num)
		return arr[0];
	else
		return binarySearch(arr + 1, num);
}

int GCD(int n1, int n2)
{
	if (n2 != 0 || n1!=n2)
		return GCD(n2, n1 % n2);
	else 
		return n1;
}

int calPower(int base, int expo)
{
	if (expo != 0)
		return (base * calPower(base, expo - 1));
	else
		return 1;
}

bool isConsonant(char ch)
{
	ch = toupper(ch);

	return !(ch == 'A' || ch == 'E' ||
		ch == 'I' || ch == 'O' ||
		ch == 'U') && ch >= 65 && ch <= 90;
}

int totalConsonants(string str, int n)
{
	if (n == 1)
		return isConsonant(str[0]);

	return totalConsonants(str, n - 1) +
		isConsonant(str[n - 1]);
}




int main()
{
	/*int arr[7] = { 1,2,3,4,5,6,7 };
	int num = 2;
	cout << binarySearch(arr, num);*/

	/*int num1, num2;
	cout << "Enter two numbers.";
	cin >> num1 >> num2;
	
	int results = GCD(num1, num2);
	cout << results;*/

	/*int base = 10;
	int expo = 2;
	int resultss = calPower(base, expo);
	cout << resultss;*/

	/*string str = "Bilal";
	cout << totalConsonants(str, str.length());*/
	

	return 0;
}








 