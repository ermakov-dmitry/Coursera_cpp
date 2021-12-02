#pragma once

namespace RAII {
    template<class Provider>
    struct Booking {
        Booking(Provider* pr, int id) : provider(pr), counter(id) {
            provider->CancelOrComplete(*this);
            --counter;
            --provider->capacity;
        }
        ~Booking() {
            if (counter || !provider) {
                provider->CancelOrComplete(*this);
            }
        }
        Provider* provider;
        int counter;
    };
}
