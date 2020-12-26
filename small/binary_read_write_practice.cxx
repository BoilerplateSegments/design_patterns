#include <iostream>
#include <stdlib.h>
#include <fstream>
// Thanks <http://www.eecs.umich.edu/courses/eecs380/HANDOUTS/cppBinaryFileIO-2.html>


// Further reading
// Cap’n Proto -> libcapnp
// Boost.serialization


typedef struct Cat{
    int id;
    char name[10];
}Cat_t;

int main(){

    Cat_t tom = {30,"tom"};
    std::ofstream outfile;
    outfile.open("temp.dat",std::ios::binary|std::ios::out);
    outfile.write((char*)&tom,sizeof(Cat));
    outfile.close();

    return 0;
}


/*
-C, --canonical
Canonical hex+ASCII display.  Display the input offset in hexadecimal, followed by  sixteen  space-separated,
two-column, hexadecimal bytes, followed by the same sixteen bytes in %_p format enclosed in '|' characters.

hexdump -C ./temp.dat 
00000000  1e 00 00 00 74 6f 6d 00  00 00 00 00 00 00 00 00  |....tom.........|
00000010

1 int is 4 bytes as (1e 00 00 00)
1 char is 1 byte
Hex:74 -> Ascii:t
Hex:6f -> Ascii:o
Hex:6d -> Ascii:m
*/
