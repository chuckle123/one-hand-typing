#ifndef OHT_H_
#define OHT_H_

#include <ApplicationServices/ApplicationServices.h>

static const int _a = 0;
static const int _s = 1;
static const int _d = 2;
static const int _f = 3;
static const int _h = 4;
static const int _g = 5;
static const int _z = 6;
static const int _x = 7;
static const int _c = 8;
static const int _v = 9;
static const int _b = 11;
static const int _q = 12;
static const int _w = 13;
static const int _e = 14;
static const int _r = 15;
static const int _y = 16;
static const int _t = 17;
static const int _1 = 18;
static const int _2 = 19;
static const int _3 = 20;
static const int _4 = 21;
static const int _6 = 22;
static const int _5 = 23;
static const int _EQUAL = 24;
static const int _9 = 25;
static const int _7 = 26;
static const int _DASH = 27;
static const int _8 = 28;
static const int _0 = 29;
static const int _RIGHT_BRACKET = 30;
static const int _o = 31;
static const int _u = 32;
static const int _LEFT_BRACKET = 33;
static const int _i = 34;
static const int _p = 35;
static const int _RETURN = 36;
static const int _l = 37;
static const int _j = 38;
static const int _SINGLE_QUOTE = 39;
static const int _k = 40;
static const int _COLON = 41;
static const int _BACK_SLASH = 42;
static const int _COMMA = 43;
static const int _FORWARD_SLASH = 44;
static const int _n = 45;
static const int _m = 46;
static const int _PERIOD = 47;
static const int _TAB = 48;
static const int _SPACE = 49;
static const int _GRAVE_ACCENT = 50;
static const int _DELETE = 51;
static const int _ENTER = 52;
static const int _ESCAPE = 53;
bool isCapsPressed = false;

CGEventRef myCGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon);
int main(void);

#endif

