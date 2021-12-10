#include <iostream>

using namespace std;
//class decleration of student class
class student
{
private:
    long ID;
    string name;
    string surname;
    float quiz_score[4];
    float hw_score[3];
    float final_score;
public:
    student ();
    void SetID (long);
    void SetName (string );
    void SetSurname (string);
    void SetQuiz_Score (float,float, float,float);
    void SetHw_Score (float,float, float);
    void SetFinal_Score (float);
    long GetID();
    string GetName();
    string GetSurname();
    float* GetQuiz_Score();
    float* GetHw_score();
    float GetFinal_score();
    float calculate_overall(float, float, float);
};
//class decleration of course class
class course
{
private:
        student students[10];
        int num = 0;
        float weightQ;
        float weightHW;
        float weightF;
public:
    course();
        int getNum();
        void addnewStudent(long id, string Name, string Surname);
        void updateWeights(float weightq, float weighthw, float weightf);
        student* getStudentInfo(long id);
        float* calculateAverage();
        float getweightQ()const{return weightQ;}
        float getweightHw()const{return weightHW;}
        float getweightF()const{return weightF;}
        void setweightQ(float newweightQ){weightQ = newweightQ;}
        void setweightHW(float newweightHW){weightHW = newweightHW;}
        void setweightF(float newweightF){weightF = newweightF;}
} ;
//constructor of student
student::student(){
this->ID = 0;
this->name = "";
this->surname = "";
this->quiz_score[0] = 0;
this->quiz_score[1] = 0;
this->quiz_score[2] = 0;
this->quiz_score[3] =0;
this->hw_score[0] = 0;
this->hw_score[1] = 0;
this->hw_score[2] = 0;
this->final_score = 0;
}
//constructor of course
course::course(){
this->num = 0;
this-> weightQ = 0.3;
this-> weightHW = 0.3;
this->weightF = 0.4;
}

course EE441;

//function takes ID, name and surname then add a new student to the classroom.
void addNewStudent(long ID, string name, string surname ){
EE441.addnewStudent(ID, name, surname);
}
//function takes ID then shows the ID, name, surname and scores of the student.
void showStudent(long ID){
EE441.getStudentInfo(ID);
}
//This function changes the scores of a student by taking ID and scores.
void changeStudentScores(long ID, float* quiz_scores, float* hw_scores, float final_score){
student *S;
S = EE441.getStudentInfo(ID);
S->SetQuiz_Score(quiz_scores[0],quiz_scores[1],quiz_scores[2],quiz_scores[3]);
S->SetHw_Score(hw_scores[0],hw_scores[1],hw_scores[2]);
S->SetFinal_Score(final_score);
}
//this functions takes new values of the weight, then change them.
void changeWeights(float weightQ, float weightHW, float weightF){
EE441.updateWeights(weightQ, weightHW, weightF);
}

void showAverage(){
EE441.calculateAverage();
}
void showAbove(){
EE441.calculateAverage()[4];

//for loop
}
void showBelow(){
EE441.calculateAverage()[4];

//for loop
}

int main(){
    cout<< "EE441 Classroom Interface" << endl;
    cout<< "1) Add Student" << endl;
    cout<< "2) Search a student by ID" << endl;
    cout<< "3) Change a student's score" << endl;
    cout<< "4) Update weights" << endl;
    cout<< "5) Show classroom average" << endl;
    cout<< "6) Show Students with overall score above a treshold" << endl;
    cout<< "7) Show Students with overall score below a treshold" << endl;
    cout<< "8) Exit" << endl;
    while (1){
    cout<< "Enter your choice:"<<endl;
    int a;
    std::cin>>a;

    switch(a){
        //1) add a student
        case 1:{
            long ID;
            string name;
            string surname;
            cout<<"Enter Student's ID, name, surname"<<endl;
            cin>> ID >> name >> surname;
            addNewStudent(ID, name, surname);
            break;
        }
        case 2:{
            long ID;
            cout<<"Enter Student's ID to search"<<endl;
            cin>> ID;
            showStudent(ID);
            break;
        }
        case 3:{
            long ID;
            float quiz_scores[4];
            float hw_scores[3];
            float final_score;
            cout<<"Enter Student's ID and scores to change student's score"<<endl;
            cin>> ID >> quiz_scores[0] >>quiz_scores[1] >>quiz_scores[2] >>quiz_scores[3]
            >>hw_scores[0] >>hw_scores[1] >> hw_scores[2] >>final_score;
            changeStudentScores(ID,quiz_scores,hw_scores,final_score);
            break;
        }
        case 4:{
            float weightQ;
            float weightHW;
            float weightF;
            cout<<"Enter new exam weights to change exam weights"<<endl;
            cin>> weightQ >> weightHW >>weightF;
            changeWeights(weightQ, weightHW,weightF);
            break;
        }
        case 5: {
            showAverage();
            break;
        }
  //      case 6: {

   //         break;
   //     }
    //    case 7: {

     //       break;
       // }
        case 8: {
            return 0 ;
            break;
        }

    }

}}


void student::SetID(long Id){
    ID = Id;
}
void student::SetName(string Name){
    name = Name;
}
void student::SetSurname(string Surname){
    surname = Surname;
}
void student::SetQuiz_Score(float Quiz_score0,float Quiz_score1,float Quiz_score2,float Quiz_score3){
    quiz_score[0] = Quiz_score0;
    quiz_score[1] = Quiz_score1;
    quiz_score[2] = Quiz_score2;
    quiz_score[3] = Quiz_score3;
}
void student::SetHw_Score(float Hw_score0,float Hw_score1, float Hw_score2){
    hw_score[0] = Hw_score0;
    hw_score[1] = Hw_score1;
    hw_score[2] = Hw_score2;
}
void student::SetFinal_Score(float Final_score){
    final_score = Final_score;
}
long student::GetID(){
    return ID;
}
string student::GetName(){
    return name;
}
string student::GetSurname(){
    return surname;
}
float* student::GetQuiz_Score(){
    return quiz_score;
}
float* student::GetHw_score(){
    return hw_score;
}
float student::GetFinal_score(){
    return final_score;
}
float student::calculate_overall(float weightq_=0.3, float weighthw_=0.3, float weightf_=0.4){
 float overall = ((((quiz_score[0] + quiz_score[1]+ quiz_score[2]+ quiz_score[3])/4)*weightq_)+((( hw_score[0]+ hw_score[1]+ hw_score[2])/3)*weighthw_)+(final_score*weightf_));
    return overall;
}

int course::getNum(){
    return num;
}
void course::addnewStudent(long id, string Name, string Surname){
    student  S;
    S.SetID(id);
    S.SetName(Name);
    S.SetSurname(Surname);
    students[num] = S;
    num += 1;
}
void course::updateWeights(float weightq, float weighthw, float weightf){
    setweightQ(weightq);
    setweightHW(weighthw);
    setweightF(weightf);
}
student* course::getStudentInfo(long id){
    int valid = 0;
    if (id < 0){
        cout<< "ID cannot be negative"<<endl;
        return 0;
    }
    for(int i=0; i<num; i++){
        if (students[i].GetID() == id){
        cout
        <<students[i].GetID()<<" "
        <<students[i].GetName()<<" "
        <<students[i].GetSurname()<<" "
        <<students[i].GetQuiz_Score()[0]<<" "
        <<students[i].GetQuiz_Score()[1]<<" "
        <<students[i].GetQuiz_Score()[2]<<" "
        <<students[i].GetQuiz_Score()[3]<<" "
        <<students[i].GetHw_score()[0]<<" "
        <<students[i].GetHw_score()[1]<<" "
        <<students[i].GetHw_score()[2]<<" "
        <<students[i].GetFinal_score()<<" "
        <<endl;
         valid = 1;
         return &students[i];
        }
    }
    if (valid == 0){
        cout<< "Student cannot found"<< endl;
    }


}
float* course::calculateAverage() {
    float sum_of_quizes = 0;
    float sum_of_hws = 0;
    float sum_of_final= 0;
    float average[4];
    for (int i = 0; i<num; i++){
        for (int j=0; j<4;j++){
            sum_of_quizes += students[i].GetQuiz_Score()[j];
        }

        for (int j=0;j<3;j++){
            sum_of_hws += students[i].GetHw_score()[j];
        }
        sum_of_final += students[i].GetFinal_score();
    }
    float average_of_quizes =  sum_of_quizes/(4*num);
    float average_of_hws = sum_of_hws/(3*num);
    float average_of_finals = sum_of_final/num;
    float threshold = average_of_quizes*weightQ + average_of_hws*weightHW + average_of_finals*weightF;
    average[0]= average_of_quizes;
    average[1]= average_of_hws;
    average[2]= average_of_finals;
    average[3]= threshold;
    cout<<average[0]<<" "<<average[1]<<" "<<average[2]<<endl;

    return average;
}
