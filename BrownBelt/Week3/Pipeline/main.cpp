#include "test_runner.h"
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

using namespace std;


struct Email {
    string from;
    string to;
    string body;
};


class Worker {
public:
    virtual ~Worker() = default;
    virtual void Process(unique_ptr<Email> email) = 0;
    virtual void Run() {
        // только первому worker-у в пайплайне нужно это имплементировать
        throw logic_error("Unimplemented");
    }
protected:
    // реализации должны вызывать PassOn, чтобы передать объект дальше
    // по цепочке обработчиков
    void PassOn(unique_ptr<Email> email) const {
        if (next_handler != nullptr) {next_handler->Process(move(email));}
    }
public:
    void SetNext(unique_ptr<Worker> next) {
        if (next_handler) {
            next_handler->SetNext(move(next));
        } else {
            next_handler = move(next);
        }
    }
    unique_ptr<Worker> next_handler = nullptr; // filter, copier, sender
};


class Reader : public Worker {
public:
    explicit Reader(istream& in) : class_in(in) {}

    void Run() override {
        string from;
        string to;
        string body;
        while (getline(class_in, from) && getline(class_in, to) && getline(class_in, body)) {
            unique_ptr<Email> email = make_unique<Email>();
            email->from = from;
            email->to = to;
            email->body = body;
            Process(move(email));
        }
    }

    void Process(unique_ptr<Email> email) override {
        PassOn(move(email));
    }

private:
    istream& class_in;
};


class Filter : public Worker {
public:
    using Function = function<bool(const Email&)>;

public:
    // реализуйте класс
    explicit Filter(Function func) : predicate(std::move(func)) {}
    void Process(unique_ptr<Email> email) override {
        if (predicate(*email)) {
            PassOn(move(email));
        }
    }
private:
    Function predicate;
};


class Copier : public Worker {
public:
    // реализуйте класс
    explicit Copier(string address) : addr(move(address)) {}
    void Process(unique_ptr<Email> email) override {
        if (addr != email->to) {
            unique_ptr<Email> new_email = make_unique<Email>();
            new_email->from = email->from;
            new_email->to = addr;
            new_email->body = email->body;
            PassOn(move(email));
            PassOn(move(new_email));
        } else {
            PassOn(move(email));
        }
    }
private:
    string addr;
};


class Sender : public Worker {
public:
    // реализуйте класс
    explicit Sender(ostream& str) : stream(str) {}
    void Process(unique_ptr<Email> email) override {
        stream << email->from << '\n';
        stream << email->to << '\n';
        stream << email->body << '\n';
        PassOn(move(email));
    }
private:
    ostream& stream;
};


// реализуйте класс
class PipelineBuilder {
public:
    // добавляет в качестве первого обработчика Reader
    explicit PipelineBuilder(istream& in) : worker(make_unique<Reader>(in)) {}

    // добавляет новый обработчик Filter
    PipelineBuilder& FilterBy(const Filter::Function& filter) {
        worker->SetNext(make_unique<Filter>(filter));
        return *this;
    }

    // добавляет новый обработчик Copier
    PipelineBuilder& CopyTo(const string& recipient) {
        worker->SetNext(make_unique<Copier>(recipient));
        return *this;
    }

    // добавляет новый обработчик Sender
    PipelineBuilder& Send(ostream& out) {
        worker->SetNext(make_unique<Sender>(out));
        return *this;
    }

    // возвращает готовую цепочку обработчиков
    unique_ptr<Worker> Build() {
        return move(worker);
    }

private:
    unique_ptr<Worker> worker;
};


void TestSanity() {
    string input = (
            "erich@example.com\n"
            "richard@example.com\n"
            "Hello there\n"

            "erich@example.com\n"
            "ralph@example.com\n"
            "Are you sure you pressed the right button?\n"

            "ralph@example.com\n"
            "erich@example.com\n"
            "I do not make mistakes of that kind\n"
    );
    istringstream inStream(input);
    ostringstream outStream;

    PipelineBuilder builder(inStream);
    builder.FilterBy([](const Email& email) {
        return email.from == "erich@example.com";
    });
    builder.CopyTo("richard@example.com");
    builder.Send(outStream);
    auto pipeline = builder.Build();

    pipeline->Run();

    string expectedOutput = (
            "erich@example.com\n"
            "richard@example.com\n"
            "Hello there\n"

            "erich@example.com\n"
            "ralph@example.com\n"
            "Are you sure you pressed the right button?\n"

            "erich@example.com\n"
            "richard@example.com\n"
            "Are you sure you pressed the right button?\n"
    );

    ASSERT_EQUAL(expectedOutput, outStream.str());
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSanity);
    return 0;
}