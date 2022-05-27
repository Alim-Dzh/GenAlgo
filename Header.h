#pragma once
#include <iostream>
using namespace std;

int randInt(int min, int max);

int* GenMin2(int A, int B, int* funcX);

void Ext(int A, int B);

void menu();

double function(int x);

int findMinRec(int* fY, int n);

void reBinary(int* A, int newB, string* S);

string binary(int n, int B);

string* Crossover(string* fBit, int i, int newB);

void Mutation(string* funcX, int B);

void Selection(int* funcX, int* Child, int* Rez);

int* GenMax(int A, int B);

void GenMin(int A, int B);

int comp(const void* a, const void* b);