#pragma once
#include <string>

class Task
{
private:
public:
    Task(std::string task_name, std::string task_content, std::string due_date);
    // Task();
    ~Task();
    Task() = default;
    int task_id = 0;
    std::string task_name;
    std::string task_content;
    std::string due_date ;
};

Task::Task(std::string task_name, std::string task_content, std::string due_date)
    : task_name(task_name), task_content(task_content), due_date(due_date)
{
}

Task::~Task()
{
}

