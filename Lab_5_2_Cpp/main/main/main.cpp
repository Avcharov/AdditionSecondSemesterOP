#include "header.h"

using namespace std;

int main()
{
    srand(time(NULL));

    int amount_of_two;
    cout << "Amount of systems with 2 equations: ";//Input the num of equations
    cin >> amount_of_two;

    int amount_of_three;
    cout << "Amount of systems with 3 equations: ";//Input the num of equations
    cin >> amount_of_three;

    vector <TSystemLinearEquation*> all_systems;
    fill_systems(all_systems, amount_of_two, amount_of_three);

    for (size_t i = 0; i < all_systems.size(); i++)
    {
        cout << "System# " << i + 1 << endl;
        all_systems[i]->display_system();
        all_systems[i]->find_solution();

        cout << endl;
    }

    string to_check;
    cout << "Enter the possible solution to check [x y] or [x y z] - format: "; //Input answers to check
    cin.ignore();
    getline(cin, to_check);

    for (size_t i = 0; i < all_systems.size(); i++)
    {
        if (all_systems[i]->is_roots(to_check))
        {
            cout << "System#" << i + 1 << " has this set of roots.";
        }
        else
        {
            cout << "System#" << i + 1 << " has another set of roots.";
        }
        cout << endl;
    }

    return 0;
}