// 'Hello World!' program 
 
#include <iostream> // Prerocessing derective from standard library 
#include <locale.h>
#include <fcntl.h>
int main() // main function
{          // start body of the main function  
  std::cout << "Hello World!" << std::endl; // << called insertion operator
  std::cout << "Hello me 1!" << std::endl;
  std::cout << std::endl;

  std::setlocale(LC_ALL,"en_US.UTF-8");
  std::setlocale(LC_CTYPE,"en_US.UTF-8");

  for (int i=1; i < 500; i++)
  {
      wchar_t a=i;
      //wchar_t a=0x0003;
      if (i == 50) std::cout << std::endl; 
      std::wcout << a;
      //std::wcout << L"\uC2A2";
      //wprintf(L"%s",a);     


  }

  return 0;
}
