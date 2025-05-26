#pragma once
#include <string>

class Implementation {
 public:
  virtual ~Implementation() {}
  virtual std::string OperationImplementation() const = 0;
};

class ConcreteImplementationA : public Implementation {
 public:
  std::string OperationImplementation() const override;
};

class ConcreteImplementationB : public Implementation {
 public:
  std::string OperationImplementation() const override;
};

class Abstraction {
 protected:
  Implementation* implementation_;
 public:
  Abstraction(Implementation* implementation);
  virtual ~Abstraction();
  virtual std::string Operation() const;
};

class ExtendedAbstraction : public Abstraction {
 public:
  ExtendedAbstraction(Implementation* implementation);
  std::string Operation() const override;
};

void ClientCode(const Abstraction& abstraction);
