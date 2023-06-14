#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int req=0;
    if (amount>=1000){
        req+= amount/1000;
        amount-= (amount/1000)*1000;
    }
    if (amount>=500){
        req+= amount/500;
        amount-= (amount/500)*500;
    }
    if (amount>=100){
        req+= amount/100;
        amount-= (amount/100)*100;
    }
    if (amount>=50){
        req+= amount/50;
        amount-= (amount/50)*50;
    }
    if (amount>=20){
        req+= amount/20;
        amount-= (amount/20)*20;
    }
    if (amount>=10){
        req+= amount/10;
        amount-= (amount/10)*10;
    }
    if (amount>=5){
        req+= amount/5;
        amount-= (amount/5)*5;
    }
    if (amount>=2){
        req+= amount/2;
        amount-= (amount/2)*2;
    }
    if (amount>=1){
        req+= amount/1;
        amount-= (amount/1)*1;
    }
    return req;
}
