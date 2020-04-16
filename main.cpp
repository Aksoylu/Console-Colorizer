/*  Author      : Umit Aksoylu
*   Date        : 16.04.2020
*   Description : Cross-Platform Unix&Linux CLI Colorising Header Only Library's
*                 Example Application
*
*   Website     : http://umit.space
*   Mail        : umit@aksoylu.space
*/

#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<iostream>
#include "clicolors.hpp"


//run this command to build				    : g++ main.cpp -std=c++11 -o bin
//run this command to execute program	: ./bin

int main(){

  Colors color;
  color.print("Bold text test\n","BOLD");
  color.print("Underlined text test\n","UNDERLINE");
  color.print("Blue color test\n","BLUE");
  color.print("Purple color test\n","PURPLE");
  color.print("Green string test\n","GREEN");
  color.print("Yellow string test\n","YELLOW");
  color.print("Red color test\n","RED");

  

  //What about create Green And Underlined Text ?
  std::string example ="hello word\n";
  example = color.colorize(example,"UNDERLINE");
  example = color.colorize(example,"GREEN");
  std::cout << example;

  //just combinig them and print 


  //or Yellow Bold text but not using std::string, just using with a char array.
  //colorizef functions takes char array as parameter and returns a std::string object
  char const *charArr = "hello world2\n";

  example = color.colorize(charArr,"BOLD");
  example = color.colorizef(charArr,"YELLOW");


  //also printf function takes char array and print it with colors

  char const *charArr4colors = "\ncolor !\n\n";
  color.printf(charArr4colors,"BLUE");

  //you can manually convert char to string or string to char conversion with using;

   char const *chars = "Whats up ?\n";
   std::string str = color.charToString(chars);

   //or inverse

   chars= color.stringToChar(str);


  printf("%s",example.c_str());


}