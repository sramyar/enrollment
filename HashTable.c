// -------------------------------
// Operations supporting hash tables
// -------------------------------

// -------------------------------
// Converts a 5 letter key into an integer
// CC###: ascii equivalent of letters and digits are simply added together.
// #####: ascii equivalent of digits are simply added together.
// -------------------------------
int convert( char key[5] )
{
    int ascii_val = 0;
    for (int i = 0; i < 5; i++)
    {
        ascii_val+=(int)key[i];
    }
    
    return ascii_val;
}

// -------------------------------
// Hash function that returns an index into the hash table given a key
// use the module formula on page 263 of CLRS.
// we're using '5381' as the divisor
// -------------------------------
int hash( char key[5], int slots )
{
    return convert(key)%slots;
}

