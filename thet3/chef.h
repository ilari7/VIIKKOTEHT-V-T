
    #define CHEF_H
    #include <string>

    using namespace std;

    class chef {
    public:
        chef(string name);
        string getName();
        int makeSalad(int aines);
        int makeSoup(int aines);
        ~chef();
    protected:
        string chefName;

    };

