// THIS IS THE DRIVER FUNCTION

#include <iostream>
#include "TruePatricianMusic.h"
using namespace std;

void mainMenu();

int main()
{
    srand((int)time(NULL));
    Genre muLibrary;
    muLibrary.initializeLibrary("mu.txt");
    string option = " ";
    while(option!="11"){
        option.erase();
        int invalid = 0;
        while(option!="1"&&option!="2"&&option!="3"&&option!="4"&&option!="5"&&option!="6"&&option!="7"&&option!="8"&&option!="9"&&option!="10"&&option!="11"){
            if(invalid>0){
                cout<<"Invalid Input"<<endl;
            }
            mainMenu();
            getline(cin,option);
            invalid++;
        }
        if(option=="1"){
            string album1, album2, album3;
            int ratingTotal = 0;
            cout<<"Why hello! I hope you are having a gr8 day m8! We have devised a flawless algorithm to determine your taste!"<<endl;
            cout<<"I am going to ask you to enter your three favorite albums!"<<endl;
            cout<<"1st: ";
            getline(cin,album1);
            cout<<"2nd: ";
            getline(cin,album2);
            cout<<"3rd: ";
            getline(cin,album3);
            ratingTotal+=muLibrary.rateMyTaste(album1);
            ratingTotal+=muLibrary.rateMyTaste(album2);
            ratingTotal+=muLibrary.rateMyTaste(album3);
            ratingTotal=ratingTotal/3;
            if(ratingTotal>89){
                cout<<"Congratulations on your true patrician taste!"<<endl;
            }
            else{
                cout<<"REEEEEEEEE! I apologize, but you do not have true patrician taste. :c"<<endl;
            }

        }
        else if(option=="2"){
            cout<<"Cool beans. What album you want to get something similar to??"<<endl;
            string album;
            getline(cin,album);
            muLibrary.recommend(album);
        }
        else if(option=="3"){
            cout<<"Brilliant, we love getting you hooked on some sweet tunes!"<<endl;
            muLibrary.printGenres();
            string genre;
            getline(cin,genre);
            muLibrary.genreRecommend(genre);
        }
        else if(option=="4"){
            cout<<"Hey, don't worry 'lil buddy / 'lil gal / 'lil friend! We got you covered! :D!"<<endl;
            muLibrary.patricianize();
        }
        else if(option=="5"){
            cout<<"Welly well, we have a nifty algo for that!"<<endl;
            muLibrary.GOAT();
        }
        if(option=="6"){
            string artist, album, genre, rating;
            int ratingInt;
            cout<<"Okay. Cool. Well first off, what band/artist are you adding?"<<endl;
            getline(cin,artist);
            cout<<"What is the album you want to put in?"<<endl;
            getline(cin,album);
            cout<<"Cool, cool. Our system is #/100 for ratings. Go to pitchfork, get that rating, and multiply it by 10 to get rid of that decimal."<<endl;
            getline(cin,rating);
            ratingInt=atoi(rating.c_str());
            cout<<"Last question, pick a genre, be specific. Either pick from this list, or if none fit, include another."<<endl;
            muLibrary.printGenres();
            getline(cin,genre);
            muLibrary.addAlbumNode(artist,album,ratingInt,genre);
            cout<<"k"<<endl;
        }
        else if(option=="7"){
            cout<<"\nThis suggestion is only for those with incomes >= 60k/year\n";
            cout<<"Enter your gross adjusted income per year:\n";
            string incomes = "";
            getline(cin, incomes);
            int income = atoi(incomes.c_str());
            if(income < 60000){
                cout<<"\nWe're very sorry, but pl3bs aren't welcome here.\n\n";
            }
            else{
                cout<<"\nWelcome, sir.\n";
                cout<<"May we suggest "<<muLibrary.patricianSuggestion()<<"?"<<endl<<"And as always, thank you for choosing Patrician Music Suggestions for your recomendation needs."<<endl<<endl;
            }
        }
        else if(option=="8"){
            string out = muLibrary.randomSuggestion();
            cout<<"\nWe randomly suggest "<<out<<endl<<endl;
        }
        else if(option=="9"){
            string out = muLibrary.badSuggestion();
            cout<<"\nThis suggestion gauranteed to keep your mind un-blown!\nDon't worry about nasty head explosions m8.\n";
            cout<<"Our poor suggestion is "<<out<<endl<<endl;
        }
        else if(option=="10"){
            muLibrary.printLibrary();
        }
    }
    cout<<"lol"<<endl;
}

void mainMenu(){
    cout<<"======/mu/ menu lol======="<<endl;
    cout<<"1. R8 my taste!"<<endl;
    cout<<"2. Recommend me some tunes pls"<<endl;
    cout<<"3. Give me everything on a genre!"<<endl;
    cout<<"4. I want to be patrician too! :c"<<endl;
    cout<<"5. Who are, without dispute, the greatest of all time?"<<endl;
    cout<<"6. Add music to the library"<<endl;
    cout<<"7. True patrician suggestion"<<endl;
    cout<<"8. Random suggestion plox"<<endl;
    cout<<"9. Bad suggestion"<<endl;
    cout<<"10. View the /mu/ library"<<endl;
    cout<<"11. GET OFF THE BOARD"<<endl;
}
