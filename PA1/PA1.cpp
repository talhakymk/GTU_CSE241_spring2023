#include <iostream>
#include <cstring>
using namespace std;

void FirstVersionOfGame(char *argv);
void SecondVersionOfGame(int number);
int GenerateSecretNumber(int NumOfDigits);
int TakeInput(int NumOfDigits);
bool check_number(string str);
int FirstCount(int SecretNumber, int UsersNumber, int NumOfDigits);
int SecondCount(int SecretNumber, int UsersNumber, int NumOfDigits);
bool CheckTheNumber(int number);
bool check_first_digit(string str);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "E0" << endl;
        exit(1);
    }
    srand(time(0));

    if (strcmp("-r", argv[1]) == 0) // checking if user enters -r
    { // if user enters -r program starts first version
        int digits = atoi(argv[2]); 
        if(check_number(argv[2]) == false){ // checking if secret number is a integer or not
            cerr << "E2" << endl;
            exit(1);
        }
        if(digits == 0 || digits > 9){ // if users enters digits 0 or more than 9 it will be error
            cerr << "E0" << endl;
            exit(1);
        }
        FirstVersionOfGame(argv[2]);
    }
    else if (strcmp("-u", argv[1]) == 0) // checking if user enters -u
    {
        if(check_number(argv[2]) == false){ // checking if secret number is a integer or not
            cerr << "E2" << endl;
            exit(1);
        }
        if(check_first_digit(argv[2]) == false){ // chechking if first digit is zero
            cout << "E0" << endl;
            exit(1);
        }
        int number = atoi(argv[2]);
        if(CheckTheNumber(number) == true){
            SecondVersionOfGame(number);
       }
    }
    else // ıf user enters something different from -r or -u it will be error
    {
        cerr << "E0" << endl;
        exit(1);
    }
    cout << endl;

    return 0;
}

void FirstVersionOfGame(char *argv) // if user enter -r this part will execute
{
    int NumOfDigits = atoi(argv); // converting command line value to integer
    int SecretNumber = GenerateSecretNumber(NumOfDigits);
    //cout << SecretNumber << endl; 
    int counter = 0;
    while(true){
	    int UsersNumber = TakeInput(NumOfDigits);
	    counter++;
	    if(counter == 100){ // ıf user cant find the secret number in 100 iteration user will be failed
	        cout << "FAILED \n";
	        exit(1);
	    }
	    if(SecretNumber == UsersNumber){
	        cout << "FOUND ";
	        cout << counter << endl;
	        exit(1);
	    }
	    int firstC = FirstCount(SecretNumber, UsersNumber, NumOfDigits);
	    int secondC = SecondCount(SecretNumber, UsersNumber, NumOfDigits);
	    cout << firstC << " " << secondC << endl;
    }
}

int GenerateSecretNumber(int NumOfDigits) // for -r this function will generate secret number
{
    int SecretNumber[NumOfDigits];
    bool DifferentDigits[9] = {false, false, false, false, false, false, false, false, false}; // created for checking if any digits have same value
    int a = 0;
    for (int i = 0; i < NumOfDigits; i++)
    {
        a = (rand() % 10);
        if (i == 0 && a == 0)
        {
            i--;
        }
        else if (DifferentDigits[a - 1] == false)
        {
            DifferentDigits[a - 1] = true;
            SecretNumber[i] = a;
        }
        else
        {
            i--;
        }
    }
    int number = 0; 
    for (int i = 0; i < NumOfDigits; i++)
    {
        number *= 10;
        number += SecretNumber[i];
    }
    return number;
}

int TakeInput(int NumOfDigits)
{
    string input = "";
    bool DifferentDigits[9] = {false, false, false, false, false, false, false, false, false};
    cout << "Please enter " << NumOfDigits << " digit number : ";
    cin >> input;
    if (input.length() != NumOfDigits)
    { // if user enter more digits it is error
        cerr << "E1" << endl;
        exit(1);
    }
    if (input[0] == '0'){
        cerr << "E1" << endl;
        exit(1);
    }
    else if (check_number(input) == false)
    { // if user enter non integer value it is error
        cerr << "E2" << endl;
        exit(1);
    }
    for (int i = 0; i < NumOfDigits; i++)
    {
        char a = input[i];
        int b = (int)a;
        if (i == 0 && b == 0)
        { // if user enter integer which starts with 0 is error
            cerr << "E0" << endl;
            exit(1);
        }
        else if (DifferentDigits[b - 1] == false)
        { // if user enter same value for different digits it is a error
            DifferentDigits[b - 1] = true;
        }
        else if (DifferentDigits[b - 1] == true)
        {
            cerr << "E0" << endl;
            exit(1);
        }
    }
    int result = stoi(input);
    return result;
}

bool check_number(string str)
{ // checking if user enter non integer value
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

int FirstCount(int SecretNumber, int UsersNumber, int NumOfDigits) // this function returns first count
{
    int counter = 0;
    int arrSecret[NumOfDigits];
    int arrUsers[NumOfDigits];
    for (int i = (NumOfDigits - 1); i >= 0; i--) // converts int to array for making count easy
    {
        arrSecret[i] = SecretNumber % 10;
        arrUsers[i] = UsersNumber % 10;
        SecretNumber /= 10;
        UsersNumber /= 10;
    }
    for (int j = 0; j < NumOfDigits; j++)
    {
        if (arrSecret[j] == arrUsers[j])
        {
            counter++;
        }
    }
    return counter;
}
int SecondCount(int SecretNumber, int UsersNumber, int NumOfDigits) // this function returns second count
{
    int counter = 0;
    int arrSecret[NumOfDigits];
    int arrUsers[NumOfDigits];
    for (int i = (NumOfDigits - 1); i >= 0; i--) // converts int to array for making count easy
    {
        arrSecret[i] = SecretNumber % 10;
        arrUsers[i] = UsersNumber % 10;
        SecretNumber /= 10;
        UsersNumber /= 10;
    }
    for (int z = 0; z < NumOfDigits; z++)
    {
        for (int y = 0; y < NumOfDigits; y++)
        {
            if (arrUsers[z] == arrSecret[y] && z != y)
            {
                counter++;
            }
        }
    }
    return counter;
}

bool CheckTheNumber(int number){
    int Snumber = number;
    int digits = 0; while (number != 0) { number /= 10; digits++; } // finds number of digits
    int arrNumber[digits];
    if(digits == 0 || digits > 9){
        cerr << "E1" << endl;
        exit(1);
    }
    for (int i = (digits - 1); i >= 0; i--) // converting int to array
    {
        arrNumber[i] = Snumber % 10;
        Snumber /= 10;
    }
    for(int i = 0 ; i < digits ; i++){
        for(int j = 0 ; j < digits ; j++ ){ // checks if secret number has same value for different digits
            if(arrNumber[i] == arrNumber[j] && i != j){
                cerr << "E0" << endl;
                exit(1);
            }
        }
        
    }
    return true;
}

void SecondVersionOfGame(int number){ // if user enter -u this part of program will execute
    int trash = number;
    int digits = 0; while (trash != 0) { trash /= 10; digits++; } // finds number of digits
    int counter = 0;
    while(true){
	    int UsersNumber = TakeInput(digits);
	    counter++;
	    if(counter == 100){ // ıf user cant find the secret number in 100 iteration user will be failed
	        cout << "FAILED \n";
	        exit(1);
	    }
	    if(number == UsersNumber){
	        cout << "FOUND ";
	        cout << counter << endl;
	        exit(1);
	    }
	    int firstC = FirstCount(number, UsersNumber, digits);
	    int secondC = SecondCount(number, UsersNumber, digits);
	    cout << firstC << " " << secondC << endl;
    }
}

bool check_first_digit(string str){ // checks if first digit is 0 for -u part
    if(str[0] == '0'){  
        return false;
    }
    return true;
}
