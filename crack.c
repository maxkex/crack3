#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    //char (*hashes)[HASH_LEN] = loadFile(argv[1], &size);
    char **hashes = loadFileAA(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    printf("Size of the array: %d\n", size);
    // TODO
    // Open the password file for reading.

    FILE *password_file = fopen(argv[2], "r");
    if (password_file == NULL) {

        perror("Error opening password file");
        exit(1);
    }

    // TODO
    // For each password, hash it, then use the array searc
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.

    char line[PASS_LEN];
    int found = 0;
    while (fgets(line, PASS_LEN, password_file)) 
    {
        char *newline = strchr(line, '\n');
        if (newline) 
        {
            *newline = '\0';
        }

        char *hash = md5(line, strlen(line));

        if(!hash)
        {
            printf("Failed to compute hash for %s\n", line);
            continue;
        }

        //printf("%s is hash of %s\n", hash, line); //debugging

        int found_index = linearSearch(hash, hashes, size);
        //printf("Found index: %d\n", found_index);
        if (found_index >= 0) 
        {
            printf("%s %s\n", hash, line);
            found++;
        }
        free(hash);
    }

    // CHALLENGE1: Use binary search instead of linear search.

    // TODO
    // When done with the file:
    //   Close the file
    //   Display the number of hashes found.
    //   Free up memory.
    fclose(password_file);
    printf("Found %d hashes\n", found);
    freeAA(hashes, size);
    
}
