#pragma once

#ifndef _PROCESS_
#define _PROCESS_

#include <iostream>
#include <fstream>
#include <string>
#include "./BracketsInfo.cpp"

using namespace std;

BracketsInfo process(string expression, int index)
{
  BracketsInfo value;

  if (expression[index] != '(')
  {
    cout << "Erorr: invalid data" << endl;
    return value;
  }

  stack<char> st;

  for (int i = index; i < expression.length(); i++)
  {

    if (expression[i] == '(')
      st.push(expression[i]);

    else if (expression[i] == ')')
    {
      st.pop();
      if (st.empty())
      {
        value.startPos = index;
        value.endPos = i;
        value.text = expression.substr(index + 1, i - index - 1);

        return value;
      }
    }
  }

  if (value.startPos == -1 || value.endPos == -1)
  {
    cout << "Erorr: invalid data" << endl;
  }

  return value;
}

#endif // !_PROCESS_
