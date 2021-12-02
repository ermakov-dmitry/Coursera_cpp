#include "Common.h"

using namespace std;

// Этот файл сдаётся на проверку
// Здесь напишите реализацию необходимых классов-потомков `IShape`
class Rectangle : public IShape {
public:
    explicit Rectangle() : type(ShapeType::Rectangle) {}
    unique_ptr<IShape> Clone() const override {
        unique_ptr<IShape> copy = make_unique<Rectangle>();
        copy->SetPosition(position);
        copy->SetSize(size);
        copy->SetTexture(texture);
        return copy;
    }

    void SetPosition(Point p) override {
        position = p;
    }

    Point GetPosition() const override {
        return position;
    }

    void SetSize(Size sz) override {
        size = sz;
    }

    Size GetSize() const override {
        return size;
    }

    void SetTexture(shared_ptr<ITexture> ptr_texture) override {
        texture = move(ptr_texture);
    }

    ITexture* GetTexture() const override {
        return texture.get();
    }

    void Draw(Image& img) const override {
        // img[i + position.y] img[j + position.x]
        for (int i = 0; i < size.height; i++) {
            for (int j = 0; j < size.width; j++) {
                if (texture != nullptr) {
                    if (i + position.y < img.size() && j + position.x < img[0].size()) {
                        if (i < texture->GetSize().height && j < texture->GetSize().width) {
                            img[i + position.y][j + position.x] = texture->GetImage()[i][j];
                        } else {
                            img[i + position.y][j + position.x] = '.';
                        }
                    }
                } else {
                    img[i + position.y][j + position.x] = '.';
                }
            }
        }
    }

private:
    ShapeType type;
    Point position{};
    Size size{};
    shared_ptr<ITexture> texture;
};

class Ellipse : public IShape {
public:
    explicit Ellipse() : type(ShapeType::Ellipse) {}

    unique_ptr<IShape> Clone() const override {
        unique_ptr<IShape> copy = make_unique<Rectangle>();
        copy->SetPosition(position);
        copy->SetSize(size);
        copy->SetTexture(texture);
        return copy;
    }

    void SetPosition(Point p) override {
        position = p;
    }

    Point GetPosition() const override {
        return position;
    }

    void SetSize(Size sz) override {
        size = sz;
    }

    Size GetSize() const override {
        return size;
    }

    void SetTexture(shared_ptr<ITexture> ptr_texture) override {
        texture = move(ptr_texture);
    }

    ITexture* GetTexture() const override {
        return texture.get();
    }

    void Draw(Image& img) const override {
        // img[i + position.y] img[j + position.x]
        for (int i = 0; i < size.height; i++) {
            for (int j = 0; j < size.width; j++) {
                if (texture != nullptr) {
                    if (IsPointInEllipse({j, i}, size) && i + position.y < img.size() && j + position.x < img[0].size()) {
                        if (i < texture->GetSize().height && j < texture->GetSize().width) {
                            img[i + position.y][j + position.x] = texture->GetImage()[i][j];
                        } else {
                            img[i + position.y][j + position.x] = '.';
                        }
                    }
                } else {
                    img[i + position.y][j + position.x] = '.';
                }
            }
        }
    }

private:
    ShapeType type;
    Point position{};
    Size size{};
    shared_ptr<ITexture> texture;
};

// Напишите реализацию функции
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
    if (shape_type == ShapeType::Rectangle) {
        return make_unique<Rectangle>();
    } else {
        return make_unique<Ellipse>();
    }
}