
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
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

    void updateInfo(string newName, int newAge, double newScore) {
        name = newName;
        age = newAge;
        score = newScore;
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

    if (isIdExists(id)) {
        cout << "该学号已存在，添加失败！" << endl;
        return;
    }

    cout << "请输入姓名: ";
    cin >> name;

    cout << "请输入年龄: ";
    cin >> age;
    if (age <= 0 || age > 120) {
        cout << "年龄输入不合法，添加失败！" << endl;
        return;
    }

    cout << "请输入成绩: ";
    cin >> score;
    if (score < 0 || score > 100) {
        cout << "成绩输入不合法，添加失败！" << endl;
        return;
    }

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
void searchStudent() {
    int id;
    cout << "请输入要查询的学生学号: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            cout << "查询成功：" << endl;
            students[i].showInfo();
            return;
        }
    }

    cout << "未找到该学生。" << endl;
}
void deleteStudent() {
        int id;
        cout << "请输入要删除的学生学号: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "删除成功！" << endl;
                return;
            }
        }

        cout << "未找到该学生，删除失败。" << endl;
    }
void updateStudent() {
    int id;
    cout << "请输入要修改的学生学号: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            string newName;
            int newAge;
            double newScore;

            cout << "请输入新的姓名: ";
            cin >> newName;

            cout << "请输入新的年龄: ";
            cin >> newAge;
            if (newAge <= 0 || newAge > 120) {
                cout << "年龄输入不合法，修改失败！" << endl;
                return;
            }

            cout << "请输入新的成绩: ";
            cin >> newScore;
            if (newScore < 0 || newScore > 100) {
                cout << "成绩输入不合法，修改失败！" << endl;
                return;
            }

            students[i].updateInfo(newName, newAge, newScore);

            cout << "修改成功！" << endl;
            return;
        }
    }

    cout << "未找到该学生，修改失败。" << endl;
}
void sortByScore() {
    if (students.empty()) {
        cout << "暂无学生信息，无法排序。" << endl;
        return;
    }

    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.getScore() > b.getScore();
    });

    cout << "已按成绩从高到低排序。" << endl;
    showAllStudents();
}
void saveToFile() {
    ofstream ofs("students.txt");

    if (!ofs.is_open()) {
        cout << "文件打开失败，保存失败。" << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        ofs << students[i].getId() << " "
            << students[i].getName() << " "
            << students[i].getAge() << " "
            << students[i].getScore() << endl;
    }

    ofs.close();
    cout << "学生信息已保存到文件。" << endl;
}
void loadFromFile() {
    ifstream ifs("students.txt");

    if (!ifs.is_open()) {
        cout << "暂无历史数据文件。" << endl;
        return;
    }

    students.clear();

    int id, age;
    string name;
    double score;

    while (ifs >> id >> name >> age >> score) {
        Student stu(id, name, age, score);
        students.push_back(stu);
    }

    ifs.close();
    cout << "学生信息读取完成。" << endl;
}
bool isIdExists(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            return true;
        }
    }
    return false;
}
};

void showMenu() {
    cout << "==========================" << endl;
    cout << "   学生管理系统 " << endl;
    cout << "==========================" << endl;
    cout << "1. 添加学生信息" << endl;
    cout << "2. 查看所有学生" << endl;
    cout << "3. 查询学生信息" << endl;
    cout << "4. 删除学生信息" << endl;
    cout << "5. 修改学生信息" << endl;
    cout << "6. 按成绩排序" << endl;
    cout << "7. 保存学生信息" << endl;
    cout << "8. 读取学生信息" << endl;
    cout << "0. 退出系统" << endl;
    cout << "请输入你的选择: ";
}

int main() {
    StudentManager manager;
    manager.loadFromFile();

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
    case 3:
        manager.searchStudent();
        break;
    case 4:
        manager.deleteStudent();
        break;
    case 5:
        manager.updateStudent();
        break;
    case 6:
        manager.sortByScore();
        break;
    case 7:
        manager.saveToFile();
        break;
case 8:
    manager.loadFromFile();
    break;
    case 0:
        manager.saveToFile();
        cout << "已保存数据并退出系统。" << endl;
        return 0;
    default:
        cout << "输入错误，请重新输入。" << endl;
}
    }

    return 0;
}
