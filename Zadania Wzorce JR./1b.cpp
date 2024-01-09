class Pizza {
public:
    void setDough(const std::string& dough)
    {
        this->dough = dough;
    }
    void setSauce(const std::string& sauce)
    {
        this->sauce = sauce;
    }
    void setTopping(const std::string& topping)
    {
        this->topping = topping;
    }
    void displayPizza() const
    {
        std::cout << "Pizza with Dough: " << dough
            << ", Sauce: " << sauce
            << ", Topping: " << topping << std::endl;
    }
private:
    std::string dough;
    std::string sauce;
    std::string topping;
};
class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getPizza() const = 0;
};
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override
    {
        pizza.setDough("Pan Dough");
    }
    void buildSauce() override
    {
        pizza.setSauce("Hawaiian Sauce");
    }
    void buildTopping() override
    {
        pizza.setTopping("Ham and Pineapple");
    }
    Pizza getPizza() const override { return pizza; }
private:
    Pizza pizza;
};
class SpicyPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override
    {
        pizza.setDough("Thin Dough");
    }
    void buildSauce() override
    {
        pizza.setSauce("Spicy Tomato Sauce");
    }
    void buildTopping() override
    {
        pizza.setTopping("Pepperoni and Jalapenos");
    }
    Pizza getPizza() const override { return pizza; }
private:
    Pizza pizza;
};
class Cook {
public:
    void makePizza(PizzaBuilder& builder)
    {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

class JakubPizza : public PizzaBuilder {
public:
    void buildDough() override {
        pizza.setDough("Maka pszenna");
    }
    void buildSauce() override {
        pizza.setSauce("Czosnkowy");
    }
    void buildTopping() override {
        pizza.setTopping("Mozzarella, Pomidory, Oliwki");
    }
    Pizza getPizza() const override { return pizza; }
private:
    Pizza pizza;
};


int main()
{
    Cook cook;
    HawaiianPizzaBuilder hawaiianBuilder;
    cook.makePizza(hawaiianBuilder);
    Pizza hawaiianPizza = hawaiianBuilder.getPizza();
    hawaiianPizza.displayPizza();
    SpicyPizzaBuilder spicyBuilder;
    cook.makePizza(spicyBuilder);
    Pizza spicyPizza = spicyBuilder.getPizza();
    spicyPizza.displayPizza();
    return 0;
}