#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
char* data();
void file(char* dt);
int main()
{
	char* dt = data();
	file(dt);
}

char* data() {
	// текущая дата/время на основе текущей системы
	time_t now = time(0);
	// преобразовывает время в string form
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	return dt;
}

void file(char* dt)
{
	std::ofstream file;
	file.open("test.txt", ios_base::app);
	unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
	file << milliseconds_since_epoch << endl;
	file << "The local date and time is : "<< dt << endl;
	file.close();

}
