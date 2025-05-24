#include <iostream>
#include <vector>
#include <string>
#include "lib/Task.h"
// This is a simple personal task management application in C++


// Create the general task vectors for storing the tasks
std::vector<Task> Task_List;

std::string global_username = "User"; // Default username





void greet_user()
{
    int i = 0;
    if (i == 0)
    {
        std::cout << "Welcome to your Personal Task Management app!\nLet's get to know you.\nName: ";
        std::cin >> global_username;
        std::cout << "Nice to meet you, " << global_username << "!\n";
    }
    else
    {
        std::cout << "Welcome " << global_username << std::endl;
    }
}


void Input_Task()
{
    std::string new_task;
    std::cout << "#New task";
    std::cout << "Task Name : ";
    std::cin >> new_task;
    Task_List.push_back(Task(new_task, "No content", "No due date"));
    std::cout <<"> Task Created: "<< std::endl;
}

void view_all_tasks()
{
    std::cout << "All Tasks" << std::endl;
    for(int i = 0; i < Task_List.size(); i++)
    {
        std::cout << i + 1 << ". " << Task_List[i].task_name << std::endl;
    }
    // do a for loop to iterate through the Task_List vector and print out their names, maybe with the due dates
}

void display_options()
{
    int option;
    std::cout << "\nSelect an action from the list below: \n1. Create a new task\n2. View all tasks\n3. View all Categories\n4. Remove a task\n5. Change username\n6. Exit\n";
    std::cin >> option;
    if (option == 1)
    {
        Input_Task();
        display_options();
        
    }
    else if (option == 2)
    {
        view_all_tasks();
        display_options();
    }
    else if (option == 3)
    {
        //display_categories();
        std::cout << "Display Categories\n";
        display_options();
    }
    else if (option == 4)
    {
        //remove task
        display_options();
    }
    else if (option == 5)
    {
        std::cout << "Input a new username: ";
        std::cin >> global_username;
        display_options();
    }
    else if (option == 6)
    {
        exit;
    }
    else
    {
        std::cout << "Invalid Option\n";
        display_options();
    }
}



int main(int argc, char* argv[])
{
    greet_user();
    display_options();
    //Task global_task_name;
    //std::cout << global_task_name << "\n";
    return 0;
}