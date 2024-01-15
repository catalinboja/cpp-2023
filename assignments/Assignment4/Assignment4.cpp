#include "pch.h"
#include "CppUnitTest.h"
#include "Assignment4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment4
{
	TEST_CLASS(TesteUnitare)
	{
	public:
		
		TEST_METHOD(_01TestStudentDeserialization)
		{

			Student student;
			student.deserialize("john.bck");

			Assert::IsTrue(student.name._Equal("John"), L"Student::name not Ok");
			Assert::IsTrue(student.program.name._Equal("Business Informatics"), L"Student::program not Ok");
			Assert::IsTrue(strcmp(student.program.faculty, "CSIE") == 0,
				L"Student::faculty not Ok");
			Assert::IsTrue(strcmp(student.program.university, "ASE") == 0,
				L"Student::faculty not Ok");
			Assert::IsTrue(student.grades[0].course._Equal("OOP"), L"Student::grades not Ok");
			Assert::IsTrue(student.grades[1].course._Equal("Data Analysis"), L"Student::grades not Ok");
			Assert::IsTrue(student.grades[2].value == 9, L"Student::grades not Ok");
			Assert::IsTrue(student.hasScholarship, L"Student::hasScholarship not Ok");
		}

		TEST_METHOD(_02TestStudentListDeserialization)
		{

			StudentList students;

			students.deserialize("students.bck");
			Assert::IsTrue(students.list[2].name._Equal("Bob"), L"StudentList::name not Ok");
			Assert::IsTrue(students.list[2].program.name._Equal("Marketing"), L"Student::program not Ok");
			Assert::IsTrue(strcmp(students.list[2].program.faculty, "MK") == 0, L"StudentList::faculty not Ok");
			Assert::IsTrue(strcmp(students.list[2].program.university, "ASE") == 0, L"StudentList::faculty not Ok");
			Assert::IsTrue(students.list[2].grades[0].course._Equal("Marketing"), L"StudentList::grades not Ok");
			Assert::IsTrue(students.list[2].grades[1].course._Equal("Commerce"), L"StudentList::grades not Ok");
			Assert::IsTrue(students.list[2].grades[3].value == 10, L"StudentList::grades not Ok");
		}
	};
}
