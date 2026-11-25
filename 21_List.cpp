#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;

struct Ticket
{
    string destination;
    int flightNumber;
    string passenger;
    string date;
};

class Airport
{
private:
    list<Ticket> tickets;

public:
    void AddTicket()
    {
        Ticket t;

        cout << "Enter destination: ";
        getline(cin >> ws, t.destination);

        cout << "Enter flight number: ";
        cin >> t.flightNumber;

        cout << "Enter passenger name: ";
        getline(cin >> ws, t.passenger);

        cout << "Enter departure date (DD.MM.YYYY): ";
        cin >> t.date;

        tickets.push_back(t);

        cout << "\nTicket successfully added!\n";
    }

    void DeleteByPassenger()
    {
        string name;

        cout << "Enter passenger name: ";
        getline(cin >> ws, name);

        int count = 0;

        for (auto it = tickets.begin(); it != tickets.end();)
        {
            if (it->passenger == name)
            {
                it = tickets.erase(it);
                count++;
            }
            else
                ++it;
        }

        cout << "\nDeleted tickets: " << count << endl;
    }

    void DeleteByFlight()
    {
        int number;

        cout << "Enter flight number: ";
        cin >> number;

        int count = 0;

        for (auto it = tickets.begin(); it != tickets.end();)
        {
            if (it->flightNumber == number)
            {
                it = tickets.erase(it);
                count++;
            }
            else
                ++it;
        }

        cout << "\nDeleted tickets: " << count << endl;
    }

    void SearchByFlight()
    {
        int number;
        bool found = false;

        cout << "Enter flight number: ";
        cin >> number;

        for (const auto& t : tickets)
        {
            if (t.flightNumber == number)
            {
                ShowTicket(t);
                found = true;
            }
        }

        if (!found)
            cout << "\nNo tickets found!\n";
    }

    void SearchByDate()
    {
        string date;
        bool found = false;

        cout << "Enter departure date: ";
        cin >> date;

        for (const auto& t : tickets)
        {
            if (t.date == date)
            {
                ShowTicket(t);
                found = true;
            }
        }

        if (!found)
            cout << "\nNo tickets found!\n";
    }

    void ShowTicket(const Ticket& t)
    {
        cout << "\nDestination: " << t.destination;
        cout << "\nFlight number: " << t.flightNumber;
        cout << "\nPassenger: " << t.passenger;
        cout << "\nDeparture date: " << t.date << endl;
        cout << "-----------------------------\n";
    }

    void ShowAll()
    {
        if (tickets.empty())
        {
            cout << "\nTicket list is empty!\n";
            return;
        }

        for (const auto& t : tickets)
            ShowTicket(t);
    }

    void SortByDate()
    {
        tickets.sort([](const Ticket& a, const Ticket& b)
            {
                return a.date < b.date;
            });

        cout << "\nTickets sorted by date!\n";
    }

    void SortByDestination()
    {
        tickets.sort([](const Ticket& a, const Ticket& b)
            {
                return a.destination < b.destination;
            });

        cout << "\nTickets sorted by destination!\n";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Airport airport;
    int choice;

    do
    {
        cout << "\n========== AIRPORT ==========\n";
        cout << "1. Add ticket\n";
        cout << "2. Delete ticket by passenger\n";
        cout << "3. Delete ticket by flight number\n";
        cout << "4. Search by flight number\n";
        cout << "5. Search by departure date\n";
        cout << "6. Show all tickets\n";
        cout << "7. Sort by date\n";
        cout << "8. Sort by destination\n";
        cout << "0. Exit\n";
        cout << "=============================\n";
        cout << "Your choice: ";
        cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            airport.AddTicket();
            break;

        case 2:
            airport.DeleteByPassenger();
            break;

        case 3:
            airport.DeleteByFlight();
            break;

        case 4:
            airport.SearchByFlight();
            break;

        case 5:
            airport.SearchByDate();
            break;

        case 6:
            airport.ShowAll();
            break;

        case 7:
            airport.SortByDate();
            break;

        case 8:
            airport.SortByDestination();
            break;

        case 0:
            cout << "Program terminated!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}
