#include <iostream>
#include <fstream>
#include <string>

#include "./extends/Elem.cpp"
#include "./extends/process.cpp"
#include "./extends/BracketsInfo.cpp"
#include "./extends/StackMethods.cpp"

using namespace std;

void Print(Elem *top)
{
  BracketsInfo info;

  while (top != NULL)
  {
    info = top->info;

    cout << "startPos: " << info.startPos << "\tendPos: " << info.endPos << "\ttext: " << info.text << endl;
    top = top->link;
  }
  cout << endl;
}

void ReadFromFile(Elem *&top, char *fname)
{
  ifstream f(fname);
  int size;
  string data;

  BracketsInfo value;

  while (getline(f, data)) {
    size = data.size();

    for (int i = 0; i < size; i++)
      if (data[i] == '(')
        Push(top, process(data, i));
  }
}

int main()
{
  int value, N, menu;

  Elem *my_stack;

  char fname[] = "data.txt";
  cout << endl;

  string text = "(logo(img) (res) test) (text())";

  ofstream f(fname);
  f << text;
  f.close();

  ReadFromFile(my_stack, fname);

  Print(my_stack);

  return 0;
}