#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{    
    if (argc != 2)
    {
        printf("Wrong number of arguments. Please try again.\n");
        
        return 1;
    }
    else 
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must be alphabetic chars only.");
                
                return 1;
            }    
        }
    }
    
    // Anahtar kelimeyi tutalım
    string k = argv[1];
    int kLen = strlen(k);
    
    // Şifrelenecek text
    string p = get_string("plaintext:");
    
    // Döngü
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {            
        // harf için oluşan kaydırma
        int letterKey = tolower(k[j % kLen]) - 'a';
        
        // büyük harf ise
        if (isupper(p[i]))
        {
            // anahtar eklendiğindeki büyük harf
            printf("%c", 'A' + (p[i] - 'A' + letterKey) % 26);
            
            // ikimnci döngü artırma
            j++;
        }
        else if (islower(p[i]))
        {
            printf("%c", 'a' + (p[i] - 'a' + letterKey) % 26);
            j++;
        }
        else
        {
            // değişmeden dönenler
            printf("%c", p[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}
