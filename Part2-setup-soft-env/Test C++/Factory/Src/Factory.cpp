#include <iostream>
#include "factory.h"

int main() {
  UARTComponent *h = new HardwareUARTComp();
  UARTDevice *d = new UARTDevice(h);
  std::cout << d->Op1();  // we are in fact calling Op1() from UARTComponent
  std::cout << d->Op2();

  d = new UARTDevice();  // we do not know yet the concrete class
  UARTComponent *s = new SoftwareUARTComp();
  d->SetComponent(s);  // set concrete class to software uart
  std::cout << d->Op1();
  std::cout << d->Op2();
  return 0;
}