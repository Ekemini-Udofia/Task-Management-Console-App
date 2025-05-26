#include <iostream>
#include <string>
#include "Task.h"

class Task
{
    public:
        int task_id = 0;
        std::string task_name = "Null";
        std::string task_content = "Null";
        std::string due_date = "Null";
        // Task()
        // {
            // std::cout << "New task created: " << task_name << "\n";
        // }
            // this-> task_name = name;
            // this->task_content = content;
            // this->due_date = date;
        Task(std::string task_name, std::string task_content, std::string due_date)
            : task_name(task_name), task_content(task_content), due_date(due_date)
        {
        }
        ~Task()
        {
            std::cout << "Task deleted: " << task_name << "\n";
        }

    private:
};
