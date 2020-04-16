/*  Author      : Umit Aksoylu
*   Date        : 16.04.2020
*   Description : Cross-Platform Unix&Linux CLI Colorising Header Only Library
*                 Developer for creating CLI shell of ClockworkOS
*
*   Website     : http://umit.space
*   Mail        : umit@aksoylu.space
*/

#pragma once
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<iostream>

    std::string  PURPLE = "\033[95m";
    std::string  BLUE = "\033[94m";
    std::string  GREEN = "\033[92m";
    std::string  YELLOW = "\033[93m";
    std::string  RED = "\033[91m";
    std::string  END = "\033[0m";
    std::string  BOLD = "\033[1m";
    std::string  UNDERLINE = "\033[4m";


    class Colors{

        public :

        Colors();
        void print(std::string text, std::string color);
        std::string colorize(std::string text, std::string color);
        void printf(char const * text, std::string color);
        std::string colorizef(char const * text, std::string color);
        std::string charToString(char const * chrArray);
        char const*  stringToChar(std::string str);

        private:

        std::string convert(std::string color);
    };

    /*  Constructor */
     Colors::Colors(){

         // Todo what you want when initializing class
    }

    std::string Colors::convert(std::string color)
    {
        std::string col = "";
        if(color == "PURPLE")
        {
            col =PURPLE;
        }
        else if (color == "BLUE")
        {
            col = BLUE;
        }
        else if (color == "GREEN")
        {
            col = GREEN;
        }
        else if (color == "YELLOW")
        {
            col = YELLOW;
        }
        else if (color == "RED")
        {
            col = RED;
        }
        else if (color == "END")
        {
            col = END;
        }
        else if (color == "BOLD")
        {
            col = BOLD;
        }
        else if (color == "UNDERLINE")
        {
            col = UNDERLINE;
        }
        else
        {
            col = "";
        }

        return col;

    }

    void Colors::print(std::string text, std::string color)
    {
          std::cout << colorize(text,color);

    }

     std::string Colors::colorize(std::string text, std::string color)
    {
        std::string s;

        color = convert(color);
        s.append(color);
        s.append(text);
        s.append(convert("END"));

        return s;
    }

    std::string Colors::charToString(char const * chrArray)
    {
	    std::string str(chrArray);

        return str;
    }

    char const * Colors::stringToChar(std::string str)
    {

         int buflen = str.length(); 
         char buf[buflen + 1]; 
         strcpy(buf, str.c_str());

         return buf;
    }


    std::string Colors::colorizef(char const * text, std::string color)
    {
        std::string str = charToString(text);
        str = colorize(str,color);

        return str;
    }

    void Colors::printf(char const * text, std::string color)
    {

          std::cout << colorizef(text,color);
    }
