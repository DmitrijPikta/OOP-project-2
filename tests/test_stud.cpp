#include "../src/header.h"
#include <cassert>
#include <iostream>

void test_operator_assignment()
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
    assert(student2.get_name() == "John");
    assert(student2.get_last_name() == "Doe");
    assert(student2.get_exam_mark() == 8);
    assert(student2.Get_average_for_homework_mark() == student1.Get_average_for_homework_mark());

    cout << "test_operator_assignment passed!" << endl;
}

void test_copy_constructor()
{
    // Create a Stud object
    Stud student1("Alice", "Johnson");
    student1.set_exam_mark(9);
    student1.set_homework_marks(10);
    student1.set_homework_marks(8);

    // Use the copy constructor
    Stud student2(student1);

    // Verify that student2 has the same data as student1
    assert(student2.get_name() == "Alice");
    assert(student2.get_last_name() == "Johnson");
    assert(student2.get_exam_mark() == 9);
    assert(student2.Get_average_for_homework_mark() == student1.Get_average_for_homework_mark());

    cout << "test_copy_constructor passed!" << endl;
}

void test_move_constructor()
{
    // Create a Stud object
    Stud student1("Bob", "Brown");
    student1.set_exam_mark(7);
    student1.set_homework_marks(6);
    student1.set_homework_marks(8);

    // Use the move constructor
    Stud student2(move(student1));

    // Verify that student2 has the same data as student1
    assert(student2.get_name() == "Bob");
    assert(student2.get_last_name() == "Brown");
    assert(student2.get_exam_mark() == 7);
    assert(student2.Get_average_for_homework_mark() == 7.0);
    assert(student1.get_name() == "");
    assert(student1.get_last_name() == "");
    assert(student1.get_exam_mark() == 0);
    assert(student1.Get_average_for_homework_mark() == 0);

    cout << "test_move_constructor passed!" << endl;
}

void test_move_assignment()
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
    assert(student2.get_name() == "Charlie");
    assert(student2.get_last_name() == "Green");
    assert(student2.get_exam_mark() == 10);
    assert(student2.Get_average_for_homework_mark() == 8.5);
    assert(student1.get_name() == "");
    assert(student1.get_last_name() == "");
    assert(student1.get_exam_mark() == 0);
    assert(student1.Get_average_for_homework_mark() == 0);

    cout << "test_move_assignment passed!" << endl;
}

void test_input_operator_stream()
{
    // Create a string stream to simulate input
    std::stringstream ss("Alice Johnson 8 9 10 // 7");

    // Create a Stud object using the input operator
    Stud student;
    ss >> student;

    // Verify that the data was read correctly
    assert(student.get_name() == "Alice");
    assert(student.get_last_name() == "Johnson");
    assert(student.get_exam_mark() == 7);
    assert(student.Get_average_for_homework_mark() == 9.0);

    cout << "test_input_operator_stream passed!" << endl;
}

void test_output_operator_stream()
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
    assert(oss.str() == expected_output);

    cout << "test_output_operator_stream passed!" << endl;
}

void test_destructor()
{
    // Create a Stud object
    Stud student("Ivan", "Smirnov");
    student.set_homework_marks(5);
    student.set_exam_mark(10);
    student.set_final_mark(0.6 * student.get_exam_mark() + 0.4 * student.Get_average_for_homework_mark());
    student.set_second_final_mark(0.6 * student.get_exam_mark() + 0.4 * student.Get_mediana_for_homework_mark());

    // Call destructor for Stud object
    student.~Stud();

    // Verify that the data was removed
    assert(student.get_name() == "");
    assert(student.get_last_name() == "");
    assert(student.get_exam_mark() == 0);
    assert(student.Get_average_for_homework_mark() == 0);
    assert(student.get_final_mark() == 0);
    assert(student.get_second_final_mark() == 0);
}

int main()
{
    test_operator_assignment();
    test_copy_constructor();
    test_move_constructor();
    test_move_assignment();
    test_input_operator_stream();
    test_output_operator_stream();
    test_destructor();
    return 0;
}
