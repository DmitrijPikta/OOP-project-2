#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::fixed;
using std::left;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;

// struct Stud
//{
//	string name;
//	string second_name;
//	vector<int> Homework_marks;
//	int exam_mark;
//	double final_mark;
//	double second_final_mark;
// };

class Stud
{
private:
	string name_;
	string last_name_;
	vector<int> Homework_marks_;
	int exam_mark_;
	double final_mark_;
	double second_final_mark_;

public:
	Stud() : exam_mark_(0) {};
	// Student(std::istream &is);
	inline string get_name() const { return name_; };
	inline void set_name(string name) { name_ = name; };
	inline string get_last_name() const { return last_name_; };
	inline void set_last_name(string last_name) { last_name_ = last_name; };
	inline int get_exam_mark() const { return exam_mark_; };
	inline void set_exam_mark(int exam_mark) { exam_mark_ = exam_mark; };
	// inline vector<int> get_homework_marks() const { return Homework_marks_; };
	inline void set_homework_marks(int Homework_mark) { Homework_marks_.push_back(Homework_mark); };
	inline void clean_homework_marks() { Homework_marks_.clear(); };
	// double Calulate_final_mark(double (*) (vector<double>) = average) const;
};

extern double time_of_generating_file;
extern double time_of_reading_file;
extern double time_of_dividing; // For best and worst
extern double time_of_sorting;
extern double time_of_culculating;
extern double time_of_writing_files;

double Get_average_for_homework_mark(Stud student);
double Get_mediana_for_homework_mark(Stud student);
void Get_final_mark(vector<Stud> &grupe, bool for_average_homework_mark, bool for_both_homework_mark);
void Print_final_mark(vector<Stud> &grupe, bool for_average_homework_mark, bool for_both_homework_mark, bool print_results_in_terminal);
int Get_size_for_string_printing(vector<Stud> &grupe);
void generate_marks(Stud &student);
void generate_marks(vector<int> &Marks, int number_of_marks);
void generate_name(Stud &student);
void Sort_students(vector<Stud> &grupe, string parametr);
bool Generate_file_with_students(int number_of_students, int number_of_marks, string filename);
void Divide_for_two_grupse(vector<Stud> &grupe, vector<Stud> &best_grupe, vector<Stud> &worst_grupe);
void Divide_for_two_grupse(vector<Stud> &grupe, vector<Stud> &worst_grupe);
void Divide_for_two_grupse_v3(vector<Stud> &grupe, vector<Stud> &best_grupe, vector<Stud> &worst_grupe);
void Enter_students_using_txt_file_bufer_P(vector<Stud> &grupe);
