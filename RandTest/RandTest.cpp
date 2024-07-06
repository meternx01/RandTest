// RandTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "xirand.h"
#include "rng/mersennetwister.h"
#include <chrono>

int main()
{
	auto sta = std::chrono::system_clock::now();
	auto end = sta + std::chrono::seconds(3600);
	std::chrono::system_clock::time_point i = sta;

	for (i = sta; i < end; i += std::chrono::seconds(1)) {
		float rand = xirand::GetRandomNumber(1.);

		if (rand <.05)
		{
			// Convert timestamp to human-readable time
			std::time_t timestamp = std::chrono::system_clock::to_time_t(i);
			char buffer[26];
			ctime_s(buffer, sizeof(buffer), &timestamp);

			std::cout << "Timestamp: " << buffer << "\t random number: " << rand << "\n";

		}
		
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
