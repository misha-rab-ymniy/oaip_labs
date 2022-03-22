#include <iostream>
#include "Expression.h"
#include "BinaryOperation.h"
#include "Number.h"

bool check_eq(Expression const* left, Expression const* right) {
	//std::cout << (int*)left << ' ' << (int*)right << '\n';
	return (*((size_t*)left) == *((size_t*)right));
}

int main() {
	Expression* sube = new BinaryOperation(new Number(4.5), '/', new Number(5));
	Expression* expr = new BinaryOperation(new Number(20), '-', new BinaryOperation(new Number(4.5), '+', new BinaryOperation(new Number(20), '-', new BinaryOperation(new Number(4.5), '+', new Number(8)))));
	std::cout << check_eq(sube, expr);
	//std::cout << sube->evaluate();
}