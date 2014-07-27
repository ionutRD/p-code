#!/usr/bin/python

import sys

def generate_problem(name):
    fo = open(name, "w")
    code = \
"""
#include <iostream>

using namespace std;

int main()
{
    return 0;
}
"""
    fo.write(code)
    fo.close()

if __name__ == "__main__":
    generate_problem(sys.argv[1])
