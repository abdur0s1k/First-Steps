#include "pch.h"
#include "ClassLibrary1.h"

namespace ClassLibrary1 {
	using namespace System;
	public ref class Class1
	{
	private:
		int hours;
		int minutes;
		int seconds;
	public:
		Class1(int num1, double num2, int num3) {
			hours = num1;
			minutes = num2;
			seconds = num3;
		}

		double CalculateGeometricMean() {
			return hours * 60 + minutes;
		}

		int CountDigitsInSum() {
			int totalMinutes = hours * 60 + minutes;
			totalMinutes -= 10;
			if (totalMinutes < 0) {
				totalMinutes += 24 * 60; 
			}
			hours = totalMinutes / 60;
			minutes = totalMinutes % 60;
			return minutes;
		}
	};
}