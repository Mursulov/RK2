#include "bridge.hpp"
#include <iostream>

std::string ConcreteImplementationA::OperationImplementation() const {
    return "ConcreteImplementationA: Here's the result on the platform A.\n";
}

std::string ConcreteImplementationB::OperationImplementation() const {
    return "ConcreteImplementationB: Here's the result on the platform B.\n";
}

Abstraction::Abstraction(Implementation* implementation) : implementation_(implementation) {}
Abstraction::~Abstraction() {}

std::string Abstraction::Operation() const {
    return "Abstraction: Base operation with:\n" + implementation_->OperationImplementation();
}

ExtendedAbstraction::ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {}
std::string ExtendedAbstraction::Operation() const {
    return "ExtendedAbstraction: Extended operation with:\n" + implementation_->OperationImplementation();
}

void ClientCode(const Abstraction& abstraction) {
    std::cout << abstraction.Operation();
}
