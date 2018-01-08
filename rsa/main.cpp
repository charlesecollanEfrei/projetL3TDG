//
//  main.cpp
//  rsa
//
//  Created by Charles Ecollan on 20/03/2017.
//  Copyright © 2017 Charles Ecollan. All rights reserved.
//

#include <iostream>

unsigned long rsa(unsigned n, unsigned e, unsigned long block){
    unsigned long res = 1;
    int i;
    res=1;
    for(i=0; i<e; i++){
        res = (res*block)%n;
    }
    return res;
}


int main(int argc, const char * argv[]) {
    printf("Welcome to the dark-side rsa Project\n");
    unsigned n, d;
    unsigned s1, s2;
    unsigned nT = 1876891, eT = 3125;
    unsigned long res;
    int fr;
    bool flag;
    printf("Enter your n: ");
    fr = scanf("%u", &n);
    printf("Enter your d: ");
    fr = scanf("%u", &d);
    printf("Now we test teller signature!\nEnter crypted signatures send by teller\nN°1: ");
    fr = scanf("%u", &s1);
    printf("N°2: ");
    fr = scanf("%u", &s2);
    if(n > nT){
        res = rsa(n, d, s1);
        res = rsa(nT, eT, res);
        if(res == 1121948){
            printf("Message 1 is correctly signed !\n");
            flag = true;
        }else{
            res = rsa(n, d, s2);
            res = rsa(nT, eT, res);
            if(res == 1121948){
                printf("Message 2 is correctly signed !\n");
                flag = false;
            }else{
                printf("Fatal ERROR no signature match!\nPlease check your data!\n");
                exit(0);
            }
        }
    }else{
        res = rsa(nT, eT, s1);
        res = rsa(n, d, res);
        if(res == 1121948){
            printf("Message 1 is correctly signed !\n");
            flag = true;
        }else{
            res = rsa(nT, eT, s2);
            res = rsa(n, d, res);
            if(res == 1121948){
                printf("Message 2 is correctly signed !\n");
                flag = false;
            }else{
                printf("Fatal ERROR no signature match!\nPlease check your data!\n");
                exit(0);
            }
        }
    }
    if(flag){
        printf("Enter cypher message n°1: ");
    }else{
        printf("Enter cypher message n°2: ");
    }
    unsigned m;
    fr = scanf("%u", &m);
    res = rsa(n, d, m);
    printf("Plain message: %lu\n", res);
    
    printf("Thank you Teller !!\nand nique la SEP!\n");
    return 0;
}
