#pragma once

#ifndef _ELEM_
#define _ELEM_

#include "./BracketsInfo.cpp"

struct Elem
{
  Elem *link;
  BracketsInfo info;
};

#endif // !_ELEM_
