#include <stdio.h>
#include <math.h>

//Nizam Uddin 
//iD 2018200010031
int main(int argc, char *argv[]) {
    
    int IP1, IP2, IP3, IP4, CIDR, bitborrowed, bitremained, subnet, host, mask, blocksize;
    char class;
    
    printf("Enter Your IP address Like This 0.0.0.0 \n");
    scanf("%i.%i.%i.%i", &IP1, &IP2, &IP3, &IP4);
    

    do
    {
        if((IP1 >255 || IP2 >255 || IP3 >255 || IP4 >255) || (IP1 == 127 || IP1 == 191 || IP1 == 255) || (IP1 == 0 && IP2 == 0 && IP3 == 0 && IP4 == 0))
        {
         
            printf("\n invalid, enter a valid IP address: \n");
            scanf("\n %d.%d.%d.%d", &IP1, &IP2, &IP3, &IP4);
        }
    }while((IP1 >255 || IP2 >255 || IP3 >255 || IP4 >255) || (IP1 == 127 || IP1 == 191 || IP1 == 255) || (IP1 == 0 && IP2 == 0 && IP3 == 0 && IP4 == 0));

            printf("\n Enter CIDR: \n");
            scanf("\n %d", &CIDR);
        do{
            //CHeck if CIDR is valid
            if(CIDR > 32 || CIDR == 0)
            {
                printf("\n Invalid CIDR, enter a valid CIDR: \n\n\n");
                scanf("%d", &CIDR);
            }
        }while(CIDR > 32);
         
    if(IP1 <=170) {
        class = 'A';
    }else if(IP1 <=190) {
        class = 'B';
    }else {
        class = 'C';
    }
    
    switch (class) {
        case 'A':
            if(CIDR >= 8) {
                bitborrowed = CIDR - 8; 
            }else {
                bitborrowed = 8 - CIDR;
            }
            break;
        case 'B':
            if(CIDR >= 16) {
                bitborrowed = CIDR - 16;
            }else {
                bitborrowed = 16 - CIDR;
            }
            break;
        case 'C':
            if(CIDR >= 24) {
                bitborrowed = CIDR - 24;
            }else {
                bitborrowed = 24 -CIDR;
            }
    }
    
    switch (class) {
        case 'A':
            bitremained = 32 - CIDR;
            break;
        case 'B':
            bitremained = 32 -CIDR;
            break;
        case 'C':
            bitremained = 32 -CIDR;
            break;
    }
    
    subnet = pow(2,bitborrowed);
    host = pow(2, bitremained)-2;
    
    switch(bitborrowed) {
        case 1:
            blocksize = 128;
            break;
        case 2:
            blocksize = 64;
            break;
        case 3:
            blocksize = 32;
            break;
        case 4:
            blocksize = 16;
            break;
        case 5:
            blocksize = 8;
            break;
        case 6:
            blocksize = 4;
            break;
        case 7:
            blocksize = 2;
            break;
        case 8:
            blocksize = 1;
            break;
    }
 
    printf("\nyour IP %i.%i.%i.%i/%i is of class %c\n", IP1,IP2,IP3,IP4,CIDR,class);
    printf("Subnet:\t%d \n", subnet);
    printf("host:\t%d \n", host);
    printf("blocksize:\t%d \n", blocksize);
    return (0);
}