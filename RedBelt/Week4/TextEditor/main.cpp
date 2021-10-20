#include <string>
#include "test_runner.h"
#include <list>

using namespace std;

class Editor {
public:
    // Реализуйте конструктор по умолчанию и объявленные методы
    Editor() = default;
    void Left() {
        cursor = (cursor == text.begin()) ? cursor : prev(cursor);
    }
    void Right() {
        cursor = (cursor == text.end()) ? cursor : next(cursor);
    }
    void Insert(char token) {
        text.insert(cursor, token);
    }
    void Cut(size_t tokens = 1) {
        buffer.clear();
        if (tokens == 0) {
            return;
        } else {
            auto dst = distance(cursor, text.end());
            if (tokens >= dst) {
                buffer.splice(buffer.begin(), text, cursor, text.end());
                cursor = text.end();
            } else {
                buffer.splice(buffer.begin(), text, cursor, next(cursor, static_cast<int>(tokens)));
                cursor = next(text.end(), static_cast<int>(tokens) - dst);
            }
        }
    }
    void Copy(size_t tokens = 1) {
        buffer.clear();
        if (tokens == 0) {
            return;
        } else {
            size_t len = 0;
            for (auto it = cursor; it != text.end() && len <= tokens; it++) {
                buffer.push_back(*it);
                ++len;
            }
        }

    }
    void Paste() {
        text.insert(cursor, buffer.begin(), buffer.end());
    }
    string GetText() const {
        string all_text{text.begin(), text.end()};
        return all_text;
    }

private:
    list<char> text;
    list<char> buffer;
    list<char>::iterator cursor = text.end();
};

void TypeText(Editor& editor, const string& text) {
    for(char c : text) {
        editor.Insert(c);
    }
}

void TestEditing() {
    {
        Editor editor;

        const size_t text_len = 12;
        const size_t first_part_len = 7;
        TypeText(editor, "hello, world");
        for(size_t i = 0; i < text_len; ++i) {
            editor.Left();
        }
        editor.Cut(first_part_len);
        for(size_t i = 0; i < text_len - first_part_len; ++i) {
            editor.Right();
        }
        TypeText(editor, ", ");
        editor.Paste();
        editor.Left();
        editor.Left();
        editor.Cut(3);

        ASSERT_EQUAL(editor.GetText(), "world, hello");
    }
    {
        Editor editor;

        TypeText(editor, "misprnit");
        editor.Left();
        editor.Left();
        editor.Left();
        editor.Cut(1);
        editor.Right();
        editor.Paste();

        ASSERT_EQUAL(editor.GetText(), "misprint");
    }
}

void TestReverse() {
    Editor editor;

    const string text = "esreveR";
    for(char c : text) {
        editor.Insert(c);
        editor.Left();
    }

    ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
    Editor editor;
    ASSERT_EQUAL(editor.GetText(), "");

    editor.Left();
    editor.Left();
    editor.Right();
    editor.Right();
    editor.Copy(0);
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
    Editor editor;

    editor.Paste();
    TypeText(editor, "example");
    editor.Left();
    editor.Left();
    editor.Paste();
    editor.Right();
    editor.Paste();
    editor.Copy(0);
    editor.Paste();
    editor.Left();
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "example");
}

void Test()
{
    Editor editor;
    TypeText(editor, "1234567");
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Paste();
    editor.Paste();
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "123456667");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestEditing);
    RUN_TEST(tr, TestReverse);
    RUN_TEST(tr, TestNoText);
    RUN_TEST(tr, TestEmptyBuffer);
    RUN_TEST(tr, Test);
    Editor editor;
    TypeText(editor, "this is many many letter");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Copy(55);
    editor.Paste();
    editor.Paste();
    editor.Paste();
    cout << editor.GetText() << endl;
    return 0;
}