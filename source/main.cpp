#include <iostream>
#include <string>
class Car
{
private:
    
    std::string brand_; //торговая марка 
    int cnt_cilind_, power_;// число цилиндров и мощность
    
public:
    static int amountCar;
    Car(std::string brand = "null_nameCar", int cnt_cilind = 1, int power = 10) {
        brand_ = brand;
        cnt_cilind_ = cnt_cilind;
        power_ = power;

        ++amountCar;
    }
    Car(const Car& other){
        brand_ = other.brand_;
        cnt_cilind_ = other.cnt_cilind_;
        power_ = other.power_;
        ++amountCar;
    }
    ~Car()
    {
        --amountCar;
    }
    // getter
    std::string getBrand(){
        return brand_;
    }
    int getCntCilind(){
        return cnt_cilind_;
    }
    int getPower(){
        return power_;
    }
    // setter
    void setBrand(std::string b){
        brand_ = b;
    }
    void setCntCilind(int cilindr){
        cnt_cilind_ = cilindr;
    }
    void setPower(int power){
        power_ = power;
    }

    Car& operator=(const Car& car)
{
    if(&car != this)
    {
        brand_ = car.brand_;
        cnt_cilind_ = car.cnt_cilind_;
        power_ = car.power_;
    }
    return *this;
}

    static int count(){
        return amountCar;
    }
};
class Lorry : public Car
{
private:
    int liftPower_;
    
public:
    Lorry(std::string brand = "null_nameLorry", int cnt_cilind = 1, int power = 10, int liftPower = 20) : Car(brand,cnt_cilind,power){
        liftPower_ = liftPower;
    }
    // Lorry(const Lorry& other){
    //     Lorry(other.getBrand(), other.getCntCilind(), other.getPower(), other.liftPower_);
    // }

    int getliftPower(){
        return liftPower_;
    }
    // setter
    void setliftPower(int liftpower){
        liftPower_ = liftpower;
    }    

};

int Car::amountCar = 0;

std::ostream& operator << (std::ostream &os, Car &car)
{
    return os << car.getBrand() << " cilindr:" << car.getCntCilind() << " power:" << car.getPower() <<std::endl;
}
std::ostream& operator << (std::ostream &os, Lorry &lorry)
{
    return os << lorry.getBrand() << " cilindr:" << lorry.getCntCilind() << " power:" << lorry.getPower() << " powerLift:" << lorry.getliftPower()<<std::endl;
}

std::istream& operator >> (std::istream& in, Car &car)
{
    std::string brand;
    int power, cnt_cilindr;
    in >> brand >> cnt_cilindr >> power;
    car.setBrand(brand);
    car.setCntCilind(cnt_cilindr);
    car.setPower(power);
    return in;
}
std::istream& operator >> (std::istream& in, Lorry &lorry)
{
    std::string brand;
    int power, cnt_cilindr, liftPower;
    in >> brand >> cnt_cilindr >> power >> liftPower;
    lorry.setBrand(brand);
    lorry.setCntCilind(cnt_cilindr);
    lorry.setPower(power);
    lorry.setliftPower(liftPower);
    return in;
}

int main()
{
    Car first("dodge",4,4);
    
    Lorry bigtruck("kamaz",2,200,4000);
    std::string name1, name2;
    name1 = first.getBrand();
    int printvalue;
    std::cout << "-------------------Test print"<<std::endl; 
    std::cout << name1 <<std::endl;
    std::cout << first;

    std::cout << bigtruck ;

    name2 = bigtruck.getBrand();
    std::cout << name2 << " Lift Power = " << bigtruck.getliftPower() <<std::endl; 

    std::cout << Car::count() << std::endl; 
    Car second;
    std::cout << "-------------------Test assignment"<<std::endl; 
    std::cout << second;
    second = first;
    std::cout << second;
    std::cout << Car::count() << std::endl; 

    Lorry lorrysec;
    std::cout << "-------------------Test input Lorry"<<std::endl; 
    std::cout << "Input brand, amount cilindr, power and powerlift: ";
    std::cin >> lorrysec;
    std::cout << lorrysec;


    return 0;
}