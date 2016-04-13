 // Copyright 2016 Tishkin Konstantin

 #include <gtest/gtest.h>

 #include "include/complex_number.h"

 TEST(Tishkin_Konstantin_ComplexNumberTest, Can_multiple) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(3.0, 4.0);

    // Act
    ComplexNumber m = a * b;

    // Assert
    EXPECT_EQ(m, a);
}
