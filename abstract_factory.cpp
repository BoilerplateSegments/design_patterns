/*
The client can choose between two types of factory
+ coffee_noodle_factory
+ Factory_milk_rice
Detailed production of drink or food share same mother-class.
*/

/*

1. Usage of ** in class should be reviewed
2. wtf is const = 0??
3. check <https://releases.llvm.org/8.0.0/tools/clang/tools/extra/docs/clang-tidy/checks/modernize-use-nodiscard.html#modernize-use-nodiscard>

*/

#include <string>
#include <iostream>

class drinkMaker {
public:
    virtual ~drinkMaker()= default;;
    virtual std::string printDrink() const = 0; // const = 0 ?? why??
};

class milkMaker : public drinkMaker {
public:
    std::string printDrink() const override{
        return "This is milk!";
    }
};

class coffeeMaker : public drinkMaker {
public:
    std::string printDrink() const override{
        return "This is coffee!";
    }
};

class foodMaker {
public:
    virtual ~foodMaker()= default;; // Destroy method
    virtual std::string printFood() const = 0;
};

class riceMaker : public foodMaker {
public:
    std::string printFood() const override{
        return "This is rice!";
    }
};

class noodleMaker : public foodMaker {
public:
    std::string printFood() const override{
        return "This is noodle!";
    }
};

class abstractFactory {
    public:
    virtual drinkMaker *createDrinkMaker() const = 0; //why add const??
    virtual foodMaker  *createFoodMaker () const = 0;
};

class Factory_milk_rice : public abstractFactory {
    public:
        drinkMaker *createDrinkMaker() const override {
            return new milkMaker();
        }

        foodMaker *createFoodMaker() const override {
            return new riceMaker();
         }
};

class Factory_coffee_noodle : public abstractFactory {
public:
    drinkMaker *createDrinkMaker() const override {
        return new coffeeMaker();
    }

    foodMaker *createFoodMaker() const override {
        return new noodleMaker();
    }
};

void ClientOrder (abstractFactory &factory){
    drinkMaker *drink_maker = factory.createDrinkMaker();
    foodMaker  *food_maker  = factory.createFoodMaker() ;

    std::cout << drink_maker-> printDrink() << std::endl;
    std::cout << food_maker -> printFood()  << std::endl;

    delete drink_maker;
    delete food_maker ;
}

int main(){
    std::cout << "================="  << std::endl;

    Factory_coffee_noodle *coffee_noodle_factory = new Factory_coffee_noodle();
    ClientOrder(*coffee_noodle_factory);

    return 0;
}

/*
output:

=================
This is coffee!
This is noodle!


*/
