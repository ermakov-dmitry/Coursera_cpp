#include "Common.h"

using namespace std;

class Number : public Expression {
public:
    explicit Number(const int& val) : value(make_unique<int>(val)) {}
    int Evaluate() const override {
        return *value;
    }
    string ToString() const override {
        return to_string(*value);
    }

private:
    unique_ptr<int> value;
};

class Summary : public Expression {
public:
    explicit Summary(ExpressionPtr left_, ExpressionPtr right_) : left(move(left_)), right(move(right_)) {}
    int Evaluate() const override {
        return left->Evaluate() + right->Evaluate();
    }
    string ToString() const override {
        return '(' + left->ToString() + ')' + '+' + '(' + right->ToString() +')';
    }

private:
    ExpressionPtr left;
    ExpressionPtr right;
};

class Prod : public Expression {
public:
    explicit Prod(ExpressionPtr left_, ExpressionPtr right_) : left(move(left_)), right(move(right_)) {}
    int Evaluate() const override {
        return left->Evaluate() * right->Evaluate();
    }
    string ToString() const override {
        return '(' + left->ToString() + ')' + '*' + '(' + right->ToString() +')';
    }

private:
    ExpressionPtr left;
    ExpressionPtr right;
};

ExpressionPtr Value(int value) {
    return make_unique<Number>(value);
}

ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right) {
    return make_unique<Summary>(move(left), move(right));
}

ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right) {
    return make_unique<Prod>(move(left), move(right));
}