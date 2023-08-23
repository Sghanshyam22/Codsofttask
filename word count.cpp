#include <iostream>
#include <string>

using namespace std;

int main() 
{
    char line[100];
    cout << "enter a line of text: ";
    cin.getline(line,100);

    int i, count=1;
    for (i=0; i<=100; i++)
    {
        if (line[i] == ' ')
        {
            if (line[i+1] != ' ')
            {
                count++;
            }
        }
    }
    cout <<"\nNumber of words:  " <<  count;

    return 0;
}  