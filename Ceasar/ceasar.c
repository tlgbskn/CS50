#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, string argv[])
{


// kontrol noktası
    if (argc == 2 && isdigit(*argv[1]))
        
    {

        int k = atoi(argv[1]); // anahtar argumanı integera çeviriyoruz

        string s = get_string("plaintext: "); // metni alıyoruz
        printf("ciphertext: "); // şifreli halini yazıyoruz

// metni harf harf inceliyoruz
        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            // eğer lowercase 97 = a dan 112 = z ve if it + 13 harf uzunluğuna bakıyoruz.
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a'); // kucuk harfleri anahtarla yazıyroruz
            } // eğer büyük harf aralıpında ise
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A'); // büyük harfleri anahtarla hyazıyoruz
            }

            else

            {
                printf("%c", s[i]);
            }
        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar k\n");
        return 1;

    }
}
