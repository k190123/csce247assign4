// Copyright 2024 ksakers
#include "MonetaryAmount.h"
bool MonetaryAmount::display_unit_name = false;
//  replace all tabs with spaces
MonetaryAmount::MonetaryAmount(double value, const MonetaryUnit& unit)
: value(value), unit(unit) {}

double MonetaryAmount::GetValue() const {
  return value;
}
MonetaryUnit MonetaryAmount::GetUnit() const {
  return unit;
}

//  passed in conversion factor, set
void MonetaryAmount::ConvertToUnit(const MonetaryUnit& ma) {
  // get/set convsersion rate
  unit.SetAmountEquivalentTo1Dollar(ma.GetAmountEquivalentTo1Dollar());
  // assign new currency type and sybmol
  unit.SetName(ma.GetName());
  unit.SetSymbol(ma.GetSymbol());
  // do the math
  value = value * unit.GetAmountEquivalentTo1Dollar();
  //value = ( value * unit.GetAmountEquivalentTo1Dollar() ) / ma.GetAmountEquivalentTo1Dollar();
}
// Overload the == operator to return true if two MonetaryAmount objects hold
// the equivalent amounts, and false if they do not
bool MonetaryAmount::operator==(const MonetaryAmount& ma) const {
  // if different units convert then compare, otherwise compare directly
  if ( this->GetUnit() == ma.GetUnit() ) {
      return this->GetValue() == ma.GetValue();
  } else {
    // temp value to avoid overwritting old value
    MonetaryAmount temp = ma;
    temp.ConvertToUnit(this->GetUnit());
    return this->GetValue() == temp.GetValue();
  }
}
// return true if the MonetaryAmount object on the
// left of the operator represents a smaller monetary amount than the
// MonetaryAmount on the right, and false otherwise
bool MonetaryAmount::operator<(const MonetaryAmount& ma) const {
    // if different units convert then compare, otherwise compare directly
    if (this->GetUnit() == ma.GetUnit()) {
        return this->GetValue() < ma.GetValue();
    } else {
        // temp value to avoid overwritting old value
        MonetaryAmount temp = ma;
        temp.ConvertToUnit(this->GetUnit());
        return this->GetValue() < temp.GetValue();
    }
}
// true if the MonetaryAmount oject on the
// left of the operator represents a larger monetary amount than the
// MonetaryAmount on the right
bool MonetaryAmount::operator>(const MonetaryAmount& ma) const {
    // if different units convert then compare, otherwise compare directly
    if (this->GetUnit() == ma.GetUnit()) {
        return this->GetValue() > ma.GetValue();
    } else {
        // temp value to avoid overwritting old value
        MonetaryAmount temp = ma;
        temp.ConvertToUnit(this->GetUnit());
        return this->GetValue() > temp.GetValue();
    }
}
 //if display unit name, output '<value> <unit name>' else '<symbol> <value>'
     std::ostream & operator<<(std::ostream & os, const MonetaryAmount & ma) {
     if (ma.display_unit_name) {
         os << ma.GetValue() << " " << ma.GetUnit().GetName();
     }
     return os;
 }

// Overload the + operator to take two MonetaryAmount objects as operands and
// returns a MonetaryAmount object holding the sum of the two objects in the
// units of the left operand.
MonetaryAmount operator+(const MonetaryAmount& ma1,
const MonetaryAmount& ma2) {
    MonetaryAmount ret = ma1;
    MonetaryAmount temp = ma2;

    // convert right op to left op's units
    temp.ConvertToUnit(ret.GetUnit());
    // once converted, sum values
    ret.value = ret.GetValue() + temp.GetValue();

    return ret;
}

