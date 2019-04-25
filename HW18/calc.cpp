using namespace std;
#include "ccalc.h"

CCalc::CCalc(void)
{
    m_total = 0;
}

void CCalc::Add(CCalcType value)
{
    m_total += value;
}

void CCalc::Clear(void)
{
    m_total = 0;
}

void CCalc::Divide(CalcType value)
{
    m_total /= value;
}

void CCalc::Multiply(CalcType value)
{
    m_total *= value;
}

void CCalc::SetValue(CalcType newValue)
{
    m_total = newValue;
}

void CCalc::Subtract(CalcType value)
{
    m_total -= value;
}