#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Image { // this class contains image member functions and variables
    private:
        vector<int> AsciImage; // vector holds all ascii number 
        int x , y; // dimensions
    public:
        Image() { };
        Image(string FileName); // reads filename and create object
        Image(string x , string y); // create white ppm file according to dimensions
        
        const int ReadImageData(string FileName); // reads test.ppm and contains setImage for folding AsciImage with test.ppm
        const void SaveImage(string FileName)const; // saving output.ppm
        const void PrintExactDimensions(string a , string b); // according to given dimensions print exact dimension
        const void PrintDimension();
        const void ChangeExactDimensions(string a , string b); // according to given dimensions change exact dimension
        const Image operator+(Image rValue);
        const Image operator-(Image rValue);
        friend const ostream & operator << (ostream &out, Image &c);
        int& operator()(int x , int y , int channel);
        static int FileExistorWhat ; // for checking if a file  exist or not
        
        const vector<int>& getImage() const { return AsciImage; } //getter for vector
        void setImage(int a) { AsciImage.push_back(a); } // setter for vector which sets vector int by int
        void setImage(vector<int> a) { AsciImage = a ; } // setter for vector which sets whole vector by equaling another vector 
        const int getX() const { return this->x; } // getter for dimension x
        const int getY() const { return this->y; } // getter for dimension y
        void setX(int x) { this->x = x;}
        void setY(int y) { this->y = y;}
};

int Image::FileExistorWhat = 0;

int& Image::operator()(int x , int y , int channel) {
    x++;
    y++;
    int index = (y * this->getY()) + (x - this->getX()) - 1; // formula for reaching given index
    if(channel == 1){
        return this->AsciImage[index * 3];
    }
    else if(channel == 2){
        return this->AsciImage[(index * 3) + 1];
    }
    else{
        return this->AsciImage[(index * 3) + 2];
    } 
}

const ostream & operator << (ostream &out,  Image &c)
{
    int counter = 0;
   out << "P3" << endl << c.getX() << " " << c.getY() << endl << "255" << endl; // default adding these to output.ppm for gimp
    for(int i = 0 ; i < c.getImage().size() ; i++){
        if(counter == (3 * c.getX())){ // for readable output.ppm endl 
            out << endl;
            counter = 0;
        }
        out << c.getImage()[i] << " "; // folding output.ppm with new vector
        counter++;
    } 
    return out;
}

const Image Image::operator-(Image rValue) {
    Image result;
    int a = 0;
    vector<int> temp;
    if(rValue.getImage().size() != this->getImage().size()) { // if sizes are different sets results default 0
        result.setX(0);
        result.setY(0);
        result.setImage(temp);
    }
    else {
        for(int i = 0 ; i < rValue.getImage().size() ; i++) {
            a = this->getImage()[i] - rValue.getImage()[i]; // subtraction
            if(a < 0) {
                a = 0;
            }
            temp.push_back(a); // folding temp vector with new integers
    	}
	    result.setX(rValue.getX());
	    result.setY(rValue.getY());
	    result.setImage(temp); // sets object with new vector
    }
    return result;
}

const Image Image::operator+(Image rValue) {
    Image result;
    int a = 0;
    vector<int> temp;
    if(rValue.getImage().size() != this->getImage().size()) { // if sizes are different sets results default 0
        result.setX(0);
        result.setY(0);
        result.setImage(temp);
    }
    else {
        for(int i = 0 ; i < rValue.getImage().size() ; i++) {
            a = this->getImage()[i] + rValue.getImage()[i]; // sum 
            if(a > 255) {
                a = 255;
            }
            temp.push_back(a); // folding temp vector with new integers
    	}
	    result.setX(rValue.getX());
	    result.setY(rValue.getY());
	    result.setImage(temp); // sets object with new vector
    }
    return result;
}

bool isNumber(const string& input) // checks if given input is number or not
{
    for (char const &ch : input) {
        if (isdigit(ch) == 0) 
            return false;
    }
    return true;
 }

 const void Image::PrintDimension() {
    cout << getX() << " " << getY() << endl;
 }

Image::Image(string FileName) {
    if(ReadImageData(FileName) == 1) {
        FileExistorWhat = 1;
    }
    else {
        FileExistorWhat = 0;
    }
    
}

bool CheckValidity(string x , string y){
    if(!isNumber(x) || !isNumber(y)) {
        return false;
    }
    else {
        int a = stoi(x);
        int b = stoi(y);
        if(a <= 0 || b <= 0) {
            return false;
        }
    }
    return true;
}

bool CheckValidity(string x , string y , string z) {
    if(!isNumber(x) || !isNumber(y) || !isNumber(z)) {
        return false;
    }
    else {
        int a = stoi(x);
        int b = stoi(y);
        int c = stoi(z);
        if(a < 0 || b < 0 || c < 0 || a > 255 || b > 255 || c > 255){
            return false;
        }
    }
    return true;
}

bool GetNewPixels(int& k , int& g , int& m){ // uses for changing pixel values
    string a , b , c;
    cin >> a >> b >> c;
    if(CheckValidity(a , b , c) == false) {
        return false;
    }
    else {
        k = stoi(a);
        g = stoi(b);
        m = stoi(c);
        return true;
    }
}

const void Image::ChangeExactDimensions(string a , string b) { // changes given index for object vector
    int x = 0 , y = 0 , k = 0 , g = 0 , m = 0;
    if(CheckValidity(a,b) == false) {
        return;
    }
    else {
        x = stoi(a);
        y = stoi(b);
        if(getImage().size() < (x * y) * 3){
            return;
        }
        else {
            int index = (y * this->getY()) + (x - this->getX()) - 1; // formula for reaching exact index
            cout << "Enter new pixel values \n";
            if(GetNewPixels(k , g , m) == false) { // if new pixel values are not integer it does nothing
                return;
            }
            else {
                this->AsciImage[index * 3] = k; // we change int values of exact dimensions
                this->AsciImage[(index * 3) + 1] = g; // we change int values of exact dimensions
                this->AsciImage[(index * 3) + 2] = m; // we change int values of exact dimensions
            }
        }
    }
}

const void Image::PrintExactDimensions(string a , string b) {
    int x = 0 , y = 0;
    if(CheckValidity(a,b) == false) {
        return;
    }
    else {
        x = stoi(a);
        y = stoi(b);
        if(getImage().size() < (x * y) * 3){
            return;
        }
        else {
            int index = (y * this->getY()) + (x - this->getX()) - 1; // formula for reaching exact index
            cout << getImage()[index * 3] << " " << getImage()[(index * 3) + 1] << " " << getImage()[(index * 3) + 2] << endl; // it prints exact dimensions
        }
    }
}

Image::Image(string xv , string yv) { // according to given dimensions it creates white ppm file
    int x , y;
    if(CheckValidity(xv,yv) == false) {
        x = 0;
        y = 0;
    }
    else {
        x = stoi(xv);
        y = stoi(yv);
    }
    setX(x);
    setY(y);
    string FileName;
    int counter = 0;
    cout << "please name a new white ppm file \n";
    cin >> FileName;
    ofstream output(FileName);
    output << "P3" << endl << x << " " <<  y << endl << "255" << endl; // default adding these to output.ppm for gimp
    for(int i = 0 ; i < ((x * 3) * y)  ; i++) {
        if(counter == (x * 3)){ // for readable output.ppm endl 
            output << endl;
            counter = 0;
        }
        setImage(255);
        output << getImage()[i] << " "; // folding output.ppm with new vector
        counter++;
    }
    output.close();
}

const void Image::SaveImage(string FileName)const {
    int counter = 0;
    ofstream output(FileName);
    output << "P3" << endl << getX() << " " << getY() << endl << "255" << endl; // default adding these to output.ppm for gimp
    for(int i = 0 ; i < getImage().size() ; i++){
        if(counter == (3 * getX())){ // for readable output.ppm endl 
            output << endl;
            counter = 0;
        }
        output << getImage()[i] << " "; // folding output.ppm with new vector
        counter++;
    }
    output.close();
}

const int Image::ReadImageData(string FileName) {
    ifstream input;
    string  num;
    int counter = 0;
    vector<string> img;
    input.open(FileName);
    if(!input) { // if there is no file it returns 0
        return 0;
    }
    while (input >> num) {
        if(counter == 1){ // first string is dimension of x
            int indeX = stoi(num);
            setX(indeX);
        }
        if(counter == 2) { // second string is dimension of y
            int indeY = stoi(num);
            setY(indeY);
        }
        if(counter > 3) { // first 3 string is P3 4 4 and 255 so we must skip them
            img.push_back(num); // folding temp vector with test.ppm
        }
        counter++;
    }
    for(int z = 0 ; z < img.size() ; z++) {
        setImage(stoi(img[z])); // setting AsciImage with test.ppm
    }
    input.close();
    return 1;
}

int test_addition(const string filename_image1, const string filename_image2, const string filename_image3) {
    Image obj1(filename_image1) , obj2(filename_image2) , obj3; // creates objects with constructors
    if(Image::FileExistorWhat == 0) { // if there is no file it returns 0
        return 0;
    }
    obj3 = obj1 + obj2;
    obj3.SaveImage(filename_image3);
    return 1;
}

int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3) {
    Image obj1(filename_image1) , obj2(filename_image2) , obj3; // creates objects with constructors
    if(Image::FileExistorWhat == 0){ // if there is no file it returns 0
        return 0;
    }
    obj3 = obj1 - obj2;
    obj3.SaveImage(filename_image3);
    return 1;
}

int read_ppm(const string source_ppm_file_name, Image& destination_object) {
    if(destination_object.ReadImageData(source_ppm_file_name) == 0){ // class already have read function and we use it
        return 0;
    }
    else {
        return 1;
    }
}

int write_ppm(const string destination_ppm_file_name, const Image& source_object) {
    source_object.SaveImage(destination_ppm_file_name); // class already have write function and we use it
    return 1;
}

int swap_channels(Image& image_object_to_be_modified, string swap_choice){
    vector<int> red , green , blue ,temp;
    int a = 0;
    for(int i = 0 ; i < image_object_to_be_modified.getImage().size() ; i+=3) { // loop splits red green and blue channels to different vectors
        red.push_back(image_object_to_be_modified.getImage()[i]); // holds only red
        green.push_back(image_object_to_be_modified.getImage()[i+1]); // holds only green
        blue.push_back(image_object_to_be_modified.getImage()[i+2]); // holds only blue
    }
    if(swap_choice == "1") {// swap red and green
        for(int i = 0 ; i < image_object_to_be_modified.getX() ; i++) {
            for(int j = 0 ; j < image_object_to_be_modified.getY() ; j++) {
                image_object_to_be_modified(j , i , 1) = green[a]; // with using () overload we can change exact index so we swap red and green
                image_object_to_be_modified(j , i , 2) = red[a];
                a++;
            }
        }
        return 1;
    }
    else if(swap_choice == "2") {// swap red and blue
        for(int i = 0 ; i < image_object_to_be_modified.getX() ; i++) {
            for(int j = 0 ; j < image_object_to_be_modified.getY() ; j++) {
                image_object_to_be_modified(j , i , 1) = blue[a];// with using () overload we can change exact index so we swap red and blue
                image_object_to_be_modified(j , i , 3) = red[a];
                a++;
            }
        }
        return 1;
    }
    else if(swap_choice == "3") {// swap blue and green
        for(int i = 0 ; i < image_object_to_be_modified.getX() ; i++) {
            for(int j = 0 ; j < image_object_to_be_modified.getY() ; j++) {
                image_object_to_be_modified(j , i , 2) = blue[a];// with using () overload we can change exact index so we swap blue and green
                image_object_to_be_modified(j , i , 3) = green[a];
                a++;
            }
        }
        return 1;
    }
    else{
        return 1;
    }
}

Image single_color(const Image& source, string color_choice) {
    vector<int> red , green , blue ;
    Image temp;
    temp = source;
    if(color_choice == "1") {
        for(int i = 0 ; i < source.getX() ; i++) { // takes only red and others become zero
            for(int j = 0 ; j < source.getY() ; j++) { // with using () overload we can set all blue and green channels with zero
                temp(j , i , 2) = 0;
                temp(j , i , 3) = 0;
            }
        }
    }
    else if(color_choice == "2") {
        for(int i = 0 ; i < source.getX() ; i++) { // takes only green and others become zero
            for(int j = 0 ; j < source.getY() ; j++) { // with using () overload we can set all blue and red channels with zero
                temp(j , i , 1) = 0;
                temp(j , i , 3) = 0;
            }
        }
    }
    else if(color_choice == "3") {
        for(int i = 0 ; i < source.getX() ; i++) { // takes only blue and others become zero
            for(int j = 0 ; j < source.getY() ; j++) { // with using () overload we can set all green and red channels with zero
                temp(j , i , 1) = 0;
                temp(j , i , 2) = 0;
            }
        }
    }
    return temp;
}

int test_print(const string filename_image1) {
    Image image1(filename_image1);
    if(Image::FileExistorWhat == 0){
        return 0;
    }
    else{
    cout << image1;
    return 1;
    }
}

int main(int argc , char** argv) {
    if(*argv[1] == '1' || *argv[1] == '2'){ // checking for if user wants to sum or substract and gives true inputs
        if(argc != 5) {
            exit(1);
        }
    }
    if(*argv[1] == '3' || *argv[1] == '4' || *argv[1] == '5' || *argv[1] == '6' || *argv[1] == '7'){
        if(argc != 4) { // checking for if user wants to swap or only one channel and gives true inputs
            exit(1);
        }
    }
    if(*argv[1] == '1') {
        test_addition(argv[2], argv[3], argv[4]);
    }
    else if(*argv[1] == '2') {
        test_subtraction(argv[2], argv[3], argv[4]);
    }
    else if(*argv[1] == '3') {
        Image destination_object;
        read_ppm(argv[2] , destination_object);
        swap_channels(destination_object , "2");
        write_ppm(argv[3] , destination_object);
    }
    else if(*argv[1] == '4') {
        Image destination_object;
        read_ppm(argv[2] , destination_object);
        swap_channels(destination_object , "3");
        write_ppm(argv[3] , destination_object);
    }
    else if(*argv[1] == '5') {
        Image destination_object , red;
        read_ppm(argv[2] , destination_object);
        red = single_color(destination_object , "1");
        write_ppm(argv[3] , red);
    }
    else if(*argv[1] == '6') {
        Image destination_object , green;
        read_ppm(argv[2] , destination_object);
        green = single_color(destination_object , "2");
        write_ppm(argv[3] , green);
    }
    else if(*argv[1] == '7') {
        Image destination_object , blue;
        read_ppm(argv[2] , destination_object);
        blue = single_color(destination_object , "3");
        write_ppm(argv[3] , blue);
    }
    return 0;
}
