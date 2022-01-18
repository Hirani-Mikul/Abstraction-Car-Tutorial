#include <iostream>
#include <type_traits>

enum class Direction : unsigned int {
    REST = 0,
    LEFT,
    RIGHT
};

std::ostream& operator << (std::ostream& os, const Direction& dir)
{
    os << static_cast<std::underlying_type<Direction>::type>(dir);
    return os;
}



class Car {
public:
    virtual void changeDirection(Direction direction) = 0;
    virtual void accelerate() = 0;
    virtual void decelerate() = 0;
    virtual bool toggleEngine() = 0;
};

class Toyota: public Car {
public:
    Toyota()
    {
        currentDirection = Direction::REST;
        isEngineOn = false;
        fuelLevel = 400.0f;
        speed = 0.0f;
    }
public:
    
    bool toggleEngine() {

        if (isEngineOn) std::cout << "Turning engine off.\n";
        else std::cout << "Turning engine on.\n";

        isEngineOn = !isEngineOn;

        return isEngineOn;
    }

    void changeDirection(Direction newDirection)
    {
        std::cout << "Turning: " << newDirection << '\n';
        currentDirection = newDirection;
    }

    void consumeFuel()
    {
            fuelLevel--;
            std::cout << fuelLevel << '\n';
            if (fuelLevel <= 0.00f) toggleEngine();
    }

    void accelerate() {
        if (speed >= maxSpeed || !isEngineOn) return;
        speed++;
        std::cout << "ACCELERATING: Toyota.\n";
    }

    void decelerate()
    {
        if (speed == 0) return;
        speed--;
        std::cout << "DECELERATING: Toyota.\n";

    }
private:

    float fuelLevel;
    Direction currentDirection;
    float maxSpeed = 180.00f;
    float speed;

    bool isEngineOn;
};

int main()
{
    Toyota car1 = Toyota();
    car1.toggleEngine();
    // Depending on key pressed, certain actions are executed

    /*while (car1.toggleEngine())
    {
        car1.consumeFuel();

        if (KEY == ARROW UP) car1.accelerate();
        else if (KEY == ARROW DOWN) car1.decelerate();
        
        if (KEY == ARROW LEFT) car1.changeDirection(Direction::LEFT);
        if (KEY == ARROW RIGHT) car1.changeDirection(Direction::RIGHT);

    }*/
    
}
