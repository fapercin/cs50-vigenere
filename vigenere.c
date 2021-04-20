#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    string value = argv[1];
    for (int i = 0; i < strlen(value); i++)
    {
        if(isdigit(value[i]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
        // checking every single character in the value if it contains digit
        // if it does, prompting an error message.
    }
    
    string plaintext = get_string("plaintext: ");
    
    int key;
    for(int i = 0; i < strlen(plaintext); i++)
    {
            key = shift(value[i % strlen(value)]);
            if(islower(plaintext[i]))
            {
                plaintext[i] = (((plaintext[i] - 97) + key) % 26)+ 97;
            }
            else if(isupper(plaintext[i]))
            {
                plaintext[i] = (((plaintext[i] - 65) + key) % 26) + 65;
            }
            else 
            {
                plaintext[i] = plaintext[i];
            }
            
        printf("Int value of key: %d\n", key);
        
    }
    
    printf("ciphertext: %s\n", plaintext);
}

int shift(char c)
{
    if(islower(c))
    {
        c = c - 97;
        // minus 97 because i need to set a(97) to 0, b(98) to 1...
        return c;
    }
    if(isupper(c))
    {
        c = c - 65;
        // minus 65 because i need to set A(65) to 0, B(66) to 1...
        return c;
    }
    else return 1;
}
