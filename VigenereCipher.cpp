/* Vigenere Cipher Program
*  PROGRAM ONLY ACCEPTS UPPERCASE MESSAGES AND KEYWORD WITHOUT SPACES OR SYMBOLS
*  EXAMPLE TEST RUN- 
*  PLAINTEXT MESSAGE: HELLO
*  WITH KEYWORD: BLUE
*  PRODUCES CIPHER TEXT: IPFPP
* 
* PROGRAM WILL NOT ACCEPT MESSAGES AND KEYWORDS THAT MIXES UPPERCASE AND LOWERCASE LIKE:
* Hello for plaintext and Blue for keyword
* SYMBOLS AND SPACES ARE ALSO NOT ALLOWED:
* NO MESSAGES LIKE: HELLO HELLO! or Hello!hello?
* MESSAGE MUST BE ENTERED WITHOUT SPACES AND WITHOUT SYMBOLS: 
* EXAMPLE: HELLOMYNAMEIS would work
*/
#include <iostream>
#include <string>
using namespace std;

/* VIGENERE FUNCTION PROTOTYPE: Passes in user's plaintext, key-word and 
* and bool value. Bool value indicates if function should encode or decode 
* the users message depending on their input                         */
string vigenere(string text, string key, bool decode);

int main() {
    char choice;        // User's choice from menu
    bool decode;        // Input: Encode or decode 
    string plainText;   // User's plaintext message
    string keyWord;     // User's keyword 
    string cipherText;  // Ciphertext 
    char c;             // User's choice to continue after encrpytion/decryption

    // Message explaining to user the parameters and limitations of program
    cout<<"\nPROGRAM ONLY ACCEPTS UPPERCASE ALPHABETICAL CHARACTERS (A-Z): "<<endl;
    cout<<"NO SPACES OR SYMBOLS."<<endl;
    cout<<"\nPLEASE ONLY ENTER UPPERCASE MESSAGES AND KEYWORD"<<endl;
    cout<<"WITHOUT SPACES OR SYMBOLS!"<<endl;
    
    do{ 
        int choice; // User's choice from menu

        cout<<"\nChoose from the menu: "<<endl; // Menu
        cout<<"-------------------------"<<endl;
        cout<<"1: Encrypt"<<endl;
        cout<<"2: Decrypt"<<endl;
        cout<<"3: TERMINATE PROGRAM "<<endl;
        
        cin>>choice;  // Input
        cin.ignore();
        
        switch(choice){   // Switch case for encrypting or decrypting 
           
            case 1:         // CASE 1 is for encrypting plaintext
                decode=0;   // Decode is false 
                cout<<"\nEnter message to encrypt: ";
                getline(cin,plainText);
               
                cout<<"Enter key-word: "; // Get key word
                getline(cin,keyWord);

                // Assign function call to cipherText variable 
                // Pass in plaintext, keyword and decode
                cipherText= vigenere(plainText, keyWord, decode); 
                cout<<"\nThe ciphertext is: "<<cipherText<<endl;  // Display cipherText
                
                cout<<"\nContinue Y/N ? "; // Continue program after initial choice 
                cin>>c;                    // Input user's choice 
                c=toupper(c); // Make c uppercase
            break;
            
            case 2:       // CASE 2 is for decrypting ciphertext
                decode =1; // Decode is true
                cout<<"\nEnter ciphertext to decrypt: ";
                getline(cin,cipherText);
                
                cout<<"Enter key-word used: "; // Get key word
                getline(cin,keyWord);

                // Assign function call to plaintext variable 
                // Pass in the ciphertext, keyword and bool value 
                plainText= vigenere(cipherText, keyWord, decode);
                cout<<"The plaintext is: "<<plainText<<endl; // Display plaintext
                 
                cout<<"\nContinue Y/N: ? "; // User's choice to continue
                cin>>c;                     // Input
                c=toupper(c);               // Make c uppercase
            break;
            
            case 3 :    // CASE 3 is for exiting program
                cout<<"\nEXITING PROGRAM! THANK YOU!"<<endl;
                c='N';
            break;
        }
    }while (c == 'Y' && choice != 3); // while user input is Y and not 3

return 0;
}

/* VIGENERE FUNCTION implementing algorithm to produce encrpyted ciphertext
* and decrypted plaintext. It uses modular arithmetic and ASCII values to
* encrypt and decrypt. It cannot encrypt/decrypt message unless they are 
* all in uppercase without spaces nor symbols. Keyword must also be uppercase */
string vigenere(string text, string key, bool decode){
    
    string newKey = key; // Assign newKey to the user's key, which is passed in as function parameter
    string newText;   // newText will hold either ciphertext or plaintext depending on user's input 

    // While loop that assures the length of the new key will be the same length as the users message 
    // newKey should repeat until it is the same length as the user's message
    while( newKey.length() < text.length() ){
        newKey+=key;
    }
        if(decode == 0){                       // Decode is false
            for(int i=0; i<text.length(); i++){ 
            // newText will be cihpertext. Add the values of the index of the original text and keyword and 
            // compute modular arithmetic value at each index and store that value in each index of newText
            // add 65 or 'A' to bring into range of capital letter ascii values.
                newText += (text[i] + newKey[i])%26 +'A';
            }
        }
        else{  // when decode is true
             for(int i=0; i<text.length(); i++){
                // newText will be plaintext. Subtract the values of the index of the entered text and keyword
                // and add 26 to bring it into the correct range. Compute modular aritmetic value at each index 
                // then add 65 or 'A' to bring it into the range of the capital letter asciii values
                newText+= (text[i] - newKey[i] +26 )%26 +'A';
            }
        }
    
return newText; // Function returns either ciphertext or plaintext depending on user's input
}