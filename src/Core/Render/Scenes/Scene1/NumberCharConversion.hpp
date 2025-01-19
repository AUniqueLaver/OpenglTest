#pragma once


#include "Base.hpp"

#include <cstddef>
#include <cstdint>
#include <utility>

#include <iostream>


struct Fraction
{
   public:
    Fraction()
    : m_nominator{0},
      m_denominator{0}
    {

    }
    Fraction(int32_t nominator,
             int32_t denominator)
    : m_nominator{nominator},
      m_denominator{denominator}
    {

    }
    Fraction(int32_t nominator)
    : m_nominator{nominator},
      m_denominator{1}
    {

    }
    ~Fraction()
    {

    }

    int32_t nominator() const
    {
    return m_nominator;
    }
   
    int32_t denominator() const
    {
    return m_denominator;
    }

    Fraction operator/(const Fraction a1)
    {
    return Fraction{m_nominator * a1.m_denominator, m_denominator * a1.m_nominator};
    }

    void operator/=(const Fraction a1)
    {
    m_nominator *= a1.m_denominator;
    m_denominator *= a1.m_nominator;
    }

    Fraction operator*(const Fraction a1)
    {
    return Fraction{m_nominator * a1.denominator(), m_denominator};
    }
   
   private:
    int32_t m_nominator;
    int32_t m_denominator;
};

float log(float base, float a);

std::pair<int32_t, Fraction> divisionRemainder(const int32_t diviseAmount, const int32_t divisor);

Fraction divisionFraction(const int32_t divisor, int32_t diviseAmount);

int32_t basePlacesDivide(const int32_t source, const int32_t base);

std::string numericChar(int32_t digit);

int32_t charNumber(const char* characters);
