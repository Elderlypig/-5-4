#include <iostream>
#include <vector>
#include <algorithm>

class Employee {
public:
    std::string name;
    int start_year;

    Employee(std::string name, int start_year) {
        this->name = name;
        this->start_year = start_year;
    }
};

int linear_search(std::vector<Employee>& employees, int year) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].start_year == year) {
            return i;
        }
    }
    return -1;
}


int binary_search(std::vector<Employee>& employees, int year) {
    int left = 0;
    int right = employees.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (employees[mid].start_year == year) {
            return mid;
        }
        else if (employees[mid].start_year < year) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Employee> employees = {
        Employee("Мохов Глеб Генадьевич", 1970),
        Employee("Мороз Ксения Ивановна", 1978),
        Employee("Скала Джонсон", 1975),
        Employee("Егор Ярошенко", 1985),
        Employee("Габи", 1990)
    };

    std::sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.start_year < b.start_year;
        });

    int index = binary_search(employees, 1975);
    if (index != -1) {
        std::cout << "Метод интерполяционный:"<<std::endl;
        std::cout << "Работники работающие с 1975: " << employees[index].name << std::endl;
    }
    else {
        std::cout << "Нет работников работающих с 1975." << std::endl;
    }

    index = linear_search(employees, 1975);
    if (index != -1) {
        std::cout << "Метод полного перебора:" << std::endl;
        std::cout << "Работники работающие с 1975: " << employees[index].name << std::endl;
    }
    else {
        std::cout << "Нет работников работающих с 1975." << std::endl;
    }

    return 0;
}
