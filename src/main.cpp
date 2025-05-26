#include <iostream>
#include <vector>
#include <string>
#include "lib/Task.h"
#include <fstream>
//#include <filesystem>



// This is a simple personal task management application in C++


// Create the general task vectors for storing the tasks
std::vector<Task> Task_List;

std::string global_username = ""; // Default username



static void greet_user()
{
    if (global_username == "")
    {
        std::cout << "> Welcome to your Personal Task Management app!\n> Let's get to know you.\n> Name: ";
        std::getline(std::cin, global_username);
        std::cout << "> Nice to meet you, " << global_username << "!\n";
        std::ofstream new_file("cred.txt");
        if (new_file.is_open()) {
            new_file << global_username << std::endl;
            new_file.close();
            std::cout << "> Username Saved" << std::endl;
        }
    }
    else
    {
        std::cout << "> Welcome " << global_username << std::endl;
    }
}


static void Input_Task()
{
    std::string new_task;
    std::string new_date;
    std::string new_content;
    std::cin.ignore();
    std::cout << "> Task Name : ";
    std::getline(std::cin, new_task);
    if (new_task.empty()) {
        std::cout << "> Task name cannot be empty. Please try again.\n";
        Input_Task();
        return;
    }
    std::cout << "\n> Details : ";
    std::getline(std::cin, new_content);
    std::cout << "\n> Due Date(yy/mm/dd) : ";
    std::getline(std::cin, new_date);
    Task_List.push_back(Task(new_task, new_content, new_date));
    std::cout <<"> Task Created: "<< std::endl;
}

static void view_all_tasks()
{
    
    if (Task_List.size())
    {
        std::cout << "All Tasks" << std::endl;
        for (int i = 0; i < Task_List.size(); i++)
        {
            std::cout << i + 1 << ". " << Task_List[i].task_name << std::endl;
        }
        // do a for loop to iterate through the Task_List vector and print out their names, maybe with the due dates
    }
    else
    {
        std::cout << "> No Tasks!" << std::endl;
    }
}
static void remove_tasks(int i)
{
    Task_List.erase(Task_List.begin() + i);
}
static void display_options()
{
    int option;
    std::cout << "> \n> Select an action from the list below: \n> 1. Create a new task\n> 2. View all tasks\n> 3. Remove a task\n> 4. Change Username\n> 5. Exit\n> ";
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
        int i;
        std::cout << "> Input the number of the task to be deleted(Press ENTER and view all tasks to see its number : ";
        std::cin >> i;
        remove_tasks(i - 1);
        display_options();
    }

    else if (option == 4)
    {
        std::cout << "Input a new username: ";
        std::cin.ignore();
        std::getline(std::cin, global_username);
        std::ofstream inFile("cred.txt", std::ios::trunc);
        if (inFile.is_open()) {
            inFile << global_username << std::endl;
            inFile.close();
            std::cout << "> Username Saved" << std::endl;
        }
        display_options();
    }
        
    else if (option == 5)
    {
        exit(0);
    }
        
    else if (option == 6)
    {
        std::cout << "Invalid Option\n";
        display_options();
    }        
}



int main(int argc, char* argv[])
{

    // Initializations
    // Create an output file for writing to 
    // check if theres a file like that named already
    
    //write user name to it
    std::ifstream inFile("cred.txt");
    if (!inFile.is_open())
    {
        greet_user();
    }
    else
    {
        std::getline(inFile, global_username);
        inFile.close();
        greet_user();
    }
    display_options();
    return 0;
}