/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/


/*
 copied UDT 1:
 */
#include <iostream>

struct CookieShop  
{
    CookieShop();
    ~CookieShop();
    int numberOfStaff = 10;
    float avgEarningsPerWeek = 1500.50f;
    float avgCookieDoughPerWeek = 20.5f;
    float avgCoffeePerWeek = 17.8f;
    float cashOnHand = 2447.89f;

    struct Oven  
    {
        Oven();
        ~Oven();
        float widthOfOven = 30;
        int maxTemp = 450;
        std::string manufacturer = "Maytag";
        int widthOfOvenWindow = 26;
        float numOfKnobs = 7;

        void produceHeat(bool isOvenOn);
        void displayTimer(std::string setTime);
        void displayTemp(std::string setTemp);
        void lowerTemp(int currentTemp); 
    };

    void bakeCookies(bool isPreheatTempReached);
    float calculateTotalCustomerCharge(float cookiePrice = 1.95f, float coffeePrice = 3.15f); 
    void buyNewOven(Oven manufacturer);
    int hireNewStaff(int newStaffMember); 
};

CookieShop::Oven::Oven() 
{
    std::cout << "Oven being constructed!" << std::endl;
}

CookieShop::Oven::~Oven() 
{
    std::cout << "Oven being deconstructed!" << std::endl;
}

void CookieShop::Oven::produceHeat(bool isOvenOn)
{
    if (isOvenOn == true)
    {
        std::cout << std::endl;
        std::cout << "Oven heating." << std::endl;
    }
}

void CookieShop::Oven::displayTimer(std::string setTime)
{
    std::cout << "Timer is " << setTime << "." << std::endl;
}

void CookieShop::Oven::displayTemp(std::string setTemp)
{
    std::cout << "Temperature is " << setTemp << "." << std::endl;
    std::cout << "Changing temperature to " << maxTemp <<  "." << std::endl;
    std::cout << std::endl;
}

void CookieShop::Oven::lowerTemp(int currentTemp)
{
    Oven Oven;
    while(Oven.maxTemp > currentTemp)
    {
        Oven.maxTemp -= 10;
        std::cout << "Lowering temp to: " << Oven.maxTemp << std::endl;
    }
}

CookieShop::CookieShop() 
{
    std::cout << "CookieShop being constructed!" << std::endl;
}

CookieShop::~CookieShop() 
{
    std::cout << "CookieShop being deconstructed!" << std::endl;
}

void CookieShop::bakeCookies(bool isPreheatTempReached)
{
    if (isPreheatTempReached)
    {
        std::cout << std::endl;
        std::cout << "Ready to bake." << std::endl;
    }
}

float CookieShop::calculateTotalCustomerCharge(float cookiePrice, float coffeePrice)
{
    float total = cookiePrice + coffeePrice;
    std::cout << "Your total is:$ " << total << std::endl;
    return total;
}

void CookieShop::buyNewOven(Oven newOvenA)
{
    std::cout << "I bought a new oven from " << newOvenA.manufacturer << "." << std::endl;
    std::cout << "We will now go from " << numberOfStaff << " to " << numberOfStaff + 3 << " employees." << std::endl; 
}

int CookieShop::hireNewStaff(int totalStaffNeeded) 
{
    for(int i = numberOfStaff; i <= totalStaffNeeded; ++i)
    {
        ++numberOfStaff;
        std::cout << "Increasing staff: " << numberOfStaff << std::endl;     
    }   
    return numberOfStaff;
}

/*
 copied UDT 2:
 */
struct Airplane
{
    Airplane();
    ~Airplane ();
    float numOfPassengerSeats = 180;
    float totalWeightOfPlane = 92354.67f;
    float lengthOfPlaneWings = 33.5f;
    int numOfLuggagePieces = 225;
    int amountOfFuel = 20000;

    struct Cockpit
    { 
        Cockpit();
        ~Cockpit();
        int numOfSwitches = 30;
        int numOfDisplays = 8;
        int numOfFlightControllers = 2;
        int numOfRudderPedals = 4;
        float numOfPilots = 2;

        int turnPlane(int degreesTurned);
        void landingGearRaised(bool isGearLeverInUpPostion);
        void talkToAirTrafficControl(bool isPushToTalkSwitchPressed);
        int addMoreDisplays(int displayTotal); 
    };

    void takeOff(bool isRunwayClear, bool isTakeOffSpeedReached);
    void land(bool isLandingSpeedReached, bool areWheelsDeployed);
    void sendDataToControlTower(bool isGreenLightOn);
    int  increaseTotalLuggage(int totalLuggage); 
};

Airplane::Cockpit::Cockpit()
{
    std::cout << "Cockpit being constructed!" << std::endl;
}

Airplane::Cockpit::~Cockpit()
{
    std::cout << "Cockpit being deconstructed!" << std::endl;
}

int Airplane::Cockpit::turnPlane(int degreesTurned)
{
    std::cout << std::endl;
    std::cout << "Plane turned " << degreesTurned << " degrees." << std::endl;
    return degreesTurned;
}

void Airplane::Cockpit::landingGearRaised(bool isGearLeverInUpPostion)
{
    if(isGearLeverInUpPostion)
    {
        std::cout << "One of the " << numOfSwitches << " switches will raise the landing gear." << std::endl;
        std::cout << "Landing Gear is raised." << std::endl;
    }
}

void Airplane::Cockpit::talkToAirTrafficControl(bool isPushToTalkSwitchPressed)
{
    if(isPushToTalkSwitchPressed)
    {
        std::cout << "Ready to talk." << std::endl;
        std::cout << std::endl;
    }
}

int Airplane::Cockpit::addMoreDisplays(int displayTotal) 
{
    while(numOfDisplays < displayTotal)
    {
        ++numOfDisplays;
        std::cout <<"Increasing number of displays "<< numOfDisplays << std::endl;   
    }
    return numOfDisplays;
}

Airplane::Airplane()
{
    std::cout << "Airplane being constructed!" << std::endl;
}

Airplane::~Airplane()
{
    std::cout << "Airplane being deconstructed!" << std::endl;
}

void Airplane::takeOff(bool isRunwayClear, bool isTakeOffSpeedReached)
{
    if ((isRunwayClear == true) && (isTakeOffSpeedReached == true))
    {
        std::cout << std::endl;
        std::cout << "Ready for takeoff!" << std::endl;
        std::cout << "We only have " << numOfPassengerSeats - 20 << " passenger seats filled." << std::endl; 
    }  
}

void Airplane::land(bool isLandingSpeedReached, bool areWheelsDeployed)
{
    if (isLandingSpeedReached && areWheelsDeployed)
    {
        std::cout << "Ready for landing." << std::endl;
    }       
}

void Airplane::sendDataToControlTower(bool isGreenLightOn)
{
    if (isGreenLightOn == false)
    {
        std::cout << "Data is not being sent to control." << std::endl;
        std::cout << std::endl;
    }
}

int Airplane::increaseTotalLuggage(int totalLuggage)
{
    for(int i = numOfLuggagePieces; i < totalLuggage; ++i)
    {
        ++numOfLuggagePieces;
        std::cout << "Increasing luggage to " << numOfLuggagePieces << std::endl;  
    }
    return numOfLuggagePieces;
}
/*
 copied UDT 3:
 */
struct Laptop
{
    Laptop();
    ~Laptop();
    int towerHeight = 13;
    int numOfFans = 3;
    int amountOfRam = 16;
    int numOfUSBPorts = 6;
    int numOfKeys = 120;

    void typeLetter(bool isLetterKeyPressed);
    int productOfNumbers(int num1, int num2);
    void runSoftware(bool hasDoubleClickedIcon);
    int increaseRam(int newRam); 
    
};

Laptop::Laptop()
{
    std::cout << "Laptop being constructed!" << std::endl;
}

Laptop::~Laptop()
{
    std::cout << "Laptop being deconstructed!" << std::endl;
}

void Laptop::typeLetter(bool isLetterKeyPressed)
{
    if (isLetterKeyPressed == true)
    {
        char letterPressed = 'B';
        std::cout << std::endl;
        std::cout << "Out of " << numOfKeys << " keys, you pressed the letter " << letterPressed << "." << std::endl; 
    }
}

int Laptop::productOfNumbers(int num1, int num2)
{
    int product = num1 * num2;
    std::cout << "Product is " << product << "." << std::endl;
    return product;
}

void Laptop::runSoftware(bool hasDoubleClickedIcon)
{
    if (hasDoubleClickedIcon == true)
    {
        std::cout << "Software Running." << std::endl; 
        std::cout << std::endl;
    }   
}

int Laptop::increaseRam(int addNewRam) 
{
    for(int i = amountOfRam; i < addNewRam; ++i)
    {
        amountOfRam += 4;
        std::cout << "Increasing RAM to: " << amountOfRam << std::endl;
        if( amountOfRam >= addNewRam)
            return amountOfRam;
    }
    return amountOfRam;
}
/*
 new UDT 4:
 with 2 member functions
 */
struct StripMall
{
    StripMall();
    ~StripMall();
    CookieShop cookieShop1, cookieShop2;
    CookieShop::Oven newOven1;

    float calculateMonthlyEarnings(float CS1WeeklyEarnings, float CS2WeeklyEarnings);
    float constructionForMoreOvens(float howManyOvensNeeded);   
};

StripMall::StripMall()
{
    std::cout << "StripMall being constructed!" << std::endl;
}

StripMall::~StripMall()
{
    std::cout << "StripMall being deconstructed!" << std::endl;
}

float StripMall::calculateMonthlyEarnings(float CS1WeeklyEarnings, float CS2WeeklyEarnings)
{
    cookieShop1.avgEarningsPerWeek = CS1WeeklyEarnings;
    cookieShop2.avgEarningsPerWeek = CS2WeeklyEarnings;
    float totalMonthlyCSEarnings = (cookieShop1.avgEarningsPerWeek + cookieShop2.avgEarningsPerWeek) * 4; 
    std::cout<<std::endl;
    std::cout << "Cookie Shops' monthly earnings are:$ " << totalMonthlyCSEarnings  << std::endl;
    return totalMonthlyCSEarnings;
}

float StripMall::constructionForMoreOvens(float howManyOvensNeeded)
{
    float ovenSpaceNeeded = howManyOvensNeeded * newOven1.widthOfOven;
    std::cout << "We need at least " << ovenSpaceNeeded  << " inches of extra space for " << howManyOvensNeeded << " ovens." << std::endl;
    return ovenSpaceNeeded;
}

/*
 new UDT 5:
 with 2 member functions
 */
struct NewPlaneCompany
{
    NewPlaneCompany();
    ~NewPlaneCompany();
    Airplane airplane1, airplane2;
    Airplane::Cockpit cockpit1, cockpit2;

    float buySeatDisplays(float displayPrice);
    float calculateTotalPilotSalary(float pilotSalary);  
};

NewPlaneCompany::NewPlaneCompany()
{
    std::cout << "NewPlaneCompany being constructed!" << std::endl;
}

NewPlaneCompany::~NewPlaneCompany()
{
    std::cout << "NewPlaneCompany being deconstructed!" << std::endl;
}

float NewPlaneCompany::buySeatDisplays(float priceOfEachDisplay)
{
    float totalPriceofDisplays = (airplane1.numOfPassengerSeats + airplane2.numOfPassengerSeats) * priceOfEachDisplay;
    std::cout << "Total price for displays are:$ " << totalPriceofDisplays << std::endl;
    return totalPriceofDisplays;
}

float NewPlaneCompany::calculateTotalPilotSalary(float pilotSalary)
{
    float totalPilotSalary = (cockpit1.numOfPilots + cockpit2.numOfPilots) * pilotSalary;
    std::cout << "Total salary for all pilots is:$ " << totalPilotSalary << std::endl;
    return totalPilotSalary;
}


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    CookieShop cookieShop;
    CookieShop::Oven newOven1;
    Laptop laptop;
    Airplane airplane;
    Airplane::Cockpit cockpit;
    StripMall stripMall;
    NewPlaneCompany newPlaneCompany;

    cookieShop.bakeCookies(true);
    cookieShop.calculateTotalCustomerCharge(2.00f, 4.00f);
    cookieShop.buyNewOven(newOven1);
    cookieShop.hireNewStaff(12);

    newOven1.produceHeat(true);
    newOven1.displayTimer("10:00");
    newOven1.displayTemp("400F");
    newOven1.lowerTemp(430);

    laptop.typeLetter(true );
    laptop.productOfNumbers(5, 6);
    laptop.runSoftware(true);
    laptop.increaseRam(32);

    airplane.takeOff(true, true);
    airplane.land(true, true);
    airplane.sendDataToControlTower(false);
    airplane.increaseTotalLuggage(228);

    cockpit.turnPlane(25);
    cockpit.landingGearRaised(true);
    cockpit.talkToAirTrafficControl(true);
    cockpit.addMoreDisplays(11);

    stripMall.calculateMonthlyEarnings(2000, 3000);
    stripMall.constructionForMoreOvens(3);

    newPlaneCompany.buySeatDisplays(100);
    newPlaneCompany.calculateTotalPilotSalary(75000);
  
    std::cout << "good to go!" << std::endl;
    
}
