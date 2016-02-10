#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
    FILE *pFile;

    //challenge says the words can at most be 20 letters long
    //buffer will hold word space mask\0
    char buffer[50];
    char word[25];
    char mask[25];

    pFile = fopen(argv[1], "r");

    if(pFile == NULL)
    {
        perror("Error opening data");
    }
    else
    {
        while( !feof(pFile) )
        {
            if( fgets(buffer,50,pFile) == NULL )
            {
                break;
            }
            else
            {
                unsigned int index = 0;

                //fputs(buffer,stdout);
                
                while(buffer[index] != ' ')
                {
                    word[index] = buffer[index];
                    
                    ++index;
                }

                word[index] = '\n';
                word[index+1] = '\0';
            
                //fputs(word,stdout);

                ++index;

                unsigned int oldIndex = index;
                
                index = 0;

                while(buffer[oldIndex] != '\n' && index < 25)
                {
                    mask[index] = buffer[oldIndex];

                    ++oldIndex;
                    ++index;
                }

                mask[index] = '\n';
                mask[index+1] = '\0';
                
                //fputs(mask,stdout);

                index = 0;

                while(index < 25)
                {
                    if(mask[index] == '1')
                    {
                        word[index] = word[index] - 32;
                    }

                    ++index;
                }

                fputs(word,stdout);
            }
        }
            
        fclose(pFile);
    }

    return 0;
}
