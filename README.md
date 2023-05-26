# CIS7 Course Project 
# Professor Nguyen
# Vigenère Cipher C++ Implementation
Published on May 26, 2023 by Noel Perez

https://github.com/Computer-PsiPhi/CIS7.CourseProject.Prof-Nguyen

* The [Vigenère Cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher) is a slightly more complex version of the [Caesar Cipher](https://en.wikipedia.org/wiki/Caesar_cipher), where instead of rotating plaintext by a single letter, Vigenère allows rotation of a key-word. 

* The Vigenère Cipher is a method of encrypting alphabetic text. It uses a simple form of polyalphabetic substitution. A polyalphabetic cipher is any cipher based on substitution, using multiple substitution alphabets .The encryption of the original text is done using the Vigenère square or Vigenère table.
The table consists of the alphabets written out 26 times in different rows, each alphabet shifted cyclically to the left compared to the previous alphabet, corresponding to the 26 possible Caesar Ciphers.
At different points in the encryption process, the cipher uses a different alphabet from one of the rows.
The alphabet used at each point depends on a repeating keyword.

## Implementation of encryption and decryption using the Vigenère algorithm




### 
- #### `input` - 
- #### `output` - 
- #### `keyword` - mandatory string used for calculating the position in the alphabet, this value is needed to perform both the encryption and decryption - . ``

---


## How does it work ?
### Encryption and Decryption
#### To encrypt a character the position of the sign is evaluated based on the current key character and current word character
![Vigenere](https://pages.mtu.edu/~shene/NSF-4/Tutorial/VIG/FIG-VIG-Table-EX-M.jpg)
#### In the example above you can see that we treat both word string indices as a position of a character. In this case, the index of `M`, and its ascii value of 77 and index of `H` and its ascii value of 72 are added together. This produces a total of 149. To compute the correct results we perform the following modular arithmetic:  (77+72)mod26 which is the same as 149mod26. The result of this operation is 19. Now we add the ascii value of 'A' which is 65 to bring it into the range of the capital letter ascii values. So 19+65=84. And 84 is the ascii value for capital T. Thus that character index has been encrypted. 
#### To decrypt the character we basically treat the encrypted char index as our `offset` value and subtract the `offset` from it to revert the ecryption operation



newText += the ascii value of the letter in the plaintext [index] plus (+) the ascii value of the newKey[index] modulus 26 and add 65 to bring it in range of the capital letter 



## Examples
####  Vigenère cipher encrypting:

Plaintext 

```
HELLO 
```

Key Word

```
BLUE
```

Results in

```
IPFPP
```

More complex message: 

Plaintext

```
HELLOMYNAMEISNOEL
```


Key Word

```
RED
```

Results in

```
YIOCSPPRDDILJRRVP
``` 


### Vigenère cipher decrypting :

Ciphertext

```
IPFPP
```

Key Word used

```
BLUE
```

Results in

```
HELLO
```






> Explanation: \
If the user inputs the plaintext message :  MYNAMEISNOEL \
And the keyword :  RED \
The output ciphertext is :   YIOCSPPRDDILJRRVP \
For generating a new key to be used in the program, the given keyword is repeated in a circular manner until it matches the length of the plain text.
The keyword "RED" generates the key "REDREDREDREDREDRE".
The plain text is then encrypted using the process explained below.
 
#### Encryption
The first letter of the plaintext, G is paired with A, the first letter of the key. So use row G and column A of the Vigenère square, namely G. Similarly, for the second letter of the plaintext, the second letter of the key is used, the letter at row E and column Y is C. The rest of the plaintext is enciphered in a similar fashion.
Encryption:
The the plaintext(P) and key(K) are added modulo 26.\
Ei = (Pi + Ki) mod 26

#### Decryption
Decryption is performed by going to the row in the table corresponding to the key, finding the position of the ciphertext letter in this row, and then using the column’s label as the plaintext. For example, in row A (from AYUSH), the ciphertext G appears in column G, which is the first plaintext letter. Next we go to row Y (from AYUSH), locate the ciphertext C which is found in column E, thus E is the second plaintext letter.

Decryption: \
Di = (Ei - Ki + 26) mod 26
Note: Di denotes the offset of the i-th character of the plaintext. Like offset of A is 0 and of B is 1 and so on.
