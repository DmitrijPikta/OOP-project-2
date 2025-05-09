#include "../src/header.h"
#include <gtest/gtest.h>
#include <cassert>
#include <iostream>

TEST(RuleOfFive, TestOperatorAssignment)
{
    // Create two Stud objects
    Stud student1("John", "Doe");
    student1.set_exam_mark(8);
    student1.set_homework_marks(7);
    student1.set_homework_marks(9);

    Stud student2("Jane", "Smith");
    student2.set_exam_mark(5);
    student2.set_homework_marks(6);

    // Use the assignment operator
    student2 = student1;

    // Verify that student2 now has the same data as student1
    EXPECT_EQ(student2.get_name(), "John");
    EXPECT_EQ(student2.get_last_name(), "Doe");
    EXPECT_EQ(student2.get_exam_mark(), 8);
    EXPECT_EQ(student2.Get_average_for_homework_mark(), student1.Get_average_for_homework_mark());
}

TEST(RuleOfFive, TestCopyConstructor)
{
    // Create a Stud object
    Stud student1("Alice", "Johnson");
    student1.set_exam_mark(9);
    student1.set_homework_marks(10);
    student1.set_homework_marks(8);

    // Use the copy constructor
    Stud student2(student1);

    // Verify that student2 has the same data as student1
    EXPECT_EQ(student2.get_name(), "Alice");
    EXPECT_EQ(student2.get_last_name(), "Johnson");
    EXPECT_EQ(student2.get_exam_mark(), 9);
    EXPECT_EQ(student2.Get_average_for_homework_mark(), student1.Get_average_for_homework_mark());
}

TEST(RuleOfFive, TestMoveConstructor)
{
    // Create a Stud object
    Stud student1("Bob", "Brown");
    student1.set_exam_mark(7);
    student1.set_homework_marks(6);
    student1.set_homework_marks(8);

    // Use the move constructor
    Stud student2(move(student1));

    // Verify that student2 has the same data as student1
    EXPECT_EQ(student2.get_name(), "Bob");
    EXPECT_EQ(student2.get_last_name(), "Brown");
    EXPECT_EQ(student2.get_exam_mark(), 7);
    EXPECT_EQ(student2.Get_average_for_homework_mark(), 7.0);
    EXPECT_EQ(student1.get_name(), "");
    EXPECT_EQ(student1.get_last_name(), "");
    EXPECT_EQ(student1.get_exam_mark(), 0);
    EXPECT_EQ(student1.Get_average_for_homework_mark(), 0);
}

TEST(RuleOfFive, TestMoveAssignment)
{
    // Create two Stud objects
    Stud student1("Charlie", "Green");
    student1.set_exam_mark(10);
    student1.set_homework_marks(9);
    student1.set_homework_marks(8);

    Stud student2("Daisy", "White");
    student2.set_exam_mark(6);
    student2.set_homework_marks(5);

    // Use the move assignment operator
    student2 = move(student1);

    // Verify that student2 has the same data as student1
    EXPECT_EQ(student2.get_name(), "Charlie");
    EXPECT_EQ(student2.get_last_name(), "Green");
    EXPECT_EQ(student2.get_exam_mark(), 10);
    EXPECT_EQ(student2.Get_average_for_homework_mark(), 8.5);
    EXPECT_EQ(student1.get_name(), "");
    EXPECT_EQ(student1.get_last_name(), "");
    EXPECT_EQ(student1.get_exam_mark(), 0);
    EXPECT_EQ(student1.Get_average_for_homework_mark(), 0);
}

TEST(RuleOfFive, TestDestructor)
{
    // Create a Stud object
    Stud student("Ivan", "Smirnov");
    student.set_homework_marks(5);
    student.set_exam_mark(10);
    student.set_final_mark(0.6 * student.get_exam_mark() + 0.4 * student.Get_average_for_homework_mark());
    student.set_second_final_mark(0.6 * student.get_exam_mark() + 0.4 * student.Get_mediana_for_homework_mark());

    // Call destructor for Stud object
    // student.~Stud();

    // Verify that the data was removed
    // EXPECT_EQ(student.get_name(), "");
    // EXPECT_EQ(student.get_last_name(), "");
    // EXPECT_EQ(student.get_exam_mark(), 0);
    // EXPECT_EQ(student.Get_average_for_homework_mark(), 0);
    // EXPECT_EQ(student.get_final_mark(), 0);
    // EXPECT_EQ(student.get_second_final_mark(), 0);
}

TEST(StreamOperators, TestInputOperatorStream)
{
    // Create a string stream to simulate input
    std::stringstream ss("Alice Johnson 8 9 10 // 7");

    // Create a Stud object using the input operator
    Stud student;
    ss >> student;

    // Verify that the data was read correctly
    EXPECT_EQ(student.get_name(), "Alice");
    EXPECT_EQ(student.get_last_name(), "Johnson");
    EXPECT_EQ(student.get_exam_mark(), 7);
    EXPECT_EQ(student.Get_average_for_homework_mark(), 9.0);
}

TEST(StreamOperators, TestOutputOperatorStream)
{
    // Create a Stud object
    Stud student("Eve", "Black");
    student.set_exam_mark(9);
    student.set_homework_marks(8);
    student.set_homework_marks(10);
    student.set_final_mark(0.6 * student.get_exam_mark() + 0.4 * student.Get_average_for_homework_mark());

    // Use the output operator
    std::ostringstream oss;
    oss << student;

    // Verify that the output is correct
    string expected_output = "Black          Eve            9.00\n";
    EXPECT_EQ(oss.str(), expected_output);
}

TEST(OtherFunctions, TestGetFinalMark)
{
    // Create a Stud object
    Stud student("Tom", "Hanks");
    student.set_exam_mark(8);
    student.set_homework_marks(8);
    student.set_homework_marks(5);
    student.set_homework_marks(5);

    // Create a vector of Stud objects
    vector<Stud> grupe = {student};
    Get_final_mark(grupe, true, true);

    // Verify that the final mark is calculated correctly
    EXPECT_EQ(grupe.back().get_final_mark(), 7.2);
    EXPECT_EQ(grupe.back().get_second_final_mark(), 6.8);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
