#include <iostream>
# include <string>
#include <vector>

using namespace std;

// name, studentID, grade
// create a class Student
class Student {
    private:
        string name;
        int studentID;
        float grade;

    public:
        Student(string name,int studentID,float grade){
            this->name = name;
            this->studentID = studentID;
            this->grade = grade;
        }
        string get_name(){
            return name;
        };

        int get_studenID (){
            return studentID;
        };

        float get_grade(){
            return grade;
        };
        
        friend class ManagementStudent;
};

class ManagementStudent : public Student {
    private:
        vector <Student> students;
    public:
    ManagementStudent() : Student("Manager", 0, 0.0) {
        // Khởi tạo với giá trị mặc định cho lớp cha
        // vector students tự động rỗng, không cần làm gì thêm
    }

        void addStudent(string name, int studentID, float grade){

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].get_studenID() == studentID)
                {
                    cout << "your studentID did exit, please another studentID\n";
                    return;
                }
            }

            students.emplace_back(name, studentID, grade);
            cout << "Add student successed \n";
            cout << "name: " << name << endl;
            cout << "studentID: " << studentID << endl;
            cout << "grade: " << grade << endl;
        };

        void findStudent(int studentID){
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].get_studenID() == studentID) 
                {
                    cout << "finded a student: ";
                    cout << "name: " << students[i].get_name();
                    cout << "| studentID: " << students[i].get_studenID();
                    cout << "| grade: " << students[i].get_grade();
                }
                else {
                    cout << "wrong studentID"<<endl;
                }
                
            }
            
        };

        void fullStudent(){
            for (int i = 0; i < students.size(); i++)
            {
                cout << " ID: "<< students[i].get_studenID();
                cout << "  name: "<< students[i].get_name();
                cout << "  grade: "<< students[i].get_grade() << endl; 
            }
        };

        void avgGrade(){
            float sum = 0;
            for (int i = 0; i < students.size(); i++)
            {
                sum += students[i].get_grade();
            }
            float avgGrade = sum / students.size();
            cout << "Average all students is: "<< avgGrade<< endl;
        }
};

int main(){
    // create a class have a vector
    ManagementStudent manager;
    manager.addStudent("anphan", 1234, 8.9);
    manager.addStudent("tantran", 1235, 8.8);
    manager.addStudent("phongdang", 1236, 9.5);
    
    manager.fullStudent();
    manager.avgGrade();
    manager.findStudent(1236);
    
    return 0;
}