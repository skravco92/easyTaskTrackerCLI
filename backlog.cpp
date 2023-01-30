#include <iostream>
#include <string>
#include <list>  // include the list library for storing tasks
#include <ctime> // include the time library for generating random IDs

using namespace std;

// Define the Item class to store task information
class Item
{
private:
    int id;                 // unique ID of the task
    string description;     // description of the task
    bool completed;         // completion status of the task

public:
    // Default constructor
    Item() : id(0), description(""), completed(false) {}

    // Destructor
    ~Item() = default;

    // Function to create a new task
    bool create(string new_description)
    {
        id = rand() % 25 + 1; // generate a random ID between 1 and 25
        description = new_description;
        return true;
    }

    // Getter functions for task information
    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }

    // Setter function for completion status
    void setCompleted(bool val) { completed = val; }
};

int main()
{
    char opt;               // variable to store user's choice
    int itemId;             // variable to store the ID of a task
    string itemDescription; // variable to store the description of a task
    list<Item> backlog;     // list to store tasks as objects of the Item class
    list<Item>::iterator iterator; // iterator for the list of tasks

    srand(time(NULL));      // seed the random number generator

    backlog.clear();        // clear the list of tasks

    // Loop to provide the menu and perform actions
    while (1)
    {
        system("cls");  // clear the screen

        // Display the header
        cout << "**|**  takeItEasy!  **|**" << endl;
        cout << "          **|**          " << endl;

        // Display the list of tasks
        for (iterator = backlog.begin(); iterator != backlog.end(); iterator++)
        {
            string completed = iterator->isCompleted() ? "Done" : "inProgress";

            cout << iterator->getId() << " | " << iterator->getDescription() << " | " << completed << endl;
        }

        // Display a message if there are no tasks yet
        if (backlog.empty())
        {
            cout << "No items yet... Enter your first item." << endl;
        }

        // Display the menu
        cout << endl;
        cout << "[c] to create a new item in a list." << endl;
        cout << "[d] to mark item as 'Done'." << endl;
        cout << "[q] to quit the program." << endl;

        // Get user's choice
        cout << "Enter the key that corresponds to the desired action: ";
        cin >> opt;

        // Quit the program
        if (opt == 'q')
        {
            cout << "The program has been terminated" << endl;
            break;
        }

        // Create a new task
        else if (opt == 'c')
       {
            cout << "Add a new description: " << endl;
            cin.clear();
            cin.ignore();
            getline(cin, itemDescription);

            Item newTask;
            newTask.create(itemDescription);
            backlog.push_back(newTask);
        }
        // Update task status
        else if (opt == 'd')
        {
            cout << "Enter the id of the task you want to mark as complete: " << endl;
            cin >> itemId;

            for (iterator = backlog.begin(); iterator != backlog.end(); iterator++)
            {
                if (itemId == iterator->getId())
                {
                    iterator->setCompleted(true);
                    break;
                }
            }
        }
    }
    return 0;
}