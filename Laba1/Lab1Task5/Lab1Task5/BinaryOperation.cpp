#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(Expression const* left, const char& op, Expression const* right) {
	BinaryOperation::left = left;
	BinaryOperation::op = op;
	BinaryOperation::rigth = right;
}

BinaryOperation::~BinaryOperation() {
	delete left;
	left = nullptr;
	delete rigth;
	rigth = nullptr;
}

double BinaryOperation::evaluate() const {
	return BinaryOperation::makeOperation();
}

double BinaryOperation::makeOperation() const {
	switch (op)
	{
	case '+':
		return sum();
	case '-':
		return sub();
	case '*':
		return mul();
	case '/':
		return div();
	default:
		throw "WRONG_SIMBOL";
	}
}

double BinaryOperation::sum() const {
	return left->evaluate() + rigth->evaluate();
}

double BinaryOperation::sub() const {
	return left->evaluate() - rigth->evaluate();
}

double BinaryOperation::mul() const {
	return left->evaluate() * rigth->evaluate();
}

double BinaryOperation::div() const {
	return left->evaluate() / rigth->evaluate();
}