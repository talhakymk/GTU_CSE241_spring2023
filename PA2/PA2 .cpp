#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Menu { // this class contains menu and submenu's
    public:
        char MainMenu();
        char OpenAnImageMenu();
        char SaveImageDataMenu();
        char ScriptsMenu();
        char ConvertToGrayscaleMenu();
        bool CheckZeroOrOne(string choice); // this method returns true if given variable is 0 or 1

};

class Image { // this class contains image member functions and variables
    private:
        vector<int> AsciImage; // vector holds all ascii number 
    public:
        void ReadImageData(); // reads test.ppm and contains setImage for folding AsciImage with test.ppm
        void WriteImageData(); // writes output.ppm according to given doubles
        void SaveImage(); // saving output.ppm
        
        vector<int> getImage() { return AsciImage; } //getter for vector
        void setImage(int a) { AsciImage.push_back(a); } // setter for vector which sets vector int by int
        void setImage(vector<int> a) { AsciImage = a; } // setter for vector which sets whole vector by equaling another vector 
};

void Image::SaveImage() {
    string FileName;
    int counter = 0;
    cin >> FileName;
    ofstream output(FileName);
    output << "P3" << endl << "4 4" << endl << "255" << endl; // default adding these to output.ppm for gimp
    for(int i = 0 ; i < getImage().size() ; i++) {
        if(counter == 12) { // for readable output.ppm endl 
            output << endl;
            counter = 0;
        }
        output << getImage()[i] << " "; // folding output.ppm with new vector
        counter++;
    }
    output.close();
}

void Image::ReadImageData() {
    ifstream input;
    string FileName , num;
    int counter = 0;
    vector<string> img;
    cin >> FileName;
    input.open(FileName);
    while (input >> num) {
        if(counter > 3) { // first 3 string is P3 4 4 and 255 so we must skip them
            img.push_back(num); // folding temp vector with test.ppm
        }
        counter++;
    }
    for(int z = 0 ; z < img.size() ; z++) {
        setImage(stoi(img[z])); // setting AsciImage with test.ppm
    }
    input.close();
}

void TakeInput(double &r , double &g , double &b) { // using for taking input in grayscale
    double a , y , c;
    while(true) { // endless loop if user dont enter true values
        if(cin >> a  >> y >> c && a != ' ' && b != ' ' && c != ' ') { // checking if given input is double and between 0 - 1
            if(a >= 0 && a < 1 && y >= 0 && y < 1 && c >= 0 && c < 1 ) {
                r = a;
                g = y;
                b = c;
                return; // return void to finish function
            }
        }
        cin.clear(); // if given input is char or not between 0 - 1 we clear cin function
        while (cin.get() != '\n'); 
    }
}

void Image::WriteImageData() {
    vector<int> temp = getImage(); // folding temp vector with test.ppm
    double r , g , b;
    int x , y , z;
    TakeInput(r , g , b);
    for(int i = 0 ; i < temp.size() ; i += 3) {
        x = r * temp[i]; // calculating r g b according to given formula
        y = g * temp[i+1]; // calculating r g b according to given formula
        z = b * temp[i+2]; // calculating r g b according to given formula
        if(x + y + z > 255) { // max int is 255 so if calculating int is more than 255 program must equal r g b with 255
            temp[i] = 255;
            temp[i+1] = 255;
            temp[i+2] = 255;
        }
        else {
            temp[i] = x + y + z;
            temp[i+1] = x + y + z;
            temp[i+2] = x + y + z;
        }
    }
    setImage(temp); // setting new vector 
}

char Menu::MainMenu() { // member function of Menu for main menu
    string choice = " ";
    while(true) { // endless loop if user dont enter true values
        cout <<"MAIN MENU"<< endl  <<"0 - Exit" << endl << "1 - Open An Image (D)" << endl
            << "2 - Save Image Data (D)" << endl << "3 - Scripts (D)" << endl;
        cin >> choice;
        if(choice.compare("0") == 0 || choice.compare("1") == 0 || choice.compare("2") == 0 || choice.compare("3") == 0 ) // comparing given choice if it is 0 , 1 , 2 or 3
            return choice[0];
    }
}

char Menu::OpenAnImageMenu() { // member function of Menu for open an image choice
    string choice = " ";
    while(true) { // endless loop if user dont enter true values
        cout << "OPEN AN IMAGE MENU" << endl <<"0 - UP" << endl << "1 - Enter The Name Of The Image File" << endl;
        cin >> choice;
        if(CheckZeroOrOne(choice)) // if input is 0 or 1 it can return 
            return choice[0];
    }
}

char Menu::SaveImageDataMenu() {
    string choice = " ";
    while(true) { // endless loop if user dont enter true values
        cout << "SAVE IMAGE DATA MENU" << endl << "0 - UP" << endl << "1 - Enter A File Name" << endl;
        cin >> choice;
        if(CheckZeroOrOne(choice)) // if input is 0 or 1 it can return 
            return choice[0];
    }
}

char Menu::ScriptsMenu() {
    string choice = " " ;
    string convert = " ";
    while(true) { // endless loop if user dont enter true values
        cout << "SCRIPTS MENU"<< endl <<"0 - UP" << endl << "1 - Convert To Grayscale (D)" << endl;
        cin >> choice;
        if(CheckZeroOrOne(choice)) {
            if(choice.compare("0") == 0) // if input is 0 it returns 0
                return choice[0];
            else if(choice.compare("1") == 0) { // if input is 1 it opens another submenu
                convert = ConvertToGrayscaleMenu(); // grayscale menu opens
                if(convert.compare("0") == 0) // if user enters 0 it continue and goes scripts menu
                    continue;
                else if(choice.compare("1") == 0) // if user enters 1 it return 1 
                    return convert[0];
            }
        }  
    }
}

char Menu::ConvertToGrayscaleMenu() {
    string choice = " ";
    while(true) { // endless loop if user dont enter true values
        cout <<"CONVERT TO GRAYSCALE MENU" << endl <<"0 - UP" << endl << "1 - Enter Coefficients For RED GREEN And BLUE Channels" << endl;
        cin >> choice;
        if(CheckZeroOrOne(choice)) // if input is 0 or 1 it can return 
            return choice[0];
    }
}

bool Menu::CheckZeroOrOne(string  choice) {
    if(choice.compare("0") == 0 || choice.compare("1") == 0) // checking given input if it is 0 or 1
        return true;
    else
        return false;
}

int main() {
    Menu menu; // object for menu class
    Image image; // object for image class
    char save , open , script;
    while(true) { // infinite loop for main menu
        switch(menu.MainMenu()) { // switch determines cases according to returning char from main menu member function
            case '0':
                return 0;
            case '1':
                while(true) {
                    open = menu.OpenAnImageMenu();
                    if(open == '0') // if user enters 0 it break and exit from loop so it can return back to main menu
                        break;
                    else if(open == '1')
                        image.ReadImageData();
                }
                break;
            case '2':
                while(true) {
                    save = menu.SaveImageDataMenu();
                    if(save == '0') // if user enters 0 it break and exit from loop so it can return back to main menu
                        break;
                    else if(save == '1')
                        image.SaveImage();
                }
                break;
            case '3':
                while(true) {
                    script = menu.ScriptsMenu();
                    if(script == '0') // if user enters 0 it break and exit from loop so it can return back to main menu
                        break;
                    else if(script == '1')
                        image.WriteImageData();
                }
                break;
        }
    }
    return 0;
}
