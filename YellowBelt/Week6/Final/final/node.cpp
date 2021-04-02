//
// Created by dmitry on 04.01.2021.
//

#include "node.h"

#include <utility>

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &op, shared_ptr<Node> lhs, shared_ptr<Node> rhs) : op_(op), lhs_(move(lhs)), rhs_(move(rhs)) {}
bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    if (op_ == LogicalOperation::Or) {
        return lhs_->Evaluate(date, event) || rhs_->Evaluate(date, event);
    } else {
        return lhs_->Evaluate(date, event) && rhs_->Evaluate(date, event);
    }
}

DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &value) : cmp_(cmp), date_(value) {}
bool DateComparisonNode::Evaluate(const Date &date, const string &event) const {
    if (cmp_ == Comparison::Less) {
        return date < date_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return date <= date_;
    } else if (cmp_ == Comparison::Greater) {
        return date > date_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return date >= date_;
    } else if (cmp_ == Comparison::Equal) {
        return date == date_;
    } else {
        return date != date_;
    }
}

EventComparisonNode::EventComparisonNode(const Comparison &cmp, string value) : cmp_(cmp), event_(std::move(value)) {}
bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    if (cmp_ == Comparison::Less) {
        return event < event_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return event <= event_;
    } else if (cmp_ == Comparison::Greater) {
        return event > event_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return event >= event_;
    } else if (cmp_ == Comparison::Equal) {
        return event == event_;
    } else {
        return event != event_;
    }
}

EmptyNode::EmptyNode() = default;
bool EmptyNode::Evaluate(const Date &date, const string &event) const {
    return true;
}
