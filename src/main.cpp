
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    double score;

public:
    Student(int id, string name, int age, double score) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->score = score;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    double getScore() {
        return score;
    }

    void showInfo() {
        cout << "学号: " << id
             << "  姓名: " << name
             << "  年龄: " << age
             << "  成绩: " << score << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id, age;
        string name;
        double score;

        cout << "请输入学号: ";
        cin >> id;
        cout << "请输入姓名: ";
        cin >> name;
        cout << "请输入年龄: ";
        cin >> age;
        cout << "请输入成绩: ";
        cin >> score;

        Student stu(id, name, age, score);
        students.push_back(stu);

        cout << "添加成功！" << endl;
    }

    void showAllStudents() {
        if (students.empty()) {
            cout << "暂无学生信息。" << endl;
            return;
        }

        for (int i = 0; i < students.size(); i++) {
            students[i].showInfo();
        }
    }
};

void showMenu() {
    cout << "==========================" << endl;
    cout << "   学生管理系统 C++ 版" << endl;
    cout << "==========================" << endl;
    cout << "1. 添加学生信息" << endl;
    cout << "2. 查看所有学生" << endl;
    cout << "0. 退出系统" << endl;
    cout << "请输入你的选择: ";
}

int main() {
    StudentManager manager;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.showAllStudents();
                break;
            case 0:
                cout << "已退出系统。" << endl;
                return 0;
            default:
                cout << "输入错误，请重新输入。" << endl;
        }
    }

    return 0;
}
