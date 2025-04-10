#ifndef EC_H
#define EC_H

    //Screen manipulation
        #define EC_DEF      "\x1B[0m"               //reset SGR (Select Graphic Rendition) to Default
        #define EC_CLS      "\x1B[2J\x1B[H"         //clears the entire terminal screen, set cursor to (0,0)
        #define EC_CLS_LN   "\x1B[2k\r"             //clears a single line, resets cursor to start of line

    //cursor manipulation
        #define EC_cursor_UP(n)     __mingw_printf("\x1B[%dA",(n))     //moves the cursor n lines upwards
        #define EC_cursor_DWN(n)    __mingw_printf("\x1B[%dB",(n))     //moves the cursor n lines downwards
        #define EC_cursor_FWD(n)    __mingw_printf("\x1B[%dC",(n))     //moves the cursor n columns right
        #define EC_cursor_BCK(n)    __mingw_printf("\x1B[%dD",(n))     //moves the cursor n columns left
        #define EC_cursor_NXT_LN(n) __mingw_printf("\x1B[%dE",(n))     //moves the cursor to the start of a line, n lines downwards
        #define EC_cursor_PRV_LN(n) __mingw_printf("\x1B[%dF",(n))     //moves the cursor to the start of a line, n lines upwards
    
    //functions with customizable input
        //changes text color to a custom RGB(0-255) value
        #define EC_set_txt_rgb(r,g,b) __mingw_printf("\x1B[38;2;%d;%d;%dm",(r),(g),(b))
        //changes the ENTIRE terminal's background color to a custom RGB(0-255) value
        #define EC_set_BG_rgb(r,g,b) __mingw_printf("\x1B[48;2;%d;%d;%dm",(r),(g),(b))
        //moves the cursor to a specified location within the terminal
        #define EC_move_cursor(x,y) __mingw_printf("\x1B[%d;%dH",(x),(y))

    //common text colors
        #define EC_TXT_BLK      "\x1B[30m"      //changes the text color to Black
        #define EC_TXT_RED      "\x1B[31m"      //changes the text color to Red
        #define EC_TXT_GRN      "\x1B[32m"      //changes the text color to Green
        #define EC_TXT_YEL      "\x1B[33m"      //changes the text color to Yellow
        #define EC_TXT_BLU      "\x1B[34m"      //changes the text color to Blue
        #define EC_TXT_MAG      "\x1B[35m"      //changes the text color to Magenta
        #define EC_TXT_CYN      "\x1B[36m"      //changes the text color to Cyan
        #define EC_TXT_WHT      "\x1B[37m"      //changes the text color to White

    //text modification (bold, italicize, etc)
        #define EC_BLD          "\x1B[1m"       //bolds or brightens the text
        #define EC_ITC          "\x1B[3m"       //Italicizes the text
        #define EC_UND          "\x1B[4m"       //underlines the text
    
    //text background color
        #define EC_TXT_BG_BLK  "\x1B[40m"       //changes the text's background color to Black
        #define EC_TXT_BG_RED  "\x1B[41m"       //changes the text's background color to Red
        #define EC_TXT_BG_GRN  "\x1B[42m"       //changes the text's background color to Green
        #define EC_TXT_BG_YEL  "\x1B[43m"       //changes the text's background color to Yellow
        #define EC_TXT_BG_BLU  "\x1B[44m"       //changes the text's background color to Blue
        #define EC_TXT_BG_MAG  "\x1B[45m"       //changes the text's background color to Magenta
        #define EC_TXT_BG_CYN  "\x1B[46m"       //changes the text's background color to Cyan
        #define EC_TXT_BG_WHT  "\x1B[47m"       //changes the text's background color to White

#endif