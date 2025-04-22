# Stud class 
## Rule of five:
|Method                   |Syntax                             |
|-------------------------|-----------------------------------|
|Copy-constructor         |Stud(const Stud &other)            |
|Copy-assignment operator |Stud &operator=(const Stud &other) |
|Move constructor         |Stud(Stud &&other)                 |
|Move assignment operator |Stud &operator=(Stud &&other)      |
|Destructor               |~Stud()                            |

## Input operator:
| Syntax | friend std::ostream &operator<<(std::ostream &out, const Stud &student) |
| ------ |-------------------------------------------------------------------------|

### Example of usage:
### std::cin 

When you will enter data, you will see following messages in terminal:
1. Please enter name
2. Please enter last name
3. Please input student's one homework mark, when to save it, press enter. To finish entering marks enter double slash '//'
4. Please input student's exam mark
   
To input data, answer on each question.
```
Stud student;
cin >> student;
```
### You can also input data from terminal by one string

String structure: name last_name homework_marks // exam_mark

Amount of homework_marks can be any, separate each hoemwork mark by space

String example: Alice Johnson 8 9 10 // 9

### std::stringstream

String structure: name last_name homework_marks // exam_mark

Amount of homework_marks can be any, separate each hoemwork mark by space

String exampple: Alice Johnson 8 9 10 // 9

```
std::stringstream ss("Alice Johnson 8 9 10 // 7");
Stud student;
ss >> student;
```

## Output operator:
| Syntax | friend std::istream &operator>>(std::istream &in, Stud &student) |
| ------ |------------------------------------------------------------------|

### Example of usage:
## std::cout

You can output data in terminal by std::cout 
```
Stud student;
//input data to student
//calcutating final mark for student
std::cout << student;
```

## std::ofstream 

You can output data to file by std::ofstream

```
Stud student;
//input data to student
//calcutating final mark for student
std::ofstream fr(filename);
fr << student;
fr.close();
```

## std::ostringstream

You can output data to string using std::ostringstream

```
Stud student;
//input data to student
//calcutating final mark for student
std::ostringstream oss;
oss << student;
string result = oss.str();
```
### Example of output:
![Screenshot 2025-04-22 125753](https://github.com/user-attachments/assets/f23248e3-5f59-43be-8f4d-5d6ef6cd4d13)

## Warning
Stud class by default do not calculate final mark, so if you before outputing student have not calculated final mark ourselves, in the output final mark would be equal 0.

## Final mark
It is possible to have 1 or 2 final marks. If you have set only first final_mark, you would see one final mark in output. If you have set first and second final mark, you would see both in output.
To set it use setter:
```
Stud student;
double final_mark;
student.set_final_mark(final_mark);
student.set_second_final_mark(final_mark);
```
Also to calculate final mark you can use build-in methods to get average or mediana of homeworks marks.
Average:
```
student.Get_average_for_homework_mark();
```
Mediana:
```
student.Get_mediana_for_homework_mark();
```

### Example of calculating final mark:
```
Stud student;
//intup data to student
student.set_final_mark(student.Get_average_for_homework_mark());
student.set_second_final_mark(student.Get_mediana_for_homework_mark());
```












