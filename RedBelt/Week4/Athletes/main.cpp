#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Athletes {
public:
    explicit Athletes() {
        v_athletes.resize(1'000'000 + 1, f_athletes.end());
    }
    void AddNewAthlete(const int& number_athlete, const int& number_next_athlete) {
        v_athletes[number_athlete] = f_athletes.insert(v_athletes[number_next_athlete], number_athlete);
    }
    void PrintList() const {
        for (const auto& x : f_athletes) {
            cout << x << '\n';
        }
        cout << endl;
    }
private:
    vector<list<int>::iterator> v_athletes;
    list<int> f_athletes;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t N = 0;
    cin >> N;
    Athletes group;
    for (size_t i = 0; i < N; i++) {
        int number_athlete;
        int number_next_athlete;
        cin >> number_athlete >> number_next_athlete;
        group.AddNewAthlete(number_athlete, number_next_athlete);
    }
    group.PrintList();
    return 0;
}
