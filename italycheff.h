
#define ITALYCHEFF_H
#include "chef.h"


class italychef : public chef {
private:
    int makePizza(int flour, int water);
    string password;
public:
    italychef(string chefName);
    ~italychef();
    bool askSecret(string sala, int flour, int water);

};


