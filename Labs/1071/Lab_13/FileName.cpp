#include <iostream>
#include <string>

using namespace std;

class Evaluation {
protected:
	string name;
	string date;
public:
	Evaluation(string name, string date) :
		name(name), date(date) {

	}

	virtual void printDetails() {
		cout << endl << "Evalation " << name << " on " << this->date;
	}
};

class Question {
	string question;
	string* posibleAnswers;
	int noAnswers;
	int correctAnswerIndex;
};

class Quiz : public Evaluation {
	int noQuestions;
	int pointsPerQuestion;
	//Question* questions;
public:
	Quiz(string name, string date, int noQuestions, int points)
		:Evaluation(name, date) {
		this->noQuestions = noQuestions;
		this->pointsPerQuestion = points;
	}

	void printQuizDetails() {
		this->printDetails();
		cout << endl << "The quiz will have "
			<< this->noQuestions << " questions,  for "
			<< this->pointsPerQuestion << " points each";
	}
};

class Exam : public Evaluation {
	float duration;
	int roomNumber;
	string courseName;
public:
	Exam(string name, float duration, int room, string course) :
		Evaluation(name, "not known"), duration(duration),
		roomNumber(room), courseName(course) {

	}

	//override 
	void printDetails() {
		//call the Evaluation version
		this->Evaluation::printDetails();
		cout << endl << "The exam for " << this->courseName
			<< " will take place in room "
			<< this->roomNumber << " for "
			<< this->duration << " minutes ";
	}
};

void processEvalution(Evaluation* ev) {

}

int main( int argc, char** argv) {

	cout << endl << argv[0];

	if (argc == 2) {
		cout << endl << argv[1];
	}

	Evaluation laboratoryTest("Laboratory test", "11-12-2023");
	Quiz courseQuiz("Course quiz","15-01-2024",20,4.5);
	Exam oopExam("OOP Exam", 60, 2316, "OOP");

	Evaluation* evaluations[5];
	Evaluation** otherEvaluations = new Evaluation * [5];

	evaluations[0] = &laboratoryTest;
	evaluations[1] = &courseQuiz;
	evaluations[2] = &oopExam;

	evaluations[3] = new Quiz(
		"Macroeconomics Quiz", "17-01-2024", 90, 1);
	evaluations[4] = new Exam("Database", 120, 2017, "DB");


	for (int i = 0; i < 5; i++) {
		//if (i == 1) //NOT LIKE THIS

		//PROPER WAY OF DOWN-CASTING
		Quiz* q = dynamic_cast<Quiz*>(evaluations[i]);
		if(q != nullptr)
		{
			Quiz* quiz = (Quiz*)evaluations[i];
			quiz->printQuizDetails();
		}
		else {
			evaluations[i]->printDetails();
		}
		
	}

}