#include _XOPEN_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<cs50.h>

int main (int argc,string argv[])
{
    if (argv !=2)
    {
        printf("use: crack <hash>");
        return 1;
    }
    int letters-djib =53;
    string letters ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash =argv[1];
    char salt[3];
    memcpy(salt,hash,2);
    salt[2]='\0';

    char key_candidate[6]="\0\0\0\0\0\0";

    for(int zero =0 ;zero<letters-djib ;zero++)
    {
        for(int one =0 ;one<letters-djib ;one++)
        {
            for(int two =0; two<letters-djib; two++)
            {
                for(int tree=0 ;tree<letters-djib;tree++)
                {
                    for(int fourth=0;fourth<letters-djib;fourth++)
                    {
                        key_candidate[0]=letters[fourth];
                        key_candidate[1]=letters[tree];
                        key_candidate[2]=letters[two];
                        key_candidate[3]=letters[one];
                        key_candidate[4]=letters[zero];
                        if(strcmp(crypt(key_candidate,salt),hash)==0)
                        {
                            printf("%s\n",key_candidate);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("password could no be cracked");
    return 2;
}