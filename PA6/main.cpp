#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include <list>
using namespace std;

class Catalog { // class for base class
    private:
        vector<string> Title; // title is common for every sub-class
        vector<string> Year; // year is common for every sub-class
        vector<string> Genre = {"0000"}; // genre is common for every sub-class
    public:
        vector<string> getTitle();
        vector<string> getYear();
        vector<string> getGenre();
        void setTitle(vector<string> title);
        void setYear(vector<string> year);
        void setGenre(vector<string> genre);
};

class Book : public Catalog {
    private:
        vector<string> Author; // only book has author
        vector<string> Tag;  // only book has tag
    public:
        vector<string> getAuthor();
        vector<string> getTag();
        void setAuthor(vector<string> author);
        void setTag(vector<string> tag);
        Book(){ }
        Book(vector<string> title , vector<string> author , vector<string> year , vector<string> tag);
};

class Music : public Catalog {
    private:
        vector<string> Artist; // only music has artist
    public:
        vector<string> getArtist();
        void setArtist(vector<string> artist);
        Music(){ }
        Music(vector<string> title , vector<string> artist , vector<string> year , vector<string> genre);
};

class Movie : public Catalog {
    private:
        vector<string> Director; // only movie has director
        vector<string> Starring; // only movie has starring
    public:
        vector<string> getDirector();
        vector<string> getStarring();
        void setDirector(vector<string> director);
        void setStarring(vector<string> starring);
        Movie(){ }
        Movie(vector<string> title , vector<string> director , vector<string> year , vector<string> genre , vector<string> starring);
};

class Operations { // class for general operations
    public:
         Book BookCatalogActive(); // active book part
         Music MusicCatalogActive(); // active music part
         Movie MovieCatalogActive(); // active movie part
         void MovieCommandFounder(Movie obj , vector<string> command); //founding exception and reading command.txt happens in here
         void MusicCommandFounder(Music obj , vector<string> command); //founding exception and reading command.txt happens in here
         void BookCommandFounder(Book obj , vector<string> command); //founding exception and reading command.txt happens in here
};

vector<string> Catalog::getTitle() { return this->Title;}

vector<string> Catalog::getYear() { return this->Year;}

vector<string> Catalog::getGenre() {return this->Genre;}

void Catalog::setTitle(vector<string> title) {this->Title = title;}

void Catalog::setYear(vector<string> year) {this->Year = year;}

void Catalog::setGenre(vector<string> genre) { this->Genre = genre;}

vector<string> Book::getAuthor() {return this->Author;}

vector<string> Book::getTag() {return this->Tag;}

void Book::setAuthor(vector<string> author) {this->Author = author;}

void Book::setTag(vector<string> tag) {this->Tag = tag;}

Book::Book(vector<string> title , vector<string> author , vector<string> year , vector<string> tag) {
    setTitle(title);
    setAuthor(author);
    setYear(year);
    setTag(tag);
}

vector<string> Music::getArtist() {return this->Artist;}

void Music::setArtist(vector<string> artist) {this->Artist = artist;}

Music::Music(vector<string> title , vector<string> artist , vector<string> year , vector<string> genre) {
    setTitle(title);
    setArtist(artist);
    setYear(year);
    setGenre(genre);
}

vector<string> Movie::getDirector() {return this->Director;}

vector<string> Movie::getStarring() {return this->Starring;}

void Movie::setDirector(vector<string> director) {this->Director = director;}

void Movie::setStarring(vector<string> starring) {this->Starring = starring;}

Movie::Movie(vector<string> title , vector<string> director , vector<string> year , vector<string> genre , vector<string> starring){
    setTitle(title);
    setDirector(director);
    setYear(year);
    setGenre(genre);
    setStarring(starring);
}

vector<string> return_Whole_DataTxt() { // reads whole data.txt and push it into vector
    vector<string> wholeData;
    fstream ptr;
    string var;
    ptr.open("data.txt");
    while(ptr >> var) {
        wholeData.push_back(var);
    }
    ptr.close();
    return wholeData;
}

vector<string> return_Whole_CommandTxt() { // reads whole command.txt and push it into vector
    vector<string> wholeData;
    fstream ptr;
    string var;
    ptr.open("command.txt");
    while(ptr >> var) {
        wholeData.push_back(var);
    }
    ptr.close();
    return wholeData;
}
//extract between two ""
void FindFirstQuotationtoLastQuatotion(vector<string> &vec ,vector<string> &temp , int &counter , int &counter2 , vector<string>::iterator &za){
    string a = *za;
    string total;
    vector<string>::iterator itr;
    if(a[0] == '"' && counter == 0 ) {
        counter++;
        counter2++;
    }
    if(counter == 1 && a[a.length() - 1] != '"') {
        temp.push_back(a);
        temp.push_back(" ");
    }
    else if(a[a.length() - 1] == '"') {
        temp.push_back(a);
        for(itr = temp.begin(); itr != temp.end() ; itr++) {
            total.append(*itr);
        }
        temp.clear();
        vec.push_back(total);
        counter++;
        counter2++;
    }
}

Book Operations::BookCatalogActive() { // extract book object to title author year and tag
    vector<string> Whole_Data_Txt = return_Whole_DataTxt();
    vector<string> title;
    vector<string> tempTitle;
    vector<string> author;
    vector<string> tempAuthor;
    vector<string> year;
    vector<string> tempYear;
    vector<string> tag;
    vector<string> tempTag;
    int counter = 0; // count of "" number
    int counter2 = 0;
    for(vector<string>::iterator it = Whole_Data_Txt.begin() ; it != Whole_Data_Txt.end(); ++it) {
        if(counter2 < 2)
            FindFirstQuotationtoLastQuatotion(title , tempTitle , counter , counter2, it);
        else if(counter2 < 4) {
            if(counter2 == 2)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(author ,tempAuthor , counter , counter2, it);
        }
        else if(counter2 < 6) {
            if(counter2 == 4)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(year , tempYear, counter , counter2, it);
        }
        else if(counter2 < 8) {
            if(counter2 == 6)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(tag , tempTag , counter , counter2, it);
            if(counter2 == 8) {
                counter2 = 0;
                counter = 0;
            } 
        }
    }
    return Book(title , author , year , tag);
}

Music Operations::MusicCatalogActive() { // extract music object to title artist year and genre
    vector<string> Whole_Data_Txt = return_Whole_DataTxt();
    vector<string> title;
    vector<string> tempTitle;
    vector<string> artist;
    vector<string> tempArtist;
    vector<string> year;
    vector<string> tempYear;
    vector<string> genre;
    vector<string> tempGenre;
    int counter = 0; // count of "" number
    int counter2 = 0;
    for(vector<string>::iterator it = Whole_Data_Txt.begin() ; it != Whole_Data_Txt.end(); ++it){
        if(counter2 < 2)
            FindFirstQuotationtoLastQuatotion(title , tempTitle ,counter , counter2, it);
        else if(counter2 < 4){
            if(counter2 == 2)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(artist , tempArtist, counter , counter2, it);
        }
        else if(counter2 < 6){
            if(counter2 == 4)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(year , tempYear, counter , counter2, it);
        }
        else if(counter2 < 8){
            if(counter2 == 6)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(genre , tempGenre, counter , counter2, it);
            if(counter2 == 8){
                counter2 = 0;
                counter = 0;
            } 
        }
    }
    return Music(title , artist , year , genre); 
}

Movie Operations::MovieCatalogActive() { // extract movie object to title director year genre and starring
    vector<string> Whole_Data_Txt = return_Whole_DataTxt();
    vector<string> title;
    vector<string> tempTitle;
    vector<string> director;
    vector<string> tempDirector;
    vector<string> year;
    vector<string> tempYear;
    vector<string> genre;
    vector<string> tempGenre;
    vector<string> starring;
    vector<string> tempStarring;
    int counter = 0; // count of "" number
    int counter2 = 0;
    for(vector<string>::iterator it = Whole_Data_Txt.begin() ; it != Whole_Data_Txt.end(); ++it){
        if(counter2 < 2)
            FindFirstQuotationtoLastQuatotion(title , tempTitle,counter , counter2, it);
        else if(counter2 < 4) {
            if(counter2 == 2)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(director , tempDirector,counter , counter2, it);
        }
        else if(counter2 < 6) {
            if(counter2 == 4)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(year , tempYear,counter , counter2, it);
        }
        else if(counter2 < 8) {
            if(counter2 == 6)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(genre , tempGenre,counter , counter2, it);
        }
        else if(counter2 < 10) {
            if(counter2 == 8)
                counter = 0;
            FindFirstQuotationtoLastQuatotion(starring , tempStarring,counter , counter2 , it);
            if(counter2 == 10) {
                counter = 0;
                counter2 = 0;
            }
        }
    }
    return Movie(title , director , year , genre , starring);
}

void PushExceptionForMovieToVector(vector<string>& vec , Movie obj , int counter) { // fold output.txt vector with object index
    vec.push_back(obj.getTitle()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getDirector()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getYear()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getGenre()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getStarring()[counter]);
    vec.push_back("\n");
}

void PushExceptionForBookToVector(vector<string>& vec , Book obj , int counter) { // fold output.txt vector with object index
    vec.push_back(obj.getTitle()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getAuthor()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getYear()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getTag()[counter]);
    vec.push_back("\n");
}

void PushExceptionForMusicToVector(vector<string>& vec , Music obj , int counter) { // fold output.txt vector with object index
    vec.push_back(obj.getTitle()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getArtist()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getYear()[counter]);
    vec.push_back(" ");
    vec.push_back(obj.getGenre()[counter]);
    vec.push_back("\n");
}

void MovieSearchCommand(vector<string> & vec , vector<string> searchThings , Movie obj) {
    searchThings[0].erase(searchThings[0].begin());
    searchThings[0].erase(searchThings[0].size() - 1);
    if(searchThings[1].compare("\"title\"") == 0) { // if command is title active here
        for(int i = 0 ; i < obj.getTitle().size() ; i++) {
            if(obj.getTitle()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in title\n");
                PushExceptionForMovieToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"director\"") == 0) { // if command is director active here
        for(int i = 0 ; i < obj.getDirector().size() ; i++) {
            if(obj.getDirector()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in director\n");
                PushExceptionForMovieToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"year\"") == 0) { // if command is year active here
        for(int i = 0 ; i < obj.getYear().size() ; i++) {
            if(obj.getYear()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in year\n");
                PushExceptionForMovieToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"genre\"") == 0) { // if command is genre active here
        for(int i = 0 ; i < obj.getGenre().size() ; i++) {
            if(obj.getGenre()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in genre\n");
                PushExceptionForMovieToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"starring\"") == 0) { // if command is starring active here
        for(int i = 0 ; i < obj.getStarring().size() ; i++) {
            if(obj.getStarring()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in starring\n");
                PushExceptionForMovieToVector(vec , obj , i);
            }
        }
    }
}

void BookSearchCommand(vector<string> & vec , vector<string> searchThings , Book obj) {
    searchThings[0].erase(searchThings[0].begin());
    searchThings[0].erase(searchThings[0].size() - 1);
    if(searchThings[1].compare("\"title\"") == 0) { // if command is title active here
        for(int i = 0 ; i < obj.getTitle().size() ; i++) { 
            if(obj.getTitle()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in title\n");
                PushExceptionForBookToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"author\"") == 0) { // if command is author active here
        for(int i = 0 ; i < obj.getAuthor().size() ; i++) {
            if(obj.getAuthor()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in author\n");
                PushExceptionForBookToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"year\"") == 0) { // if command is year active here
        for(int i = 0 ; i < obj.getYear().size() ; i++) {
            if(obj.getYear()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in year\n");
                PushExceptionForBookToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"tag\"") == 0) { // if command is tag active here
        for(int i = 0 ; i < obj.getTag().size() ; i++) {
            if(obj.getTag()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in tag\n");
                PushExceptionForBookToVector(vec , obj , i);
            }
        }
    }
}

void MusicSearchCommand(vector<string> & vec , vector<string> searchThings , Music obj) {
    searchThings[0].erase(searchThings[0].begin());
    searchThings[0].erase(searchThings[0].size() - 1);
    if(searchThings[1].compare("\"title\"") == 0) { // if command is title active here
        for(int i = 0 ; i < obj.getTitle().size() ; i++) {
            if(obj.getTitle()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in title\n");
                PushExceptionForMusicToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"artist\"") == 0) { // if command is artist active here
        for(int i = 0 ; i < obj.getArtist().size() ; i++) {
            if(obj.getArtist()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in artist\n");
                PushExceptionForMusicToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"year\"") == 0) { // if command is year active here
        for(int i = 0 ; i < obj.getYear().size() ; i++) {
            if(obj.getYear()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in year\n");
                PushExceptionForMusicToVector(vec , obj , i);
            }
        }
    }
    else if(searchThings[1].compare("\"genre\"") == 0) { // if command is genre active here
        for(int i = 0 ; i < obj.getGenre().size() ; i++) {
            if(obj.getGenre()[i].find(searchThings[0]) != string::npos) { // find function try to find sub-string in main string
                vec.push_back("search ");
                vec.push_back(searchThings[0]);
                vec.push_back(" in genre\n");
                PushExceptionForMusicToVector(vec , obj , i);
            }
        }
    }
}

void CopyVectorForBook(vector<string> &vec , vector<string> copyVector ,  vector<int> QueueOfIndex , Book obj) {
    for(int x = 0 ; x < copyVector.size() ; x++) {   //folds copyvector in sort function with necesarry things
        vec.push_back(obj.getTitle()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getAuthor()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getYear()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getTag()[QueueOfIndex[x]]);
        vec.push_back("\n");
        }
}

void BookSortCommand(vector<string> & vec , string sortThing , Book obj) { // sorts book objects
    vec.push_back("sort ");
    vec.push_back(sortThing);
    vec.push_back("\n");
    list<string> copyList;
    vector<string> copyVector;
    vector<int> QueueOfIndex;
    if(sortThing.compare("\"title\"") == 0) {
        for(int i = 0 ; i < obj.getTitle().size() ; i++) { // equalize vector with list
            copyList.push_back(obj.getTitle()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getTitle()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForBook(vec ,copyVector ,QueueOfIndex ,obj);
    }
    else if(sortThing.compare("\"author\"") == 0) { // equalize vector with list
        for(int i = 0 ; i < obj.getAuthor().size() ; i++) {
            copyList.push_back(obj.getAuthor()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getAuthor()[j]) == 0) { 
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForBook(vec ,copyVector ,QueueOfIndex ,obj);
    }
    else if(sortThing.compare("\"year\"") == 0) { // equalize vector with list
        for(int i = 0 ; i < obj.getYear().size() ; i++) {
            copyList.push_back(obj.getYear()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getYear()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForBook(vec ,copyVector ,QueueOfIndex ,obj);
    }
    if(sortThing.compare("\"tag\"") == 0) { // equalize vector with list
        for(int i = 0 ; i < obj.getTag().size() ; i++) {
            copyList.push_back(obj.getTag()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getTag()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForBook(vec ,copyVector ,QueueOfIndex ,obj);
    }
}

void CopyVectorForMusic(vector<string> &vec , vector<string> copyVector ,  vector<int> QueueOfIndex , Music obj) {
    for(int x = 0 ; x < copyVector.size() ; x++) {   //folds copyvector in sort function with right queue
        vec.push_back(obj.getTitle()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getArtist()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getYear()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getGenre()[QueueOfIndex[x]]);
        vec.push_back("\n");
    }
}

void MusicSortCommand(vector<string> & vec , string sortThing , Music obj) {
    vec.push_back("sort ");
    vec.push_back(sortThing);
    vec.push_back("\n");
    list<string> copyList;
    vector<string> copyVector;
    vector<int> QueueOfIndex;
    if(sortThing.compare("\"title\"") == 0) { // equalize vector with list
        for(int i = 0 ; i < obj.getTitle().size() ; i++) {
            copyList.push_back(obj.getTitle()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getTitle()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForMusic(vec ,copyVector ,QueueOfIndex ,obj);
    }
    else if(sortThing.compare("\"artist\"") == 0) { // equalize vector with list
        for(int i = 0 ; i < obj.getArtist().size() ; i++) {
            copyList.push_back(obj.getArtist()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getArtist()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForMusic(vec ,copyVector ,QueueOfIndex ,obj);
    }
    else if(sortThing.compare("\"year\"") == 0){ // equalize vector with list
        for(int i = 0 ; i < obj.getYear().size() ; i++) {
            copyList.push_back(obj.getYear()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getYear()[j]) == 0) {
                    QueueOfIndex.push_back(j);  // find queue of object elements
                }
            }
        }
        CopyVectorForMusic(vec ,copyVector ,QueueOfIndex ,obj);
    }
    if(sortThing.compare("\"genre\"") == 0){ // equalize vector with list
        for(int i = 0 ; i < obj.getGenre().size() ; i++) {
            copyList.push_back(obj.getGenre()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getGenre()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
    	CopyVectorForMusic(vec ,copyVector ,QueueOfIndex ,obj);
    }
}

void CopyVectorForMovie(vector<string> &vec , vector<string> copyVector ,  vector<int> QueueOfIndex , Movie obj) {
    for(int x = 0 ; x < copyVector.size() ; x++) {   //folds copyvector in sort function with right queue
        vec.push_back(obj.getTitle()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getDirector()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getYear()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getGenre()[QueueOfIndex[x]]);
        vec.push_back(" ");
        vec.push_back(obj.getStarring()[QueueOfIndex[x]]);
        vec.push_back("\n");
    }
}

void MovieSortCommand(vector<string> & vec , string sortThing , Movie obj) {
    vec.push_back("sort ");
    vec.push_back(sortThing);
    vec.push_back("\n");
    list<string> copyList;
    vector<string> copyVector;
    vector<int> QueueOfIndex;
    if(sortThing.compare("\"title\"") == 0){ // equalize vector with list
        for(int i = 0 ; i < obj.getTitle().size() ; i++) {
            copyList.push_back(obj.getTitle()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getTitle()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForMovie(vec , copyVector ,  QueueOfIndex , obj);
    }
    else if(sortThing.compare("\"director\"") == 0) { // equalize vector with list
        for(int i = 0 ; i < obj.getDirector().size() ; i++) {
            copyList.push_back(obj.getDirector()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getDirector()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForMovie(vec , copyVector ,  QueueOfIndex , obj);
    }
    else if(sortThing.compare("\"year\"") == 0){ // equalize vector with list
        for(int i = 0 ; i < obj.getYear().size() ; i++) {
            copyList.push_back(obj.getYear()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getYear()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForMovie(vec , copyVector ,  QueueOfIndex , obj);
    }
    if(sortThing.compare("\"genre\"") == 0) { // equalize vector with list
        for(int i = 0 ; i < obj.getGenre().size() ; i++) {
            copyList.push_back(obj.getGenre()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getGenre()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForMovie(vec , copyVector ,  QueueOfIndex , obj);
    }
    if(sortThing.compare("\"starring\"") == 0) { // equalize vector with list
        for(int i = 0 ; i < obj.getStarring().size() ; i++) {
            copyList.push_back(obj.getStarring()[i]);
        }
        copyList.sort(); // sortlist with using sort() function
        for (auto v : copyList)
            copyVector.push_back(v); // again fold vector with sorted list
        for(int i = 0 ; i < copyVector.size() ; i++) {
            for(int j = 0 ; j < copyVector.size() ; j++) {
                if(copyVector[i].compare(obj.getStarring()[j]) == 0) {
                    QueueOfIndex.push_back(j); // find queue of object elements
                }
            }
        }
        CopyVectorForMovie(vec , copyVector ,  QueueOfIndex , obj);
    }
}

void Operations::MovieCommandFounder( Movie obj , vector<string> command) {
    vector<string> vector_outputTxt;
    vector_outputTxt.push_back("Catalog Read: ");
    vector_outputTxt.push_back("movie");
    vector_outputTxt.push_back("\n");
    vector<string> uniqueTitles , uniqueDirector , uniqueYear , uniqueGenre , uniqueStarring;
    vector<string> main = obj.getTitle();
    int counter = 0 , counter2 = 0;
    for (int j = 0; j < main.size(); j++)
    {
        counter2 = 0;
        counter++;
        for (int i = j+1; i < main.size(); i++)
        {
            try{
                if(obj.getTitle()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getDirector()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getYear()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getGenre()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getStarring()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if (main[j].compare(main[i]) == 0) // looks for duplication
                {
                    throw (counter - 1);
                }
            }
            catch (char j){ // catch for missing field
            int i = (int)j;
            vector_outputTxt.push_back("Exception: Missing Field");
            vector_outputTxt.push_back("\n");
            PushExceptionForMovieToVector(vector_outputTxt , obj , i);
            counter2++;
            break;
            }
            catch(int counter){ // catch for duplication
                vector_outputTxt.push_back("Exception: duplicate entry");
                vector_outputTxt.push_back("\n");
                PushExceptionForMovieToVector(vector_outputTxt , obj , counter);
                counter2++;
                break;
            }
        }
        if(counter2 == 0) {
            uniqueTitles.push_back(obj.getTitle()[j]);
            uniqueDirector.push_back(obj.getDirector()[j]);
            uniqueYear.push_back(obj.getYear()[j]);
            uniqueGenre.push_back(obj.getGenre()[j]);
            uniqueStarring.push_back(obj.getStarring()[j]);
        }
    }
    Movie uniqueObj(uniqueTitles , uniqueDirector , uniqueYear , uniqueGenre , uniqueStarring);
    string uniq = to_string(uniqueTitles.size());
    vector_outputTxt.push_back(uniq);
    vector_outputTxt.push_back(" unique entries\n");
    for(int i = 0 ; i < command.size() ; i++) {
        if(command[i].compare("search") == 0) {
            vector<string> searchThings;
            i++;
            searchThings.push_back(command[i]);
            i+=2;
            try{ // try for correctness of commands
                if(command[i].compare("\"title\"") == 0 || command[i].compare("\"director\"") == 0 || command[i].compare("\"year\"") == 0 || command[i].compare("\"genre\"") == 0 || command[i].compare("\"starring\"") == 0){
                    searchThings.push_back(command[i]);
                    MovieSearchCommand(vector_outputTxt , searchThings , uniqueObj);
                }
                else
                    throw i;
            }
            catch (int i){ // catchs every wrong command exception
                vector_outputTxt.push_back("Exception: Wrong Command\n");
                vector_outputTxt.push_back("search ");
                vector_outputTxt.push_back(command[i-2]);
                vector_outputTxt.push_back(" in ");
                vector_outputTxt.push_back(command[i]);
                vector_outputTxt.push_back("\n");
                i++;
            }
        }
        else if(command[i].compare("sort") == 0) {
            string sortThing;
            i++;
            try { // try for commands
                if(command[i].compare("\"title\"") == 0 || command[i].compare("\"director\"") == 0 || command[i].compare("\"year\"") == 0 || command[i].compare("\"genre\"") == 0 || command[i].compare("\"starring\"") == 0){
                    sortThing.append(command[i]);
                    MovieSortCommand(vector_outputTxt , sortThing , uniqueObj);
                }
                else
                    throw i;
            }
            catch (int i) { // catches every wrong command exceptions
                vector_outputTxt.push_back("Exception: Wrong Command\n");
                vector_outputTxt.push_back("sort ");
                vector_outputTxt.push_back(command[i]);
                vector_outputTxt.push_back("\n");
                i++;
            }
        }
    }
    fstream outStr;
    outStr.open("output.txt", std::ios::out); // writes to output.txt file
    for (int i = 0; i < vector_outputTxt.size(); i++)
        outStr << vector_outputTxt[i];
    outStr.close();
}

void Operations::BookCommandFounder(Book obj , vector<string> command){
    vector<string> vector_outputTxt;
    vector_outputTxt.push_back("Catalog Read: ");
    vector_outputTxt.push_back("book");
    vector_outputTxt.push_back("\n");
    vector<string> uniqueTitles , uniqueAuthor , uniqueYear , uniqueTag;
    vector<string> main = obj.getTitle();
    int counter = 0 , counter2 = 0;
    for (int j = 0; j < main.size(); j++)
    {
        counter2 = 0;
        counter++;
        for (int i = j+1; i < main.size(); i++)
        {
            try{
                if(obj.getTitle()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getAuthor()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getYear()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getTag()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if (main[j].compare(main[i]) == 0) // looks for duplication
                {
                    throw (counter - 1);
                }
            }
            catch (char j){ // catches missing field
	            int i = (int)j;
	            vector_outputTxt.push_back("Exception: Missing Field");
	            vector_outputTxt.push_back("\n");
	            PushExceptionForBookToVector(vector_outputTxt , obj , i);
	            counter2++;
	            break;
            }
            catch(int counter){ // catches duplication
                vector_outputTxt.push_back("Exception: duplicate entry");
                vector_outputTxt.push_back("\n");
                PushExceptionForBookToVector(vector_outputTxt , obj , counter);
                counter2++;
                break;
            }
        }
        if(counter2 == 0) {
            uniqueTitles.push_back(obj.getTitle()[j]);
            uniqueAuthor.push_back(obj.getAuthor()[j]);
            uniqueYear.push_back(obj.getYear()[j]);
            uniqueTag.push_back(obj.getTag()[j]);
        }
    }
    Book uniqueObj(uniqueTitles , uniqueAuthor , uniqueYear , uniqueTag);
    string uniq = to_string(uniqueTitles.size());
    vector_outputTxt.push_back(uniq);
    vector_outputTxt.push_back(" unique entries\n");
    for(int i = 0 ; i < command.size() ; i++){
        if(command[i].compare("search") == 0){
            vector<string> searchThings;
            i++;
            searchThings.push_back(command[i]);
            i+=2;
            try{ // looks for command exceptions
                if(command[i].compare("\"title\"") == 0 || command[i].compare("\"author\"") == 0 || command[i].compare("\"year\"") == 0 || command[i].compare("\"tag\"") == 0){
                    searchThings.push_back(command[i]);
                    BookSearchCommand(vector_outputTxt , searchThings , uniqueObj);
                }
                else
                    throw i;
            }
            catch (int i){ // catches every command mistakes
                vector_outputTxt.push_back("Exception: Wrong Command\n");
                vector_outputTxt.push_back("search ");
                vector_outputTxt.push_back(command[i-2]);
                vector_outputTxt.push_back(" in ");
                vector_outputTxt.push_back(command[i]);
                vector_outputTxt.push_back("\n");
                i++;
            }
        }
        else if(command[i].compare("sort") == 0) {
            string sortThing;
            i++;
            try{ // looks for command exception
                if(command[i].compare("\"title\"") == 0 || command[i].compare("\"author\"") == 0 || command[i].compare("\"year\"") == 0 || command[i].compare("\"tag\"") == 0){
                    sortThing.append(command[i]);
                    BookSortCommand(vector_outputTxt , sortThing , uniqueObj);
                }
                else
                    throw i;
            }
            catch (int i){ // catches every command exception
                vector_outputTxt.push_back("Exception: Wrong Command\n");
                vector_outputTxt.push_back("sort ");
                vector_outputTxt.push_back(command[i]);
                vector_outputTxt.push_back("\n");
                i++;
            }
        }

    }
    fstream outStr;
    outStr.open("output.txt", std::ios::out); // writes to output.txt
    for (int i = 0; i < vector_outputTxt.size(); i++)
        outStr << vector_outputTxt[i];
    outStr.close();
}

void Operations::MusicCommandFounder(Music obj , vector<string> command){
    vector<string> vector_outputTxt;
    vector_outputTxt.push_back("Catalog Read: ");
    vector_outputTxt.push_back("music");
    vector_outputTxt.push_back("\n");
    vector<string> uniqueTitles , uniqueArtist , uniqueYear , uniqueGenre;
    vector<string> main = obj.getTitle();
    int counter = 0 , counter2 = 0;
    for (int j = 0; j < main.size(); j++)
    {
        counter2 = 0;
        counter++;
        for (int i = j+1; i < main.size(); i++)
        {
            try{
                if(obj.getTitle()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getArtist()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getYear()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if(obj.getGenre()[j].compare("\"\"") == 0){ // looks for missing field
                    throw (char)j;
                }
                if (main[j].compare(main[i]) == 0) // looks for duplication
                {
                    throw (counter - 1);
                }
            }
            catch (char j){ // catches missing field
	            int i = (int)j;
	            vector_outputTxt.push_back("Exception: Missing Field");
	            vector_outputTxt.push_back("\n");
	            PushExceptionForMusicToVector(vector_outputTxt , obj , i);
	            counter2++;
	            break;
            }
            catch(int counter){ // catches duplication
                vector_outputTxt.push_back("Exception: duplicate entry");
                vector_outputTxt.push_back("\n");
                PushExceptionForMusicToVector(vector_outputTxt , obj , counter);
                counter2++;
                break;
            }
        }
        if(counter2 == 0){
            uniqueTitles.push_back(obj.getTitle()[j]);
            uniqueArtist.push_back(obj.getArtist()[j]);
            uniqueYear.push_back(obj.getYear()[j]);
            uniqueGenre.push_back(obj.getGenre()[j]);
        }
    }
    Music uniqueObj(uniqueTitles , uniqueArtist , uniqueYear , uniqueGenre);
    string uniq = to_string(uniqueTitles.size());
    vector_outputTxt.push_back(uniq);
    vector_outputTxt.push_back(" unique entries\n");
   
    for(int i = 0 ; i < command.size() ; i++) {
        if(command[i].compare("search") == 0) {
            vector<string> searchThings;
            i++;
            searchThings.push_back(command[i]);
            i+=2;
            try{ // looks for command exception
                if(command[i].compare("\"title\"") == 0 || command[i].compare("\"artist\"") == 0 || command[i].compare("\"year\"") == 0 || command[i].compare("\"genre\"") == 0){
                    searchThings.push_back(command[i]);
                    MusicSearchCommand(vector_outputTxt , searchThings , uniqueObj);
                }
                else
                    throw i;
            }
            catch (int i){ // catches every command exception
                vector_outputTxt.push_back("Exception: Wrong Command\n");
                vector_outputTxt.push_back("search ");
                vector_outputTxt.push_back(command[i-2]);
                vector_outputTxt.push_back(" in ");
                vector_outputTxt.push_back(command[i]);
                vector_outputTxt.push_back("\n");
                i++;
            }
        }
        else if(command[i].compare("sort") == 0) {
            string sortThing;
            i++;
            try{ // looks for command exception
                if(command[i].compare("\"title\"") == 0 || command[i].compare("\"artist\"") == 0 || command[i].compare("\"year\"") == 0 || command[i].compare("\"genre\"") == 0){
                    sortThing.append(command[i]);
                    MusicSortCommand(vector_outputTxt , sortThing , uniqueObj);
                }
                else
                    throw i;
            }
            catch (int i){ // catches every command exception
                vector_outputTxt.push_back("Exception: Wrong Command\n");
                vector_outputTxt.push_back("sort ");
                vector_outputTxt.push_back(command[i]);
                vector_outputTxt.push_back("\n");
                i++;
            }
        }
    }
    fstream outStr; // fold output.txt
    outStr.open("output.txt", std::ios::out);
    for (int i = 0; i < vector_outputTxt.size(); i++)
        outStr << vector_outputTxt[i];
    outStr.close();
}

int main() {
    vector<string> Whole_Data_Txt = return_Whole_DataTxt();
    vector<string> Whole_Command_Txt = return_Whole_CommandTxt();
    vector<string>::iterator it = Whole_Data_Txt.begin();
    Book book;
    Music music;
    Movie movie;
    Operations op;
    if(*it == "book") {
         book = op.BookCatalogActive();
         op.BookCommandFounder(book , Whole_Command_Txt);
    }
    else if(*it == "music") {
         music = op.MusicCatalogActive();
         op.MusicCommandFounder(music , Whole_Command_Txt);
    }
    else if(*it == "movie") {
         movie = op.MovieCatalogActive();
         op.MovieCommandFounder(movie , Whole_Command_Txt);
    } 
    return 0;
}
