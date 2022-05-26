#pragma once

#ifndef _STACKMETHODS_
#define _STACKMETHODS_

#include "./Elem.cpp"

void Push(Elem *&top, BracketsInfo value)
{
  Elem *tmp = new Elem;
  tmp->info = value;
  tmp->link = top;
  top = tmp;
}

BracketsInfo pop(Elem *&top)
{
  Elem *tmp = top->link;          // 1
  BracketsInfo value = top->info; // 2
  delete top;                     // 3
  top = tmp;                      // 4
  return value;                   // 5
}

#endif // !_STACKMETHODS_
