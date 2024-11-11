// For the 2D array, this sets the width

#ifndef EB914D73_4A8D_48D5_8081_1B515ABD0343
#define EB914D73_4A8D_48D5_8081_1B515ABD0343
#define COLS 100

// Load the dictionary of words from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size);

char (*loadFile2D(char *filename, int *size))[COLS];


// Search the dictionary for the target string
// Return the found string or NULL if not found.
char * stringSearchAA(char *target, char ** arr, int size);
//char * substringSearch2D(char *target, char (*arr)[COLS], int size);

// Free the memory used by the array
void freeAA(char ** arr, int size);

//void free2D(char (*arr)[COLS]);


#endif /* EB914D73_4A8D_48D5_8081_1B515ABD0343 */