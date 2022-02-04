#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
void file();
int main()
{
	file();
	// текущая дата/время на основе текущей системы
	time_t now = time(0);
	// преобразовывает время в string form
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
}
void file()
{
	std::ofstream file;
	file.open("test.txt", ios_base::app);
	unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
	file << milliseconds_since_epoch << endl;
	file.close();

}
