#pragma once
#include <iostream>
/////////////////////////////////////////////////////////////////////////////////////
/// @brief The UARTComponent Class (a factory)
/// @fn declares a virtual UARTComponent factory Class that can be linked by the
/// UARTDevice class without worrying about the actual concrete class
/////////////////////////////////////////////////////////////////////////////////////
class UARTComponent {
 public:
  UARTComponent() { std::cout << "ctor of virtual UARTComp class called\n"; }

  ///  @brief virtual method to do some stuff must be provided by children class
  ///  @return a string
  virtual std::string Op1() const = 0;

  /// @brief virtual method to do some stuff must be provided by children class
  /// @return a string
  virtual std::string Op2() const = 0;
};

/// @brief Concrete Component provide various implementations of the Device interface.
class HardwareUARTComp : public UARTComponent {
 public:
  HardwareUARTComp() { std::cout << "Creating a Hardware UART Comp \n"; }

  /// @brief do some stuff on a Hardware UART
  /// @return string
  std::string Op1() const override { return "I'am doing operation 1 on a hardware UART\n"; }

  /// @brief do some stuff on a Hardware UART
  /// @return string
  std::string Op2() const override { return "I'am doing operation 2 on a hardware UART\n"; }
};

class SoftwareUARTComp : public UARTComponent {
 public:
  /// @brief Construct a new SoftwareUART object
  SoftwareUARTComp() { std::cout << "Creating a Software UART Comp \n"; }

  /// @brief do some stuff on a SoftwareUART
  /// @return string
  std::string Op1() const override { return "I'am doing operation 1 on a software UART\n"; }

  /// @brief do some stuff on a SoftwareUART
  /// @return string
  std::string Op2() const override { return "I'am doing operation 2 on a software UART\n"; }
};

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief The UARTDevice Class (use the UARTComponent factory class)
/// @fn declares a UART Class that can be used without knowing
/// the actual type of concrete UARTComponent used
//////////////////////////////////////////////////////////////////////////////////////////
class UARTDevice {
 public:
  /// @brief Constructs a new UARTDevice without knowing the actual UARTComponent used.
  UARTDevice() {}

  /// @brief Constructs a new UARTDevice object and link tot the concrete UART
  /// @param uart the concrete UART Component object
  UARTDevice(UARTComponent *component) : concrete_component_(component) {}

  /// @brief Set the link to concrete UART Component
  /// @param uart a pointer to a concrete UARTComponent
  void SetComponent(UARTComponent *uart) {
    concrete_component_ = uart;
    std::cout << "linking to UART comp\n";
  }

  /// @brief provide an Op1 method that just call the equivalent function
  /// provided by the concrete UARTComponent class.
  /// @return std::string
  std::string Op1() const { return this->concrete_component_->Op1(); }

  /// @brief provide an Op1 method that just call the equivalent function
  /// provided by the concrete UARTComponent class.
  /// @return std::string
  std::string Op2() const { return this->concrete_component_->Op2(); }

 protected:
  UARTComponent *concrete_component_{nullptr};
};
