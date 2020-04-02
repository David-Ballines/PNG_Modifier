#include <iostream>
#include <stdlib.h>
#include "Image.h"

int main(){
    Image current;
    string file;
    cout << "Write the file name you want to alter"<<endl;
    cin >> file;
    current.readFromFile(file);

    int functions;
    bool quit = false;
    double amount = 0;

    while(!quit){
        cout << "What would you like to do."<< endl;
        cout << "1. Rotate 90 degrees clockwise" <<endl << "2. Rotate 90 degrees counter clockwise";
        cout << endl << "3. Rotate 180 degrees" << endl << "4. Reflect horizontally" <<endl;
        cout << "5. Reflect vertically"<< endl <<"6. Grayscale" << endl << "7. Rotate colors" << endl;
        cout << "8. Scale the image" <<endl<< "9. Dersaturate" << endl;
        cout << "10. Lighten" << endl << "11. Darken" <<endl;
        cout << "12. Saturate" <<endl <<"13. Choose a different image" << endl << "14. Quit"<<endl;
        cin >> functions;

        if((functions > 8) && (functions < 13)){
                cout << "What amount, between 0-1, would you like to change the image?" <<endl;
                cin >> amount;
        }

        switch(functions){
                case 1 : {
                        current.rotateClockwise();
                        break;
                }
                case 2 : {
                        current.rotateCounterClock();
                        break;
                }
                case 3 : {
                        current.rotate180();
                        break;
                }
                case 4 : {
                        current.reflectHorizontal();
                        break;
                }
                case 5 : {
                        current.reflectVertical();
                        break;
                }
                case 6 : {
                        current.grayscale();
                        break;
                }
                case 7 : {
                        cout<< "Choose an integer between 0-360 to rotate the color"<<endl;
                        cin >> amount;
                        current.rotateColor(amount);
                        break;
                }
                case 8 : {
                        cout<<"By what factor would you like to scale the image"<<endl;
                        cin>>amount;
                        current.scale(amount);
                        break;
                }
                case 9 : {
                        current.desaturate(amount);
                        break;
                }
                case 10 : {
                        current.lighten(amount);
                        break;
                }
                case 11 : {
                        current.darken(amount);
                        break;
                }
                case 12 : {
                        current.saturate(amount);
                        break;
                }
                case 13 : {
                        current.writeToFile("new_" + file);
                        cout << "What is the new file you want to modify?"<<endl;
                        cin >> file;
                        current.readFromFile(file);
                        break;
                }
                case 14 : {
                        quit = true;
                        break;
                }
        }
     }

    current.writeToFile("new_" + file);

    return 0;
}