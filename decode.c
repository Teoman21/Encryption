#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Please invoke as %s <key>\n", argv[0]);
        return 1; // Indicate something went wrong
    }
    char *key = argv[1];
    int keyLength = strlen(key);

    // Create an array of ASCII characters in order
    char ascii[128];
    for (int i = 0; i < 128; i++)
    {
        ascii[i] = i;
    }

    // Shuffle the ASCII array using the key
    for (int i = 0; i < 128; i++)
    {
        int j = (i + key[i % keyLength]) % 128;
        char temp = ascii[i];
        ascii[i] = ascii[j];
        ascii[j] = temp;
    }

    int nextChar;
    while ((nextChar = getchar()) != EOF)
    {
      
        // Find the decoded character in the shuffled ASCII array
        char decodedChar = ascii[nextChar];
	if(nextChar == '\n'){

	  putchar(nextChar);
	  continue;
	}
        // Ignore non-printable ASCII characters
        if (!isprint(decodedChar))
        {
            continue;
        }

        putchar(decodedChar);
    }
    return 0; // Indicate nothing went wrong
}