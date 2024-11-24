#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// 学生结构体
struct Student {
        string name;
        int id;
        float grade;
};

// 添加学生信息
void addStudent(vector<Student>& students) {
        Student s;
        cout << "请输入学生姓名：";
        cin >> s.name;
        cout << "请输入学生学号：";
        cin >> s.id;
        // 检查学号唯一性
        for (const auto& student : students) {
                if (student.id == s.id) {
                        cout << "学号已存在，请重新输入。\n";
                        return;
                }
        }
        cout << "请输入学生成绩：";
        cin >> s.grade;
        if (s.grade < 0 || s.grade > 100) {
                cout << "成绩无效，请输入0-100之间的值。\n";
                return;
        }
        students.push_back(s);
        cout << "学生信息添加成功！\n";
}

// 查询学生信息
void queryStudent(const vector<Student>& students) {
        int id;
        cout << "请输入要查询的学号：";
        cin >> id;
        for (const auto& s : students) {
                if (s.id == id) {
                        cout << "学生姓名：" << s.name << "\n学号：" << s.id << "\n成绩：" << s.grade << endl;
                        return;
                }
        }
        cout << "未找到该学号的学生信息。\n";
}

// 修改学生成绩
void modifyStudent(vector<Student>& students) {
        int id;
        cout << "请输入要修改成绩的学生学号：";
        cin >> id;
        for (auto& s : students) {
                if (s.id == id) {
                        cout << "当前学生：" << s.name << "，当前成绩：" << s.grade << endl;
                        cout << "请输入新的成绩：";
                        cin >> s.grade;
                        if (s.grade < 0 || s.grade > 100) {
                                cout << "成绩无效，修改失败。\n";
                                return;
                        }
                        cout << "成绩修改成功！\n";
                        return;
                }
        }
        cout << "未找到该学号的学生信息。\n";
}

// 删除学生信息
void deleteStudent(vector<Student>& students) {
        int id;
        cout << "请输入要删除的学生学号：";
        cin >> id;
        for (auto it = students.begin(); it != students.end(); ++it) {
                if (it->id == id) {
                        students.erase(it);
                        cout << "学生信息删除成功！\n";
                        return;
                }
        }
        cout << "未找到该学号的学生信息。\n";
}

// 按成绩排序并输出所有学生信息
void sortAndDisplayStudents(vector<Student>& students) {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.grade > b.grade;
                });
        cout << "按成绩从高到低排序的学生信息：\n";
        for (const auto& s : students) {
                cout << "姓名：" << s.name << "，学号：" << s.id << "，成绩：" << s.grade << endl;
        }
}

// 统计成绩
void statistics(const vector<Student>& students) {
        if (students.empty()) {
                cout << "没有学生信息，无法统计。\n";
                return;
        }
        float sum = 0, maxGrade = -1, minGrade = 101;
        for (const auto& s : students) {
                sum += s.grade;
                if (s.grade > maxGrade) maxGrade = s.grade;
                if (s.grade < minGrade) minGrade = s.grade;
        }
        cout << fixed << setprecision(2);
        cout << "平均成绩：" << sum / students.size() << "\n最高成绩：" << maxGrade << "\n最低成绩：" << minGrade << endl;
}

int main() {
        vector<Student> students;
        int choice;
        do {
                cout << "\n欢迎进入学生成绩管理系统：\n"
                        << "1. 添加学生信息\n"
                        << "2. 查询学生信息\n"
                        << "3. 修改学生成绩\n"
                        << "4. 删除学生信息\n"
                        << "5. 按成绩排序\n"
                        << "6. 成绩统计\n"
                        << "7. 退出程序\n"
                        << "请输入选项：";
                cin >> choice;
                switch (choice) {
                case 1:
                        addStudent(students);
                        break;
                case 2:
                        queryStudent(students);
                        break;
                case 3:
                        modifyStudent(students);
                        break;
                case 4:
                        deleteStudent(students);
                        break;
                case 5:
                        sortAndDisplayStudents(students);
                        break;
                case 6:
                        statistics(students);
                        break;
                case 7:
                        cout << "退出程序。\n";
                        break;
                default:
                        cout << "无效选项，请重新输入。\n";
                        break;
                }
        } while (choice != 7);
        return 0;
}
