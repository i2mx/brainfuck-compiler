#include <stdio.h>

#define DATASIZE 1001

void brainfuck(char *command, char *input)
{

    int bracket_count;
    char data[DATASIZE] = {0};
    char *dp = &data[DATASIZE / 2];

    while (*command)
    {
        switch (*command)
        {
        case '>':
            dp++;
            break;
        case '<':
            dp--;
            break;
        case '+':
            (*dp)++;
            break;
        case '-':
            (*dp)--;
            break;
        case '.':
            printf("%c", *dp);
            break;
        case ',':
            *dp = *input++;
            break;
        case '[':
            if (!*dp)
            {
                for (bracket_count = 1; bracket_count; command++)
                {
                    if (*command == '[')
                    {
                        bracket_count++;
                    }
                    else if (*command == ']')
                    {
                        bracket_count--;
                    }
                }
            }
            break;
        case ']':
            if (*dp)
            {
                command -= 2;
                for (bracket_count = 1; bracket_count; command--)
                {
                    if (*command == '[')
                    {
                        bracket_count--;
                    }
                    else if (*command == ']')
                    {
                        bracket_count++;
                    }
                }
                bracket_count++;
            }
            break;
        }
        command++;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    char *hello_world_code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    brainfuck(hello_world_code, "");
}
