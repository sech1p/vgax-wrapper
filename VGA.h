/**
 * @file VGA.h
 * @author Eliza "sech1p" Semeniuk (https://sech1p.ovh)
 * @brief A dummy wrapper for Arduino's VGAX library
 * @version 0.1
 * @date 2024-11-03
 * 
 */

#ifndef VGA_H_
#define VGA_H_

#include <VGAX.h>

VGAX vga;

// Colors defined based on my Arduino Nano and connections to it, so you probably might need to adjust these
// At least that's what I found in the VGAx library code - which uses two colors (in my case R connected to 6 pin, B connected to 7 pin)
// Unfortunately, the limited number of colors is due to the limitations of this library and the computing power of Arduino itself, which is small.
// If anyone knows if and how to connect all graphics (R, G and B) with one Arduino Nano or just want to tell me that I'm wrong and I can use all of their, hmu
// de facto there are only 4 colors available, but VGAx library in their Readme file in examples used values bigger than 4 (like 11, etc.)
#define COLOR_BLACK 0
#define COLOR_RED 1
#define COLOR_BLUE 2
#define COLOR_PINK 3
#define COLOR_RED_BOLD 5
#define COLOR_BLUE_BOLD 10
#define COLOR_NEON 11

// https://github.com/smaffer/vgax?tab=readme-ov-file#fonts
#define FNT_UFONT_SYMBOLS_COUNT 95
#define FNT_UFONT_HEIGHT 6

const unsigned char fnt_ufont_data[FNT_UFONT_SYMBOLS_COUNT][1 + FNT_UFONT_HEIGHT] PROGMEM = {
    { 1, 128, 128, 128,   0, 128,   0, }, //glyph '!' code=0
    { 3, 160, 160,   0,   0,   0,   0, }, //glyph '"' code=1
    { 5,  80, 248,  80, 248,  80,   0, }, //glyph '#' code=2
    { 5, 120, 160, 112,  40, 240,   0, }, //glyph '$' code=3
    { 5, 136,  16,  32,  64, 136,   0, }, //glyph '%' code=4
    { 5,  96, 144, 104, 144, 104,   0, }, //glyph '&' code=5
    { 2, 128,  64,   0,   0,   0,   0, }, //glyph ''' code=6
    { 2,  64, 128, 128, 128,  64,   0, }, //glyph '(' code=7
    { 2, 128,  64,  64,  64, 128,   0, }, //glyph ')' code=8
    { 3,   0, 160,  64, 160,   0,   0, }, //glyph '*' code=9
    { 3,   0,  64, 224,  64,   0,   0, }, //glyph '+' code=10
    { 2,   0,   0,   0,   0, 128,  64, }, //glyph ',' code=11
    { 3,   0,   0, 224,   0,   0,   0, }, //glyph '-' code=12
    { 1,   0,   0,   0,   0, 128,   0, }, //glyph '.' code=13
    { 5,   8,  16,  32,  64, 128,   0, }, //glyph '/' code=14
    { 4,  96, 144, 144, 144,  96,   0, }, //glyph '0' code=15
    { 3,  64, 192,  64,  64, 224,   0, }, //glyph '1' code=16
    { 4, 224,  16,  96, 128, 240,   0, }, //glyph '2' code=17
    { 4, 224,  16,  96,  16, 224,   0, }, //glyph '3' code=18
    { 4, 144, 144, 240,  16,  16,   0, }, //glyph '4' code=19
    { 4, 240, 128, 224,  16, 224,   0, }, //glyph '5' code=20
    { 4,  96, 128, 224, 144,  96,   0, }, //glyph '6' code=21
    { 4, 240,  16,  32,  64,  64,   0, }, //glyph '7' code=22
    { 4,  96, 144,  96, 144,  96,   0, }, //glyph '8' code=23
    { 4,  96, 144, 112,  16,  96,   0, }, //glyph '9' code=24
    { 1,   0, 128,   0, 128,   0,   0, }, //glyph ':' code=25
    { 2,   0, 128,   0,   0, 128,  64, }, //glyph ';' code=26
    { 3,  32,  64, 128,  64,  32,   0, }, //glyph '<' code=27
    { 3,   0, 224,   0, 224,   0,   0, }, //glyph '=' code=28
    { 3, 128,  64,  32,  64, 128,   0, }, //glyph '>' code=29
    { 4, 224,  16,  96,   0,  64,   0, }, //glyph '?' code=30
    { 4,  96, 144, 176, 128, 112,   0, }, //glyph '@' code=31
    { 4,  96, 144, 240, 144, 144,   0, }, //glyph 'A' code=32
    { 4, 224, 144, 224, 144, 224,   0, }, //glyph 'B' code=33
    { 4, 112, 128, 128, 128, 112,   0, }, //glyph 'C' code=34
    { 4, 224, 144, 144, 144, 224,   0, }, //glyph 'D' code=35
    { 4, 240, 128, 224, 128, 240,   0, }, //glyph 'E' code=36
    { 4, 240, 128, 224, 128, 128,   0, }, //glyph 'F' code=37
    { 4, 112, 128, 176, 144, 112,   0, }, //glyph 'G' code=38
    { 4, 144, 144, 240, 144, 144,   0, }, //glyph 'H' code=39
    { 3, 224,  64,  64,  64, 224,   0, }, //glyph 'I' code=40
    { 4, 240,  16,  16, 144,  96,   0, }, //glyph 'J' code=41
    { 4, 144, 160, 192, 160, 144,   0, }, //glyph 'K' code=42
    { 4, 128, 128, 128, 128, 240,   0, }, //glyph 'L' code=43
    { 5, 136, 216, 168, 136, 136,   0, }, //glyph 'M' code=44
    { 4, 144, 208, 176, 144, 144,   0, }, //glyph 'N' code=45
    { 4,  96, 144, 144, 144,  96,   0, }, //glyph 'O' code=46
    { 4, 224, 144, 224, 128, 128,   0, }, //glyph 'P' code=47
    { 4,  96, 144, 144, 144,  96,  16, }, //glyph 'Q' code=48
    { 4, 224, 144, 224, 160, 144,   0, }, //glyph 'R' code=49
    { 4, 112, 128,  96,  16, 224,   0, }, //glyph 'S' code=50
    { 3, 224,  64,  64,  64,  64,   0, }, //glyph 'T' code=51
    { 4, 144, 144, 144, 144,  96,   0, }, //glyph 'U' code=52
    { 3, 160, 160, 160, 160,  64,   0, }, //glyph 'V' code=53
    { 5, 136, 168, 168, 168,  80,   0, }, //glyph 'W' code=54
    { 4, 144, 144,  96, 144, 144,   0, }, //glyph 'X' code=55
    { 3, 160, 160,  64,  64,  64,   0, }, //glyph 'Y' code=56
    { 4, 240,  16,  96, 128, 240,   0, }, //glyph 'Z' code=57
    { 2, 192, 128, 128, 128, 192,   0, }, //glyph '[' code=58
    { 5, 128,  64,  32,  16,   8,   0, }, //glyph '\' code=59
    { 2, 192,  64,  64,  64, 192,   0, }, //glyph ']' code=60
    { 5,  32,  80, 136,   0,   0,   0, }, //glyph '^' code=61
    { 4,   0,   0,   0,   0, 240,   0, }, //glyph '_' code=62
    { 2, 128,  64,   0,   0,   0,   0, }, //glyph '`' code=63
    { 3,   0, 224,  32, 224, 224,   0, }, //glyph 'a' code=64
    { 3, 128, 224, 160, 160, 224,   0, }, //glyph 'b' code=65
    { 3,   0, 224, 128, 128, 224,   0, }, //glyph 'c' code=66
    { 3,  32, 224, 160, 160, 224,   0, }, //glyph 'd' code=67
    { 3,   0, 224, 224, 128, 224,   0, }, //glyph 'e' code=68
    { 2,  64, 128, 192, 128, 128,   0, }, //glyph 'f' code=69
    { 3,   0, 224, 160, 224,  32, 224, }, //glyph 'g' code=70
    { 3, 128, 224, 160, 160, 160,   0, }, //glyph 'h' code=71
    { 1, 128,   0,   128, 128, 128, 0, }, //glyph 'i' code=72
    { 2,   0, 192,  64,  64,  64, 128, }, //glyph 'j' code=73
    { 3, 128, 160, 192, 160, 160,   0, }, //glyph 'k' code=74
    { 1, 128, 128, 128, 128, 128,   0, }, //glyph 'l' code=75
    { 5,   0, 248, 168, 168, 168,   0, }, //glyph 'm' code=76
    { 3,   0, 224, 160, 160, 160,   0, }, //glyph 'n' code=77
    { 3,   0, 224, 160, 160, 224,   0, }, //glyph 'o' code=78
    { 3,   0, 224, 160, 160, 224, 128, }, //glyph 'p' code=79
    { 3,   0, 224, 160, 160, 224,  32, }, //glyph 'q' code=80
    { 3,   0, 224, 128, 128, 128,   0, }, //glyph 'r' code=81
    { 2,   0, 192, 128,  64, 192,   0, }, //glyph 's' code=82
    { 3,  64, 224,  64,  64,  64,   0, }, //glyph 't' code=83
    { 3,   0, 160, 160, 160, 224,   0, }, //glyph 'u' code=84
    { 3,   0, 160, 160, 160,  64,   0, }, //glyph 'v' code=85
    { 5,   0, 168, 168, 168,  80,   0, }, //glyph 'w' code=86
    { 3,   0, 160,  64, 160, 160,   0, }, //glyph 'x' code=87
    { 3,   0, 160, 160, 224,  32, 224, }, //glyph 'y' code=88
    { 2,   0, 192,  64, 128, 192,   0, }, //glyph 'z' code=89
    { 3,  96,  64, 192,  64,  96,   0, }, //glyph '{' code=90
    { 1, 128, 128, 128, 128, 128,   0, }, //glyph '|' code=91
    { 3, 192,  64,  96,  64, 192,   0, }, //glyph '}' code=92
    { 3,  96, 192,   0,   0,   0,   0, }, //glyph '~' code=93
    { 4,  48,  64, 224,  64, 240,   0, }, //glyph '£' code=94
};

/**
 * @brief The function that draws the string, it uses the default font as in the VGAx library example (kudos to its author). There will be more fonts to choose in the future
 * 
 * @param x Position X where the given string will be drawn
 * @param y Position Y where the given string will be drawn
 * @param str A string to draw to the screen
 * @param color Integer setting the color in which the drawn string is to be displayed (see available colors in the wrapper header file to reference)
 */
void DrawString(char x, char y, const char str[] PROGMEM, byte color)
{
    vga.printPROGMEM((byte*)fnt_ufont_data, FNT_UFONT_SYMBOLS_COUNT, FNT_UFONT_HEIGHT, 3, 1, str, x, y, color);
}

/**
 * @brief The function that draws the number, I was not able to declare a const with value of a dynamic number function, so there is a workaround
 * 
 * @param x Position X where the given number will be drawn
 * @param y Position Y where the given number will be drawn
 * @param number A string with a number to draw to the screen
 * @param color Integer setting the color in which the drawn number is to be displayed (see available colors in the wrapper header file to reference)
 */
void DrawNumber(char x, char y, String number, byte color)
{
  size_t len = number.length();
  int current_x = x;
  char number_array[len];
  const static char zero[] PROGMEM = "0";
  const static char one[] PROGMEM = "1";
  const static char two[] PROGMEM = "2";
  const static char three[] PROGMEM = "3";
  const static char four[] PROGMEM = "4";
  const static char five[] PROGMEM = "5";
  const static char six[] PROGMEM = "6";
  const static char seven[] PROGMEM = "7";
  const static char eight[] PROGMEM = "8";
  const static char nine[] PROGMEM = "9";

  number.toCharArray(number_array, len);

  for (int i = 0; i < number.length(); i++) {
    if (number_array[i] == '0')
      DrawString(current_x, y, zero, color);
    if (number_array[i] == '1')
      DrawString(current_x, y, one, color);
    if (number_array[i] == '2')
      DrawString(current_x, y, two, color);
    if (number_array[i] == '3')
      DrawString(current_x, y, three, color);
    if (number_array[i] == '4')
      DrawString(current_x, y, four, color);
    if (number_array[i] == '5')
      DrawString(current_x, y, five, color);
    if (number_array[i] == '6')
      DrawString(current_x, y, six, color);
    if (number_array[i] == '7')
      DrawString(current_x, y, seven, color);
    if (number_array[i] == '8')
      DrawString(current_x, y, eight, color);
    if (number_array[i] == '9')
      DrawString(current_x, y, nine, color);
    current_x += FNT_UFONT_HEIGHT;
  }
}

#endif // VGA_H_