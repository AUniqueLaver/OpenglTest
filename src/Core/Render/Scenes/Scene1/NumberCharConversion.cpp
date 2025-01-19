
#include "NumberCharConversion.hpp"


float log(float base, float a)
{
    return log10(a) / log10(base);
}

std::pair<int32_t, Fraction> divisionRemainder(const int32_t diviseAmount, const int32_t divisor)
{
    if(divisor == 0)
    {
    std::cout << "Cannot divide by zero\n";
    }
  
    int32_t timesDivideBy = 0;
    int32_t diviseAmountDivising = diviseAmount;

    while((diviseAmountDivising - divisor) >= 0)
    {
    diviseAmountDivising -= divisor;
    timesDivideBy++;
    }


    return std::pair<int32_t, Fraction>{timesDivideBy, Fraction{diviseAmountDivising, divisor}};
}

Fraction divisionFraction(const int32_t divisor, int32_t diviseAmount)
{
    if(divisor == 0)
    {
    std::cout << "Cannot divide by zero\n";
    }
  
    int32_t timesDivideBy = 0;
    while((diviseAmount - divisor) > 0)
    {
    diviseAmount -= divisor;
    timesDivideBy++;
    }


    return Fraction{diviseAmount + (timesDivideBy * divisor), divisor};
}

int32_t basePlacesDivide(const int32_t source, const int32_t base)
{
    int32_t basePlaces = 0;

    Fraction sourceDivide{source, 1};
    Fraction baseA{base, 1};
   

    while((sourceDivide / baseA).nominator() >= (sourceDivide / baseA).denominator())
    {
    baseA = Fraction{baseA.nominator() * base, baseA.denominator()};
    basePlaces++;
    }

    return basePlaces;
}

// [ Create definition for signed numbers ]
std::string numericChar(int32_t source)
{
    int32_t placesDecimals = basePlacesDivide(source, 10);

    // std::cout << "Decimal place " << numberOfDecimals << '\n';
    std::unique_ptr<char[]> numberBuffer = std::make_unique<char[]>(static_cast<uint32_t>(placesDecimals));

    std::vector<int32_t> numberStore{0};
    std::vector<int32_t> numberPreviousStore;


    int32_t divideStandard = static_cast<int32_t>(pow(10, placesDecimals));
    uint32_t numberStoreIndex = 0;
    Fraction numberDecimal = Fraction{source} / Fraction{divideStandard};
    int32_t numberSpecfied = divisionRemainder(numberDecimal.nominator(), numberDecimal.denominator()).first;

    numberPreviousStore.push_back(numberSpecfied);

    numberStore[numberStoreIndex] = numberSpecfied;

    placesDecimals--;
    divideStandard = static_cast<int32_t>(pow(10, placesDecimals));


    while((placesDecimals + 1) > 0)
    {
    numberStore.push_back(0);

    numberDecimal = Fraction{source} / Fraction{divideStandard};

    numberSpecfied = divisionRemainder(numberDecimal.nominator(), numberDecimal.denominator()).first;
    numberPreviousStore.push_back(numberSpecfied);
    numberSpecfied = numberSpecfied - (numberPreviousStore[numberStoreIndex] * 10);

    numberStore[numberStore.size() - 1] = numberSpecfied;

    numberStoreIndex++;
    placesDecimals--;
    divideStandard = static_cast<int32_t>(pow(10, placesDecimals));
    }

    // for(uint32_t i = 0; i < numberStore.size(); i++)
    // {
    // std::cout << numberStore[i] << '\n';
    // }
    
    for(uint32_t i = 0; i < numberStore.size(); i++)
    {
    switch(numberStore[i])
    {
    case 0:
    strcat(numberBuffer.get(), "0");
    break;
    case 1:
    strcat(numberBuffer.get(), "1");
    break;
    case 2:
    strcat(numberBuffer.get(), "2");
    break;
    case 3:
    strcat(numberBuffer.get(), "3");
    break;
    case 4:
    strcat(numberBuffer.get(), "4");
    break;
    case 5:
    strcat(numberBuffer.get(), "5");
    break;
    case 6:
    strcat(numberBuffer.get(), "6");
    break;
    case 7:
    strcat(numberBuffer.get(), "7");
    break;
    case 8:
    strcat(numberBuffer.get(), "8");
    break;
    case 9:
    strcat(numberBuffer.get(), "9");
    break;
    default:
    break;
    }

    }


    return std::string{numberBuffer.get()};
}

int32_t charNumber(const char* characters)
{
    const char* charStart = characters;
    std::vector<char> chars;
    int32_t charIteration = 0;
   
    while(*(charStart + charIteration) != '\0')
    {
    chars.push_back(*(charStart + charIteration));
    charIteration++;

    }


    int32_t charSize = 0;
    for(auto charsIt = chars.begin(); charsIt != chars.end(); charsIt++)
    {
    charSize++;
    }


    if((charSize - 1) < 0)
    {
    return 0;
    }

    double num = 0;
    double base = pow(10, charSize - 1);
    for(auto charsIt = chars.begin(); charsIt != chars.end(); charsIt++)
    {
    switch(*charsIt)
    {
    case '0':
    num += (0 * base);
    break;
    case '1':
    num += (1 * base);
    break;
    case '2':
    num += (2 * base);
    break;
    case '3':
    num += (3 * base);
    break;
    case '4':
    num += (4 * base);
    break;
    case '5':
    num += (5 * base);
    break;
    case '6':
    num += (6 * base);
    break;
    case '7':
    num += (7 * base);
    break;
    case '8':
    num += (8 * base);
    break;
    case '9':
    num += (9 * base);
    break;
    default:
    break;
    }

    base /= 10;
    }


    return static_cast<int32_t>(num);
}
