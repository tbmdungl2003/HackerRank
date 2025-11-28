#include <iostream>
#include <string>
#include <vector>
#include <numeric> // For std::accumulate

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    // Pure virtual functions, must be overridden by derived classes
    virtual void getdata() = 0;
    virtual void putdata() = 0;
    // Virtual destructor, necessary for polymorphism with pointers
    virtual ~Person() {}
};

// Initialize static variable outside the class
// int Person::id_counter = 0; // We will move this

class Professor : public Person {
private:
    int publications;
    int cur_id;
    // Static ID counter specific to Professor
    static int id_counter;

public:
    Professor() {
        // Increment counter and assign ID to this object
        Professor::id_counter++;
        cur_id = id_counter;
    }

    void getdata() override {
        cin >> name >> age >> publications;
    }

    void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

int Professor::id_counter = 0; // Initialize Professor's counter

class Student : public Person {
private:
    int marks[6];
    int cur_id;
    // Static ID counter specific to Student
    static int id_counter;

public:
    Student() {
        // Increment counter and assign ID to this object
        Student::id_counter++;
        cur_id = id_counter;
    }

    void getdata() override {
        cin >> name >> age;
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }

    void putdata() override {
        // Calculate sum of marks
        int sum_of_marks = 0;
        for (int i = 0; i < 6; i++) {
            sum_of_marks += marks[i];
        }
        // Alternative: int sum_of_marks = std::accumulate(marks, marks + 6, 0);
        
        cout << name << " " << age << " " << sum_of_marks << " " << cur_id << endl;
    }
};

int Student::id_counter = 0; // Initialize Student's counter

int main() {
    int n;
    cin >> n; // Read the number of objects

    Person *per[n]; // Array of base class pointers

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val; // Read object type (1 for Professor, 2 for Student)
        if (val == 1) {
            // Create a Professor object and assign to the Person pointer
            per[i] = new Professor;
        } else { // Create a Student object and assign to the Person pointer
            per[i] = new Student;
        }
        per[i]->getdata(); // Call the corresponding getdata() function
    }

    for (int i = 0; i < n; i++) {
        per[i]->putdata(); // Call the corresponding putdata() function
    }
    
    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        delete per[i];
    }

    return 0;
}

            