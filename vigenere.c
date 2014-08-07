#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[]){
    
    int i, n, j, d;
    string k, p;
        
    if (argc != 2)
    {
        printf("Usage : ./<program name> <keyword> \n");
        return 1;
    }
    
    k = argv[1];//keywordp = GetString();
    
    //testing alphabetical-only keyword
    for (j = 0; j < strlen(k); j++)
    {
        if (!isalpha(k[j]))
        {
            printf("Usage : ./<program name> <keyword> (keyword must contain only alphabetical characters)\n");
            return 1;
        }
    }
    
    p = GetString();//plaintext
    n = strlen(p);//lenght of plaintext
    j = 0;//keyword's letters counter
    
    for (i = 0; i < n; i++)
    {   
        if (j >= strlen(k))//case all keyword's letters has been used
        {
            j = 0;
        }
        if (isalpha(p[i]))
        {
            //case test for j-th letter of keyword
            if (isupper(k[j]))
            {
                d = (int)k[j] - (int)'A';//variable d displays the "letters-away-from-A" integer
            }
            if (islower(k[j]))
            {
                d = (int)k[j] - (int)'a';
            }
            
            //case test for i-th letter of plaintext
            if (isupper(p[i]))
            {
                //printf("xrhshmopoiw to j %d\n", j);
                p[i] = ((p[i] - 'A') + d) % 26;
                p[i] = p[i] + 'A';
                j = j + 1 ;
                printf("%c", p[i]);
            }
            if (islower(p[i]))
            {
                p[i] = ((p[i] - 'a') + d) % 26;
                p[i] = p[i] + 'a';
                j = j + 1 ;                
                printf("%c", p[i]);
            }
        }
        else//if the character is non-alphabetical
        {
            printf("%c", p[i]);
        }
        
    }
        
       
    
    
    printf("\n");
    return 0;
    
}
