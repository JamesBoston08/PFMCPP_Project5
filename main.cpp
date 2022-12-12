/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
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
        void printOvenBrand();
    };

    void bakeCookies(bool isPreheatTempReached);
    float calculateTotalCustomerCharge(float cookiePrice = 1.95f, float coffeePrice = 3.15f); 
    void buyNewOven(Oven manufacturer);
    int hireNewStaff(int newStaffMember); 
    void printNumOfStaff();
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

void CookieShop::Oven::printOvenBrand()
{
    std::cout << "The oven's brand name is " << this->manufacturer << "." << std::endl;
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

void CookieShop::printNumOfStaff()
{
    std::cout << "Today, we have " << this->numberOfStaff << " staff members." << std::endl;
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
        void printNumOfPedals();
    };

    void takeOff(bool isRunwayClear, bool isTakeOffSpeedReached);
    void land(bool isLandingSpeedReached, bool areWheelsDeployed);
    void sendDataToControlTower(bool isGreenLightOn);
    int  increaseTotalLuggage(int totalLuggage);
    void printPlaneWingLength();
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

void Airplane::Cockpit::printNumOfPedals()
{
    std::cout << "The plane has " << this->numOfRudderPedals << " rudders." << std::endl;
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

void Airplane::printPlaneWingLength()
{
    std::cout << "The plane's wing length is " << this->lengthOfPlaneWings << " meters." << std::endl;
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
    void printNumOfUSBPorts();
    
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

void Laptop::printNumOfUSBPorts()
{
    std::cout << "The laptop has " << this->numOfUSBPorts << " USB ports." << std::endl;
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
    void printCS1CashOnHand();
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

void StripMall::printCS1CashOnHand()
{
    std::cout << "The first cookie shop has $" << this->cookieShop1.cashOnHand << " cash on hand." << std::endl;
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
    void printNumOfDisplays();
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

void NewPlaneCompany::printNumOfDisplays()
{
    std::cout << "The cockpits have " << this->cockpit1.numOfDisplays << " displays inside." << std::endl;
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
    std::cout << std::endl;

    std::cout << "We have " << cookieShop.numberOfStaff << " staff members today." << std::endl;
    cookieShop.printNumOfStaff();

    std::cout << newOven1.manufacturer << " is the oven's brand name." << std::endl;
    newOven1.printOvenBrand();
   
    std::cout << "There are " << cockpit.numOfRudderPedals << " rudders on the plane." << std::endl;
    cockpit.printNumOfPedals();
 
    std::cout << "The length of the plane's wings are " << airplane.lengthOfPlaneWings << " meters." << std::endl;
    airplane.printPlaneWingLength();
  
    std::cout << "There are " << laptop.numOfUSBPorts << " USB ports on the laptop." << std::endl;
    laptop.printNumOfUSBPorts();
    
    std::cout << "The cash on hand amount for first cookie shop is $" << stripMall.cookieShop1.cashOnHand << "." << std::endl;
    stripMall.printCS1CashOnHand();

    std::cout << "There are " << newPlaneCompany.cockpit1.numOfDisplays << " displays inside the cockpits." << std::endl;
    newPlaneCompany.printNumOfDisplays();
    std::cout << std::endl;
    
    std::cout << "good to go!" << std::endl;
    
}
