#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_FLIGHTS 100

typedef struct
{
    char username[20];
    char password[20];
    int flightIndex;
    int isActive;
} Account;

typedef struct
{
    char location[50];
    char destination[50];
    char departureTime[20];
    int numPassengers;
    int availableSeats;
    int flightIndex;
    int price;
} Flight;

typedef struct
{
    char fullName[50];
    int age;
    char gender[10];
    char address[100];
    char occupation[50];
    char nationality[50];
    int height;
    int weight;
    char civilStatus[20];
    int flightIndex;
} User;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

Flight flights[MAX_FLIGHTS];
int flightCount = 0;

int main();
void preMadeUser();

void addNewAccount()
{
    if (accountCount >= MAX_ACCOUNTS)
    {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);
    newAccount.isActive = 1;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully.\n");
}

void viewAllAccounts()
{
    printf("All Accounts:\n");
    for (int i = 0; i < accountCount; i++)
    {
        printf("Username: %s\n", accounts[i].username);
        printf("Password: %s\n", accounts[i].password);
        printf("Status: %s\n", accounts[i].isActive ? "Active" : "Inactive");
        printf("-------------------------\n");
    }
}

void viewSpecificAccount()
{
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            printf("Username: %s\n", accounts[i].username);
            printf("Password: %s\n", accounts[i].password);
            printf("Status: %s\n", accounts[i].isActive ? "Active" : "Inactive");
            return;
        }
    }

    printf("Account not found.\n");
}

void viewAccountByStatus()
{
    int status;
    printf("Enter account status (1 for active, 0 for inactive): ");
    scanf("%d", &status);

    printf("Accounts with status %s:\n", status ? "Active" : "Inactive");
    for (int i = 0; i < accountCount; i++)
    {
        if (accounts[i].isActive == status)
        {
            printf("Username: %s\n", accounts[i].username);
            printf("Password: %s\n", accounts[i].password);
            printf("-------------------------\n");
        }
    }
}

void updateAccountStatus()
{
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            int status;
            printf("Enter new status (1 for active, 0 for inactive): ");
            scanf("%d", &status);

            accounts[i].isActive = status;
            printf("Account status updated successfully.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void viewFlightDetailsByAccount()
{
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    char filename[50];
    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            sprintf(filename, "flight_details_%d.txt", accounts[i].flightIndex);

            // Read flight details from file
            FILE *file = fopen(filename, "r");
            if (file != NULL)
            {
                char line[100];
                printf("Flight Details:\n");
                while (fgets(line, sizeof(line), file) != NULL)
                {
                    printf("%s", line);
                }
                fclose(file);
            }
            else
            {
                printf("No flight details found.\n");
            }
        }
    }
}

void bookFlight(User *user)
{
    // printf("%d", user->flightIndex);
    Flight flights[MAX_FLIGHTS];
    Account accounts[MAX_ACCOUNTS];
    int flightCount = 0;

    // Flight 1
    strcpy(flights[flightCount].location, "Mactan International Airport");
    strcpy(flights[flightCount].destination, "DUBAI");
    strcpy(flights[flightCount].departureTime, "08:00 AM");
    flights[flightCount].availableSeats = 5;
    flights[flightCount].price = 10000;
    flightCount++;

    // Flight 2
    strcpy(flights[flightCount].location, "Mactan International Airport");
    strcpy(flights[flightCount].destination, "DOHA");
    strcpy(flights[flightCount].departureTime, "10:00 AM");
    flights[flightCount].availableSeats = 5;
    flights[flightCount].price = 8000;
    flightCount++;

    // Flight 3
    strcpy(flights[flightCount].location, "Mactan International Airport");
    strcpy(flights[flightCount].destination, "SINGAPORE");
    strcpy(flights[flightCount].departureTime, "12:00 PM");
    flights[flightCount].availableSeats = 5;
    flights[flightCount].price = 12000;
    flightCount++;

    // Flight 4
    strcpy(flights[flightCount].location, "Mactan International Airport");
    strcpy(flights[flightCount].destination, "SEOUL");
    strcpy(flights[flightCount].departureTime, "02:00 PM");
    flights[flightCount].availableSeats = 5;
    flights[flightCount].price = 11000;
    flightCount++;

    // Flight 5
    strcpy(flights[flightCount].location, "Mactan International Airport");
    strcpy(flights[flightCount].destination, "BUSAN");
    strcpy(flights[flightCount].departureTime, "4:00 PM");
    flights[flightCount].availableSeats = 5;
    flights[flightCount].price = 9000;
    flightCount++;

    // Flight 6
    strcpy(flights[flightCount].location, "Mactan International Airport");
    strcpy(flights[flightCount].destination, "TOKYO");
    strcpy(flights[flightCount].departureTime, "6:00 PM");
    flights[flightCount].availableSeats = 5;
    flights[flightCount].price = 13000;
    flightCount++;

    // Printing flight details
    printf("Available Flights:\n");
    for (int i = 0; i < flightCount; i++)
    {
        printf("Flight %d\n", i + 1);
        printf("Location: %s\n", flights[i].location);
        printf("Destination: %s\n", flights[i].destination);
        printf("Departure Time: %s\n", flights[i].departureTime);
        printf("Available Seats: %d\n", flights[i].numPassengers);
        printf("Price: %d pesos\n", flights[i].price);
        printf("-------------------------\n");
    }

    // Prompt user for booking
    int choice;
    printf("Enter the flight number you want to book: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= flightCount)
    {
        // Valid flight choice
        Flight selectedFlight = flights[choice - 1];
        printf("You have selected the following flight:\n");
        printf("Location: %s\n", selectedFlight.location);
        printf("Destination: %s\n", selectedFlight.destination);
        printf("Departure Time: %s\n", selectedFlight.departureTime);
        printf("Available Seats: %d\n", selectedFlight.availableSeats);
        printf("Price: %d pesos\n", selectedFlight.price);

        if (selectedFlight.availableSeats == 0)
        {
            printf("Sorry, the flight is full. No more seats available.\n");
            return;
        }
        // Proceed to flight details process
        printf("\n=== Flight Details ===\n");

        // Capture flight date
        char date[20];
        printf("Enter date of flight (MM/DD/YYYY): ");
        scanf("%s", date);

        // Capture bag check-in status
        char bagCheckIn[10];
        printf("Do you require bag check-in? (yes/no): ");
        scanf("%s", bagCheckIn);

        // Print user account information
        printf("\n=== User Account Information ===\n");
        printf("Full Name: %s\n", user->fullName);
        printf("Age: %d\n", user->age);
        printf("Gender: %s\n", user->gender);
        printf("Address: %s\n", user->address);
        printf("Occupation: %s\n", user->occupation);
        printf("Nationality: %s\n", user->nationality);
        printf("Height: %d\n", user->height);
        printf("Weight: %d\n", user->weight);
        printf("Civil Status: %s\n", user->civilStatus);

        // Assign priority number based on available flight seats
        int priorityNumber = 6 - selectedFlight.availableSeats;

        // Capture number of passengers
        int numPassengers;
        printf("Enter number of passengers: ");
        scanf("%d", &flights->numPassengers);

        char filename[50];

        user->flightIndex = flights->flightIndex;
        accounts->flightIndex = user->flightIndex;

        sprintf(filename, "flight_details_%d.txt", user->flightIndex);
        flights->flightIndex++;
        // Open the file for writing
        FILE *file = fopen(filename, "w");

        if (file != NULL)
        {
            fprintf(file, "=== Flight Details ===\n");
            fprintf(file, "Location: %s\n", selectedFlight.location);
            fprintf(file, "Destination: %s\n", selectedFlight.destination);
            fprintf(file, "Departure Time: %s\n", selectedFlight.departureTime);
            fprintf(file, "Date: %s\n", date);
            fprintf(file, "Bag Check-in: %s\n", bagCheckIn);
            fprintf(file, "Account Details:\n");
            fprintf(file, "Full Name: %s\n", user->fullName);
            fprintf(file, "Age: %d\n", user->age);
            fprintf(file, "Gender: %s\n", user->gender);
            fprintf(file, "Address: %s\n", user->address);
            fprintf(file, "Occupation: %s\n", user->occupation);
            fprintf(file, "Nationality: %s\n", user->nationality);
            fprintf(file, "Height(m): %d\n", user->height);
            fprintf(file, "Weight(kg): %d\n", user->weight);
            fprintf(file, "Civil Status: %s\n", user->civilStatus);
            fprintf(file, "Priority Number: %d\n", priorityNumber);
            fprintf(file, "Number of Passengers: %d\n", numPassengers);
            fprintf(file, "Price: %d pesos\n", selectedFlight.price);
            fclose(file);
            printf("\nFlight details saved to flight_details.txt\n");

            // Decrease available seats after successful booking
            selectedFlight.availableSeats--;
        }
        else
        {
            printf("Failed to create flight details file.\n");
        }
    }
    else
    {
        printf("Invalid flight choice. Please try again.\n");
    }
}

void viewFlightDetails()
{
    User *currentUser;

    char filename[50];

    sprintf(filename, "flight_details_%d.txt", currentUser->flightIndex);

    // Read flight details from file
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        char line[100];
        printf("Flight Details:\n");
        while (fgets(line, sizeof(line), file) != NULL)
        {
            printf("%s", line);
        }
        fclose(file);
    }
    else
    {
        printf("No flight details found.\n");
    }
}
void cancelFlight()
{
    int flightCount;
    int index = 1;
    if (index >= 0 && index < flightCount)
    {
        Flight canceledFlight = flights[index];
        printf("Canceled Flight Details:\n");
        printf("Location: %s\n", canceledFlight.location);
        printf("Destination: %s\n", canceledFlight.destination);
        printf("Departure Time: %s\n", canceledFlight.departureTime);
        printf("Available Seats: %d\n", canceledFlight.availableSeats);
        printf("Price: %d pesos\n", canceledFlight.price);

        // Increase available seats after canceling flight
        canceledFlight.availableSeats++;
        flights[index] = canceledFlight;

        printf("Flight canceled successfully.\n");
    }
    else
    {
        printf("Invalid flight index.\n");
    }
}

void updateInfo(User *user)
{
    printf("Update Info\n");
    printf("Enter Full Name: ");
    scanf("%s", user->fullName);

    printf("Enter Age: ");
    scanf("%d", &(user->age));

    printf("Enter Gender: ");
    scanf("%s", user->gender);

    printf("Enter Address: ");
    scanf(" %[^\n]", user->address); // Read the entire line, including spaces

    printf("Enter Occupation: ");
    scanf(" %[^\n]", user->occupation);

    printf("Enter Nationality: ");
    scanf(" %[^\n]", user->nationality);

    printf("Enter Height(m): ");
    scanf("%d", &(user->height));

    printf("Enter Weight(kg): ");
    scanf("%d", &(user->weight));

    printf("Enter Civil Status: ");
    scanf("%s", user->civilStatus);

    printf("Info updated successfully.\n");
}
void displayInfo(const User *user)
{
    printf("User Information\n");
    printf("Full Name: %s\n", user->fullName);
    printf("Age: %d\n", user->age);
    printf("Gender: %s\n", user->gender);
    printf("Address: %s\n", user->address);
    printf("Occupation: %s\n", user->occupation);
    printf("Nationality: %s\n", user->nationality);
    printf("Height(m): %d\n", user->height);
    printf("Weight(kg): %d\n", user->weight);
    printf("Civil Status: %s\n", user->civilStatus);
}

void displayMainMenu(User *user)
{
    int choice;
    // printf("%d", user->flightIndex);
    while (1)
    {
        printf("\n--------- Main Menu ---------\n");
        printf("[1] Update Info\n");
        printf("[2] Display Info\n");
        printf("[3] Book A Flight\n");
        printf("[4] View Flight Details\n");
        printf("[5] Cancel Flights\n");
        printf("[6] Go back to Main Menu\n");
        printf("[7] Exit Application\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("-----------------------------\n");
        switch (choice)
        {
        case 1:
            updateInfo(user);
            break;
        case 2:
            displayInfo(user);
            break;
        case 3:
            bookFlight(user);
            break;
        case 4:
            viewFlightDetails();
            break;
        case 5:
            cancelFlight();
            break;
        case 6:
            return;
        case 7:
            exit(0);
        default:
            printf("Invalid choice.\n");
            main();
        }
    }
}

void displayEmployeeMenu()
{
    int choice;

    while (1)
    {
        printf("\n-------- Employee Menu --------\n");
        printf("[1] Add new account\n");
        printf("[2] View all accounts\n");
        printf("[3] View specific account\n");
        printf("[4] View account by status\n");
        printf("[5] Update account status\n");
        printf("[6] View flight details by account\n");
        printf("[7] Go back to Main Menu\n");
        printf("[8] Close Application\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("-----------------------------\n");
        switch (choice)
        {
        case 1:
            addNewAccount();
            break;
        case 2:
            viewAllAccounts();
            break;
        case 3:
            viewSpecificAccount();
            break;
        case 4:
            viewAccountByStatus();
            break;
        case 5:
            updateAccountStatus();
            break;
        case 6:
            viewFlightDetailsByAccount();
            break;
        case 7:
            return;
        case 8:
            exit(0);
        default:
            printf("Invalid choice.\n");
            main();
        }
    }
}

void loginUser()
{
    if (accountCount == 0)
    {
        preMadeUser();
    }

    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0)
        {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Login failed. Invalid username or password.\n");
    main();
}

void preMadeUser()
{
    Account newAccount;
    User *currentUser;

    strcpy(newAccount.username, "user");
    strcpy(newAccount.password, "user");
    newAccount.isActive = 1;

    // currentUser->flightIndex = 0;
    // printf("%d", currentUser->flightIndex);
    accounts[accountCount] = newAccount;
    accountCount++;
}

void registerUser()
{
    if (accountCount >= MAX_ACCOUNTS)
    {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account newAccount;
    User *currentUser;

    printf("Enter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);
    newAccount.isActive = 1;

    // currentUser->flightIndex = 0;
    // printf("%d", currentUser->flightIndex);
    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully.\n");
}

int main()
{
    // User currentUser = {
    //     .flightIndex = 0,
    // };
    while (1)
    {
        int loginChoice, choice;
        printf("--------- Login Menu ---------\n");
        printf("[1] Employee Login\n");
        printf("[2] User Login\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &loginChoice);
        printf("-----------------------------\n");
        if (loginChoice == 1)
        {
            // Employee login
            char employeeUsername[20] = "admin";
            char employeePassword[20] = "admin";
            char username[20], password[20];

            printf("------ Employee Login ------\n");
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            if (strcmp(username, employeeUsername) == 0 && strcmp(password, employeePassword) == 0)
            {
                printf("Login successful.\n");
                displayEmployeeMenu();
            }
            else
            {
                printf("Login failed. Invalid username or password.\n");
                main();
            }
        }
        else if (loginChoice == 2)
        {
            // User login or registration
            User user;

            printf("--------- User Menu ---------\n");
            printf("[1] Login\n");
            printf("[2] Register\n");
            printf("-----------------------------\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            printf("-----------------------------\n");
            switch (choice)
            {
            case 1:
                loginUser();
                break;
            case 2:
                registerUser();
                break;
            default:
                printf("Invalid choice.\n");
                main();
            }

            displayMainMenu(&user);
        }
        else
        {
            printf("Invalid choice.\n");
            main();
        }
    }
    return 0;
}