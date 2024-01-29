#include <iostream>

#include <stdio.h>
#include <stdlib.h>

int main() {

    // setting memory (memset)
    {
        char string1[10] = "abcdef";

        memset(string1, '$', 5);
        std::cout << "------------memset------------\n"; 
        std::cout << string1 << '\n' << '\n';
    }

    // memory character
    {
        char string1[10] = "abcdef";
        char* p = static_cast<char*>(memchr(string1, 'e', sizeof(string1)));

        int position = p - string1;
        std::cout << "------------memchr------------\n";
        std::cout << position << '\n' << '\n';
    }

    // re-allocation
    {
        int *p;
        int new_size = 100;

        p = static_cast<int*>(malloc(50 * sizeof(int)));
        p = static_cast<int*>(realloc(p, new_size * sizeof(int)));
        free(p);
    }

    // freeing data (free)
    {
        struct a_struct {
            uint32_t prop;
        };
        a_struct* a = static_cast<a_struct*>(malloc(sizeof(a_struct)));
        free(a);
    }

    // copying memory (memcpy)
    {
        char from_src[100] = "hello";
        char* to_dst = static_cast<char*>(malloc(sizeof(from_src) * sizeof(char)));

        memcpy(to_dst, from_src, sizeof(from_src));

        std::cout << "------------memcpy------------\n";
        std::cout << to_dst << '\n' << '\n';

        free(to_dst);
    }

    // comparing memory (memcmp)
    {
        char string1[10] = "abcdef";
        char string2[10] = "ABCDEF";

        // memcpy(string1, "abcdef", 6);
        
        std::cout << "------------memcmp------------\n";
        int result = memcmp(string1, string2, 5);
        std::cout << result << '\n';
    }

    return 0;
}