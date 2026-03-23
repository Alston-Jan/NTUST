#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main() {
    string input;
    getline(cin, input);

    int length1 = 0;
    int output[500] = { 0 }, amount[500] = { 0 }, count = 0, x = 0, check = 0, save = 0;
    length1 = input.size();
    for (int i = length1 - 1; i >= 0; i--)
    {
        if (input[i] != ' ')
        {
            if (input[i] != '-')
            {
                output[count] += ((int)input[i] - 48) * pow(10, x);
                x++;
            }
            else //璽计矪瞶
            {
                output[count] = 0 - output[count];
            }
        }
        else
        {
            x = 0;
            for (int ii = 0; ii < count; ii++)
            {
                if (output[count] == output[ii])
                {
                    check = 1;
                    amount[ii]++; //计碞++
                    break;
                }
            }
            if (check == 1) //Τт计
            {
                output[count] = 0;
            }
            else //⊿т计
            {
                amount[count]++;
                count++;
            }
            check = 0;
        }
    }
    //for final number
    x = 0;
    for (int ii = 0; ii < count; ii++)
    {
        if (output[count] == output[ii])
        {

            check = 1;
            amount[ii]++;

            break;
        }
    }
    if (check == 1)
    {
        output[count] = 0;
    }
    else
    {
        amount[count]++;
        count++;
    }
    check = 0;

    // Sort
    for (int i = 0; i < count; i++)
    {
        for (int ii = i + 1; ii < count; ii++)
        {
            if (output[i] < output[ii])
            {
                save = output[i];
                output[i] = output[ii];
                output[ii] = save;
                save = amount[i];
                amount[i] = amount[ii];
                amount[ii] = save;

            }
        }
    }
    cout << "N" << "\t" << "count\n";
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << "\t" << amount[i] << endl;
    }

}