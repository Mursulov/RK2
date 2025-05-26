#include <gtest/gtest.h>
#include "bridge.hpp"

TEST(ConcreteImplementationA, OperationImplementation) {
    ConcreteImplementationA impl;
    EXPECT_EQ(impl.OperationImplementation(), "ConcreteImplementationA: Here's the result on the platform A.\n");
}

TEST(ConcreteImplementationB, OperationImplementation) {
    ConcreteImplementationB impl;
    EXPECT_EQ(impl.OperationImplementation(), "ConcreteImplementationB: Here's the result on the platform B.\n");
}

TEST(Abstraction, Operation) {
    ConcreteImplementationA impl;
    Abstraction abs(&impl);
    EXPECT_EQ(abs.Operation(), "Abstraction: Base operation with:\nConcreteImplementationA: Here's the result on the platform A.\n");
}

TEST(ExtendedAbstraction, Operation) {
    ConcreteImplementationB impl;
    ExtendedAbstraction abs(&impl);
    EXPECT_EQ(abs.Operation(), "ExtendedAbstraction: Extended operation with:\nConcreteImplementationB: Here's the result on the platform B.\n");
}
