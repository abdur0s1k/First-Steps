#include "pch.h"

#include "ClassLibrary1.h"

namespace ClassLibrary1 {
	using namespace System;
	public ref class Class1
	{
	private:
		int number3;
	public:
		Class1(int num3) {
			number3 = num3;
		}

		double CalculateGeometricMean() {
			double product = 2024 - number3;
			return product;
		}

		int CountDigitsInSum() {
			int sum = 2024 - number3;
			int count = sum * 365;
			return count;
		}
	};
}