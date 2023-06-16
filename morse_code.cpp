#include <iostream>
#include <map>
#include <vector>
#include <cstring>

std::map<char, std::vector<int>> morse_map;

void morse_vals() 
{
    // alphabet
    morse_map['A'] = {0, 1};
    morse_map['B'] = {1, 0, 0, 0};
    morse_map['C'] = {1, 0, 1, 0};
    morse_map['D'] = {1, 0, 0};
    morse_map['E'] = {0};
    morse_map['F'] = {0, 0, 1, 0};
    morse_map['G'] = {1, 1, 0};
    morse_map['H'] = {0, 0, 0, 0};
    morse_map['I'] = {0, 0};
    morse_map['J'] = {0, 1, 1, 1};
    morse_map['K'] = {1, 0, 1};
    morse_map['L'] = {0, 1, 0, 0};
    morse_map['M'] = {1, 1};
    morse_map['N'] = {1, 0};
    morse_map['O'] = {1, 1, 1};
    morse_map['P'] = {0, 1, 1, 0};
    morse_map['Q'] = {1, 1, 0, 1};
    morse_map['R'] = {0, 1, 0};
    morse_map['S'] = {0, 0, 0};
    morse_map['T'] = {1};
    morse_map['U'] = {0, 0, 1};
    morse_map['V'] = {0, 0, 0, 1};
    morse_map['W'] = {0, 1, 1};
    morse_map['X'] = {1, 0, 0, 1};
    morse_map['Y'] = {1, 0, 1, 1};
    morse_map['Z'] = {1, 1, 0, 0};
    morse_map['a'] = {0, 1};
    morse_map['b'] = {1, 0, 0, 0};
    morse_map['c'] = {1, 0, 1, 0};
    morse_map['d'] = {1, 0, 0};
    morse_map['e'] = {0};
    morse_map['f'] = {0, 0, 1, 0};
    morse_map['g'] = {1, 1, 0};
    morse_map['h'] = {0, 0, 0, 0};
    morse_map['i'] = {0, 0};
    morse_map['j'] = {0, 1, 1, 1};
    morse_map['k'] = {1, 0, 1};
    morse_map['l'] = {0, 1, 0, 0};
    morse_map['m'] = {1, 1};
    morse_map['n'] = {1, 0};
    morse_map['o'] = {1, 1, 1};
    morse_map['p'] = {0, 1, 1, 0};
    morse_map['q'] = {1, 1, 0, 1};
    morse_map['r'] = {0, 1, 0};
    morse_map['s'] = {0, 0, 0};
    morse_map['t'] = {1};
    morse_map['u'] = {0, 0, 1};
    morse_map['v'] = {0, 0, 0, 1};
    morse_map['w'] = {0, 1, 1};
    morse_map['x'] = {1, 0, 0, 1};
    morse_map['y'] = {1, 0, 1, 1};
    morse_map['z'] = {1, 1, 0, 0};

    // numbers
    morse_map['0'] = {1, 1, 1, 1, 1};
    morse_map['1'] = {0, 1, 1, 1, 1};
    morse_map['2'] = {0, 0, 1, 1, 1};
    morse_map['3'] = {0, 0, 0, 1, 1};
    morse_map['4'] = {0, 0, 0, 0, 1};
    morse_map['5'] = {0, 0, 0, 0, 0};
    morse_map['6'] = {1, 0, 0, 0, 0};
    morse_map['7'] = {1, 1, 0, 0, 0};
    morse_map['8'] = {1, 1, 1, 0, 0};
    morse_map['9'] = {1, 1, 1, 1, 0};

    // punctuation
    morse_map['.'] = {0, 1, 0, 1, 0, 1}; 
    morse_map[','] = {1, 1, 0, 0, 1, 1};     
    morse_map['?'] = {0, 0, 1, 1, 0, 0};     
    morse_map['!'] = {1, 0, 1, 0, 1, 1};     
    morse_map[':'] = {1, 1, 1, 0, 0, 0};     
    morse_map[';'] = {1, 0, 1, 0, 1, 0};     
    morse_map['-'] = {1, 0, 0, 0, 0, 1}; 
    morse_map[' '] =  {0, 0, 0, 0, 0, 0, 0}; 
}   

std::vector<int> search_morse_char(char x) 
{
    morse_vals();
	std::vector<int> value;
    auto it = morse_map.find(x);
    if (it != morse_map.end()) 
        value = morse_map[x];
    else
        std::cout << "Key: " "\"" + std::string(1, x) + "\"" << " does not have a value" << std::endl;

    return value;
}

/*
int main (void) 
{
    char message[] = "Hello World!";

    for (int i = 0; message[i] != '\0'; i++) {
        std::vector<int> value = search_morse_char(message[i]);
        std::cout << "Character '" << message[i] << "' - Morse Code: ";
        for (int i = 0; i < value.size(); i++) 
            std::cout << value[i];
        
        std::cout << std::endl;
    }
    
 	return 0;
}
*/