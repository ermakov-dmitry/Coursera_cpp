//
// Created by dmitry on 04.01.2021.
//

#pragma once
#include <string>
#include "date.h"
#include "overloaded_operators.h"
#include <memory>

using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

enum class LogicalOperation {
    Or,
    And,
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
    EmptyNode();
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& cmp, const Date& value);
    bool Evaluate(const Date& date, const string& event) const override;  // может быть возвращает операцию сравнения и дату

private:
    const Comparison cmp_;
    const Date date_;

};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& cmp, string  value);
    bool Evaluate(const Date& date, const string& event) const override;

private:
    const Comparison cmp_;
    const string event_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& op, shared_ptr<Node> lhs, shared_ptr<Node> rhs);
    bool Evaluate(const Date& date, const string& event) const override;
private:
    const LogicalOperation op_;
    shared_ptr<Node> lhs_;
    shared_ptr<Node> rhs_;

};