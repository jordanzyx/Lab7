//
// Created by Jordan on 10/10/2019.
//
#include <stdio.h>
#include "header.h"
#include "math.h"

int howManyDaysInMonth(FILE *infile){
    int month = 0;
    int year = 0;

    fscanf(infile,"%d",&month);
    fscanf(infile,"%d",&year);

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
    if(month == 4 || month == 6 || month == 9 || month == 11)return 30;

    return year % 4 == 0 ? 29 : 28;
}

int solveClient(FILE *infile,FILE *outfile){
    int id = 0;
    double average = 0;
    int hours = 0;
    fscanf(infile,"%d",&id);
    fscanf(infile,"%d",&hours);
    double charged =charge(hours,&average);

    fprintf(outfile,"Charged: %.2lf : Average Price per hour %.2lf\n",roundDouble(charged),roundDouble(average));
}

double roundDouble(double amount){

    int intVer = (int)amount;

    double decimals = amount - intVer;

    double new = (int)(decimals * 100);

    int newIntVer = (int)(decimals * 10000);

    double next = new / 100.0;

    return ((intVer + next + (newIntVer >= 50 ? .01 : 0)) * 100) / 100;
}

double charge(int hours,double *average){
    double price = 0;
    if (hours <= 10)price = hours * 7.99;
    if (hours > 10)price = (10 * 7.99) + (hours - 10) * 1.99;

    *average = price / hours;
    return price;
}

void solve(FILE *infile,FILE *outfile){
    int days = howManyDaysInMonth(infile);

    while (!feof(infile)){
        solveClient(infile,outfile);
    }
}

