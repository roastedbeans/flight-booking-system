#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 5    // Maximum number of accounts
#define MAX_ACCOUNTS 100 // Maximum number of accounts

typedef struct
{
    char location[20];
    char destination[20];
    char departureTime[10];
    char departureDate[12];
    int status;
} FlightDetails;

// Structure to hold account information
typedef struct
{
    char username[20];
    char password[20];
    char fullName[50];
    int age;
    char gender[10];
    char address[100];
    char occupation[50];
    char nationality[50];
    float height;
    float weight;
    char civilStatus[20];
    int flightCount;                    // variable to store the number of flights
    FlightDetails flights[MAX_FLIGHTS]; // array to store flight details

} Account;

// Global variables
Account accounts[MAX_ACCOUNTS]; // Array to hold all accounts

int accountCount = 0; // Current number of accounts
char guestUserName[20];

// Function prototypes
void addAccount();
void viewAllAccounts();
void viewSpecificAccount();
void viewAccountsByStatus();
void updateAccountStatus();
void viewFlightDetails();
void displayMainMenu();
void displayUserMenu();
void userLogin();
void updateUserInformation();
void bookFlight();
void viewAllFlights();
void cancelFlight();

int main()
{
    int option;
    int isEmployee = 0;

    printf("Airline Booking System\n");
    printf("======================\n");
    printf("[1] Employee\n");
    printf("[2] User\n");
    printf("Select user type: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        isEmployee = 1;
        break;
    case 2:
        userLogin();
        break;
    default:
        printf("\nInvalid option. Exiting...\n");
        return 0;
    }

    if (isEmployee)
    {
        int option;
        int isEmployee = 0;
        char username[20];
        char password[20];
        // Airline employee login
        printf("\nAirline Booking System - Employee Login\n");
        printf("======================================\n");
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);

        // Perform basic security check (pre-made user account)
        if (strcmp(username, "employee") == 0 && strcmp(password, "password") == 0)
        {
            isEmployee = 1;
            printf("\nLogin successful!\n");
        }
        else
        {
            printf("\nInvalid username or password. Exiting...\n");
            return 0;
        }

        // Employee main menu
        do
        {
            displayMainMenu();
            printf("Enter your choice: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                addAccount();
                break;
            case 2:
                viewAllAccounts();
                break;
            case 3:
                viewSpecificAccount();
                break;
            case 4:
                viewAccountsByStatus();
                break;
            case 5:
                updateAccountStatus();
                break;
            case 6:
                viewFlightDetails();
                break;
            case 7:
                printf("\nGoing back to main menu...\n");
                break;
            case 8:
                printf("\nClosing application...\n");
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n");
            }
        } while (option != 8);
    }

    return 0;
}

void displayMainMenu()
{
    printf("\nAirline Booking System - Main Menu\n");
    printf("=================================\n");
    printf("[1] Add new account\n");
    printf("[2] View all accounts\n");
    printf("[3] View specific account\n");
    printf("[4] View accounts by status\n");
    printf("[5] Update account status\n");
    printf("[6] View flight details by account\n");
    printf("[7] Go back to main menu\n");
    printf("[8] Close application\n");
}

void displayUserMenu()
{
    printf("\nAirline Booking System - User Menu\n");
    printf("==================================\n");
    printf("[1] Update Info\n");
    printf("[2] Book A Flight\n");
    printf("[3] View Flight Details\n");
    printf("[4] Cancel Flights\n");
    printf("[5] Go back to Main Menu\n");
    printf("[6] Exit Application\n");
}

void addAccount()
{
    if (accountCount >= MAX_ACCOUNTS)
    {
        printf("\nMaximum account limit reached. Cannot add more accounts.\n");
        return;
    }

    Account newAccount;
    printf("\nEnter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);

    // Add more account details capture if needed

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("\nAccount added successfully!\n");
}

void viewAllAccounts()
{
    if (accountCount == 0)
    {
        printf("\nNo accounts found.\n");
        return;
    }

    printf("\nAll Accounts\n");
    printf("============\n");

    for (int i = 0; i < accountCount; i++)
    {
        printf("Username: %s\n", accounts[i].username);
        printf("Password: %s\n", accounts[i].password);
        // Display more account details if needed
        printf("\n");
    }
}

void viewSpecificAccount()
{
    if (accountCount == 0)
    {
        printf("\nNo accounts found.\n");
        return;
    }

    char username[20];
    printf("\nEnter the username of the account to view: ");
    scanf("%s", username);

    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            printf("\nAccount Details\n");
            printf("==============\n");
            printf("Username: %s\n", accounts[i].username);
            printf("Password: %s\n", accounts[i].password);
            // Display more account details if needed
            printf("\n");
            return;
        }
    }

    printf("\nAccount with username '%s' not found.\n", username);
}

void viewAccountsByStatus()
{
    if (accountCount == 0)
    {
        printf("\nNo accounts found.\n");
        return;
    }

    int status;
    printf("\nAccount Status\n");
    printf("==============\n");
    printf("[1] Active Accounts\n");
    printf("[2] Inactive Accounts\n");
    printf("Enter your choice: ");
    scanf("%d", &status);

    printf("\n");

    switch (status)
    {
    case 1:
        printf("Active Accounts\n");
        printf("===============\n");
        for (int i = 0; i < accountCount; i++)
        {
            // Display only active accounts
        }
        break;
    case 2:
        printf("Inactive Accounts\n");
        printf("=================\n");
        for (int i = 0; i < accountCount; i++)
        {
            // Display only inactive accounts
        }
        break;
    default:
        printf("\nInvalid option. Please try again.\n");
    }
}

void updateAccountStatus()
{
    if (accountCount == 0)
    {
        printf("\nNo accounts found.\n");
        return;
    }

    char username[20];
    printf("\nEnter the username of the account to update status: ");
    scanf("%s", username);

    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            int status;
            printf("\nUpdate Account Status\n");
            printf("====================\n");
            printf("[1] Activate Account\n");
            printf("[2] Deactivate Account\n");
            printf("Enter your choice: ");
            scanf("%d", &status);

            switch (status)
            {
            case 1:
                // Activate account
                break;
            case 2:
                // Deactivate account
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
            }

            return;
        }
    }

    printf("\nAccount with username '%s' not found.\n", username);
}

// Function to add a pre-made account
void addPreMadeAccount()
{
    // Check if the accounts array has reached its maximum capacity
    if (accountCount >= MAX_ACCOUNTS)
    {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    // Create a pre-made account
    Account preMadeAccount;
    strcpy(preMadeAccount.username, "user");
    strcpy(preMadeAccount.password, "password");
    // Set other account information

    // Add the pre-made account to the accounts array
    accounts[accountCount] = preMadeAccount;
    accountCount++;

    printf("Pre-made account added successfully!\n");
}

void userLogin()
{
    char username[20];
    char password[20];

    printf("\nAirline Booking System - User Login\n");
    printf("==================================\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Perform basic security check (pre-made user account)
    if (strcmp(username, "user") == 0 && strcmp(password, "password") == 0)
    {

        printf("\nLogin successful!\n");
        int option;

        do
        {
            displayUserMenu();
            printf("Enter your choice: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                updateUserInformation();
                break;
            case 2:
                bookFlight();
                break;
            case 3:
                viewFlightDetails();
                break;
            case 4:
                cancelFlight();
                break;
            case 5:
                printf("\nGoing back to main menu...\n");
                break;
            case 6:
                printf("\nClosing application...\n");
                return;
            default:
                printf("\nInvalid option. Please try again.\n");
            }
        } while (option != 6);
    }
    else
    {
        printf("\nInvalid username or password. Exiting...\n");
        return;
    }
}

void updateUserInformation()
{
    char username[20];
    printf("\nUpdate User Information\n");
    printf("=======================\n");

    strcpy(username, guestUserName);
    printf("\nEnter the username of the account to update information: %s", guestUserName);

    int accountIndex = -1;

    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            accountIndex = i;
            break;
        }
    }

    if (accountIndex == -1)
    {
        // Account doesn't exist, create a new account
        printf("\nCreating New Account for Username '%s'\n", username);
        printf("=======================================\n");

        strcpy(accounts[accountCount].username, username);

        // Update user information
        printf("Enter Full Name: ");
        scanf(" %[^\n]s", accounts[accountCount].fullName);
        printf("Enter Age: ");
        scanf("%d", &accounts[accountCount].age);
        printf("Enter Gender: ");
        scanf(" %[^\n]s", accounts[accountCount].gender);
        printf("Enter Address: ");
        scanf(" %[^\n]s", accounts[accountCount].address);
        printf("Enter Occupation: ");
        scanf(" %[^\n]s", accounts[accountCount].occupation);
        printf("Enter Nationality: ");
        scanf(" %[^\n]s", accounts[accountCount].nationality);
        printf("Enter Height (m): ");
        scanf("%f", &accounts[accountCount].height);
        printf("Enter Weight (kg): ");
        scanf("%f", &accounts[accountCount].weight);
        printf("Enter Civil Status: ");
        scanf(" %[^\n]s", accounts[accountCount].civilStatus);

        printf("\nNew account created successfully!\n");
    }
    else
    {
        // Account already exists, display current information and update
        printf("\nUpdate User Information for Account '%s'\n", accounts[accountIndex].username);
        printf("=======================================\n");

        // Display current user information
        printf("Current Full Name: %s\n", accounts[accountIndex].fullName);
        printf("Current Age: %d\n", accounts[accountIndex].age);
        printf("Current Gender: %s\n", accounts[accountIndex].gender);
        printf("Current Address: %s\n", accounts[accountIndex].address);
        printf("Current Occupation: %s\n", accounts[accountIndex].occupation);
        printf("Current Nationality: %s\n", accounts[accountIndex].nationality);
        printf("Current Height: %.2f\n", accounts[accountIndex].height);
        printf("Current Weight: %.2f\n", accounts[accountIndex].weight);
        printf("Current Civil Status: %s\n", accounts[accountIndex].civilStatus);

        // Update user information
        printf("\nEnter New User Information\n");
        printf("============================\n");
        printf("Enter Full Name: ");
        scanf(" %[^\n]s", accounts[accountIndex].fullName);
        printf("Enter Age: ");
        scanf("%d", &accounts[accountIndex].age);
        printf("Enter Gender: ");
        scanf(" %[^\n]s", accounts[accountIndex].gender);
        printf("Enter Address: ");
        scanf(" %[^\n]s", accounts[accountIndex].address);
        printf("Enter Occupation: ");
        scanf(" %[^\n]s", accounts[accountIndex].occupation);
        printf("Enter Nationality: ");
        scanf(" %[^\n]s", accounts[accountIndex].nationality);
        printf("Enter Height: ");
        scanf("%f", &accounts[accountIndex].height);
        printf("Enter Weight: ");
        scanf("%f", &accounts[accountIndex].weight);
        printf("Enter Civil Status: ");
        scanf(" %[^\n]s", accounts[accountIndex].civilStatus);

        printf("\nUser information updated successfully!\n");
    }
}

void bookFlight()
{
    char username[20];
    printf("\nBook A Flight\n");
    printf("==============\n");

    strcpy(username, guestUserName);
    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            printf("\nBook A Flight for Account '%s'\n", accounts[i].username);
            printf("================================\n");

            // Select location and destination
            char location[20];
            char destination[20];
            printf("Available Locations: [1] Mactan International Airport [0] Back\n");
            printf("Select Location: ");
            int locationChoice;
            scanf("%d", &locationChoice);
            switch (locationChoice)
            {
            case 0:
                return;
            case 1:
                strcpy(location, "Mactan International Airport");
                break;
            default:
                printf("Invalid location choice.\n");
                return;
            }

            printf("Available Destinations\nInternational: [1] DUBAI  [2] DOHA  [3] SINGAPORE [4] TOKYO  [5] BUSAN  [6] SEOUL \nDomestic: [7] EL NIDO [8] GEN SANTOS [9] BUTUAN [10] DAVAO [11] PILI [12] MANILA \n[13] ZAMBOANGA [14] ANGELES CITY [15] MAMBAJAO [16] TACLOBAN [17] SIARGAO [18] ILOILO \n[19] CAGAYAN DE ORO [20] DUMAGUETE\n");
            printf("Select Destination: ");
            int destinationChoice;
            scanf("%d", &destinationChoice);
            switch (destinationChoice)
            {
            case 1:
                strcpy(destination, "DUBAI");
                break;
            case 2:
                strcpy(destination, "DOHA");
                break;
            case 3:
                strcpy(destination, "SINGAPORE");
                break;
            case 4:
                strcpy(destination, "TOKYO");
                break;
            case 5:
                strcpy(destination, "BUSAN");
                break;
            case 6:
                strcpy(destination, "SEOUL");
                break;
            case 7:
                strcpy(destination, "EL NIDO");
                break;
            case 8:
                strcpy(destination, "GEN SANTOS");
                break;
            case 9:
                strcpy(destination, "BUTUAN");
                break;
            case 10:
                strcpy(destination, "DAVAO");
                break;
            case 11:
                strcpy(destination, "PILI");
                break;
            case 12:
                strcpy(destination, "MANILA");
                break;
            case 13:
                strcpy(destination, "ZAMBOANGA");
                break;
            case 14:
                strcpy(destination, "ANGELES CITY");
                break;
            case 15:
                strcpy(destination, "MAMBAJAO");
                break;
            case 16:
                strcpy(destination, "TACLOBAN");
                break;
            case 17:
                strcpy(destination, "SIARGAO");
                break;
            case 18:
                strcpy(destination, "ILOILO");
                break;
            case 19:
                strcpy(destination, "CAGAYAN DE ORO");
                break;
            case 20:
                strcpy(destination, "DUMAGUETE");
                break;
            case 0:
                return;

            default:
                printf("Invalid destination choice.\n");
                return;
            }

            // Select departure time and date
            printf("Available Departure Times: [1] 10:00 AM  [2] 2:00 PM  [3] 6:00 PM\n");
            printf("Select Departure Time: ");
            int departureChoice;
            scanf("%d", &departureChoice);
            char departureTime[10];
            switch (departureChoice)
            {
            case 1:
                strcpy(departureTime, "10:00 AM");
                break;
            case 2:
                strcpy(departureTime, "2:00 PM");
                break;
            case 3:
                strcpy(departureTime, "6:00 PM");
                break;
            default:
                printf("Invalid departure time choice.\n");
                return;
            }

            printf("Enter Departure Date (DD/MM/YYYY): ");
            char departureDate[12];
            scanf("%s", departureDate);

            // Check availability and book the flight
            // In this example, we assume a maximum of 5 passengers per schedule
            int maxPassengersPerSchedule = 5;
            int bookedPassengers = 0; // You should update this based on the actual booking logic

            if (bookedPassengers < maxPassengersPerSchedule)
            {
                printf("Flight booked successfully!\n");

                // Generate and save the flight details to a text file
                FILE *file = fopen("flight_details.txt", "w");
                if (file != NULL)
                {
                    fprintf(file, "Account: %s\n", accounts[i].username);
                    fprintf(file, "Location: %s\n", location);
                    fprintf(file, "Destination: %s\n", destination);
                    fprintf(file, "Departure Time: %s\n", departureTime);
                    fprintf(file, "Departure Date: %s\n", departureDate);
                    // Add more flight details as needed
                    fclose(file);

                    printf("Flight details saved to 'flight_details.txt'.\n");
                }
                else
                {
                    printf("Failed to save flight details.\n");
                }
            }
            else
            {
                printf("This schedule is fully booked.\n");
            }

            return;
        }
    }

    printf("\nAccount with username '%s' not found.\n", username);
}

void viewFlightDetails()
{
    printf("\nView Flight Details\n");
    printf("===================\n");

    char username[20];
    strcpy(username, guestUserName);

    int accountIndex = -1;

    for (int i = 0; i < accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            accountIndex = i;
            break;
        }
    }

    if (accountIndex == -1)
    {
        printf("\nAccount with username '%s' not found.\n", username);
        return;
    }

    // Retrieve and display flight details
    int flightCount = accounts[accountIndex].flightCount;

    if (flightCount == 0)
    {
        printf("No flight details found.\n");
        return;
    }

    printf("Flight Details:\n");

    for (int i = 0; i < flightCount; i++)
    {
        FlightDetails flight = accounts[accountIndex].flights[i];
        printf("Flight %d:\n", i + 1);
        printf("Location: %s\n", flight.location);
        printf("Destination: %s\n", flight.destination);
        printf("Departure Time: %s\n", flight.departureTime);
        printf("Departure Date: %s\n", flight.departureDate);
        printf("Flight Status: %s\n", flight.status ? "Confirmed" : "Cancelled");
        printf("***************************\n");
    }
}

void cancelFlight()
{
    printf("\nCancel Flights\n");
    printf("==============\n");
    // Add code to cancel/delete a flight
}
