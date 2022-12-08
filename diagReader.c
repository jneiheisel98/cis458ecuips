#include <stdio.h>

#include <string.h>



void main()

{

    FILE *fp = fopen("test01.csv", "r");

    const char s[2] = ",";

    char *token;

    int i;

    if(fp != NULL)

    {

        char line[80];

        while(fgets(line, sizeof line, fp) != NULL)

        {

            token = strtok(line, s);

            for(i=0;i<20;i++)

            {

                if(i==0)

                {   

                    printf("%s\t",token);

                    token = strtok(NULL,s);

                } else {

                    printf("%d\n",atoi(token));

                }       

            }

        }

        fclose(fp);

    } else {

        perror("test01.csv");

    }   

}   
