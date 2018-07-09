#include<stdio.h>
void main()
{
    struct rational{
    int numerator;
    int denominator;
    };
    struct rational r;
    void reduce(struct rational *inrat,struct rational *outrat)
    {
        int a,b,rem;
        if(inrat->numerator > inrat->denominator)
        {
            a=inrat->numerator;
            b=inrat->denominator;
        }
        else{
            b=inrat->numerator;
            a=inrat->denominator;
        }
        while(b!=0){
            rem= a%b;
            a=b;
            b=rem;
        }
        outrat->numerator /=a;
        outrat->denominator /=a;

    }
    r.numerator=1976;
    r.denominator=1032;
    struct rational* p;
    struct rational* s;

    reduce(p,s);
    printf("%d",r.numerator);







}
