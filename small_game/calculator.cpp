#include <iostream>

int main()
{
	double num1, num2;
	char operation;

	std::cout << "🌟 Magical Calculator of Wonders 🌟\n";
	std::cout << "Enter the first enchanting number: ";
	std::cin >> num1;

	std::cout << "Enter the second mystical number: ";
	std::cin >> num2;

	std::cout << "Choose your mystical operation (+, -, *, /): ";
	std::cin >> operation;

	switch (operation)
	{
	case '+':
		std::cout << "✨ " << num1 << " + " << num2 << " = " << num1 + num2 << " ✨\n";
		break;
	case '-':
		std::cout << "❄️ " << num1 << " - " << num2 << " = " << num1 - num2 << " ❄️\n";
		break;
	case '*':
		std::cout << "🌟 " << num1 << " * " << num2 << " = " << num1 * num2 << " 🌟\n";
		break;
	case '/':
		if (num2 != 0)
		{
			std::cout << "🌈 " << num1 << " / " << num2 << " = " << num1 / num2 << " 🌈\n";
		}
		else
		{
			std::cout << "🧙‍♂️ Error: Division by zero is undefined. 🧙‍♂️\n";
		}
		break;
	default:
		std::cout << "⚠️ Invalid operation. Try a different magical command. ⚠️\n";
	}

	return 0;
}