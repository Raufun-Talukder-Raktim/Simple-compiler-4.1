#include<stdio.h>
#include<string.h>
#include<ctype.h>

char value1[10000],value2[10000],temp[10000];
char array[1000][1000];
int inde[10000];
int cur = 0;
struct data
{
    char * name;
    char * idType;
    char* dataType;
    char* scope;
    char* value;

}table[100];

void insert(int ind,char* _name, char* _id,char* _dat,char* _scope,char* _value);
int search(char* _name,char* _id,char* _scope);
char* modify(char * x);
void update(int cur,char* val);
void display();



char lex[100],prev_lex[100];
int a, pos;
int keywordCheck();
int identifierCheck();
int numberCheck();
int operatorCheck();
int separatorCheck();
int parenthesesCheck();
void assignmnet1();
void assignment2();
int headcheck();
int hash_chack();
void assignment3();
int keywordCheck_if();
int keywordCheck_else();
int notSemicolon;
int if_ = 0;
int else_ = 0;
int I();
int F(int i);
int E();
int L(int k);
int S(int k);
int LE(int k);
int k =0;





int main (void)
{

    char input[100];
    FILE *fp;
    fp = fopen("user_input.txt", "w");
    printf("Enter your code here (Enter 'q' to quit):\n");
    for (;;)
    {
        gets(input);
        if (strcmp(input, "q") != 0)
        {
            fprintf(fp, "%s\n", input);
        }
        else
            break;
   }
    fclose(fp);


    assignmnet1();

    return 0;
}


void assignmnet1()
{
    FILE *p1,*p2,*p3;
    int state = 0;
    int countLine = 1,k=-1,i=0;
    char r,a;
    char f[10];
    int flag =0, newline = 0;
    int count=0;
    int count1=0,value =0,space = 0;
    int space_count = 0;
    char c,e;
    p1 = fopen("C2_190104151_input.c","r");
    p2 = fopen("output_assignment1.txt","w");
    p3 = fopen("output_assignment1_3.txt","w");

    if(!p1)
        printf("File can not be opened");
    else
    {
        while ((c = fgetc(p1)) != EOF)
        {
            if (c == '/')
            {
                state ++;
                continue;
            }
             if (c == '*' )
            {
                flag ++;
                continue;
            }
            if (state == 2 && c != '\n' && flag == 0)
            {
                continue ;
            }
            else if  (state == 2 && c == '\n'){
                state = 0;
            }
            else if (state == 1 && flag ==1 && state <2 && flag <2 )
            {
                 continue;
            }
            else
            {
                state = 0;
                flag = 0;
            }
            if(countLine==1)

            {
                r = countLine+'0';
                fputc(r, p3);
                fputc(' ', p3);
                countLine++;
            }
            if ( c == '\n')
            {
                if (countLine<=9)
                {
                    r = countLine+'0';
                    fputc(c, p3);
                    fputc(r, p3);
                    countLine ++;
                    fputc(' ', p3);
                }
                else if (countLine>9 && countLine<20)
                {
                    countLine ++;
                    k++;
                    f[0] = '1';
                    f[1] = k+'0';
                    fputc(c, p3);
                    for (int i =0;i<2;i++)
                        fputc(f[i], p3);
                    fputc(' ', p3);
                }
                else if (countLine>19 && countLine<30)
                {
                    countLine ++;
                    k++;
                    f[0] = '2';
                    f[1] = k+'0';
                    fputc(c, p3);
                    for (int i =0;i<2;i++)
                        fputc(f[i], p3);
                    fputc(' ', p3);
                }
                else if (countLine>29 && countLine<40)
                {
                    countLine ++;
                    k++;
                    f[0] = '3';
                    f[1] = k+'0';
                    fputc(c, p3);
                    for (int i =0;i<2;i++)
                        fputc(f[i], p3);
                    fputc(' ', p3);
                }
                continue;
            }
            if (c== ' ')
            {
                space_count ++;
            }
            else
                space_count = 0;
            if (space_count == 1)
            {
                fputc(' ', p2);
                fputc(' ', p3);
                continue;
            }
            else if (space_count >1)
            {
                space_count=0;
                continue;
            }

            fputc(c, p2);
            fputc(c, p3);
        }
    }
    fclose(p1);
    fclose(p3);
    fclose(p2);
    p1 = fopen("input.c","r");
    p2 = fopen("output.txt","r");

    printf("Sample Input\n");
    printf("\n");
    while((e = fgetc(p1)) != EOF)
    printf("%c",e);
    printf("\n");

    printf("Sample Output Assignment 1\n");

    while((c=fgetc(p2))!=EOF)
    printf("%c",c);
    printf("\n");

    fclose(p2);
    fclose(p1);
    printf("\n");
    assignment2();
}


void assignment2 ()
{
    FILE *p1,*p2,*p3,*p4,*p5,*p6;
    p1 = fopen("output_assignment1.txt","r");
    p3 = fopen("output_assignment1_3.txt","r");
    p2 = fopen("output_assignment2.txt","w");
    p4 = fopen("output_assignment2_3.txt","w");
    char c,e;
    int count=0,  flag = 0;
    int value;
    int i;
    if(!p1)
        printf("File can not be opened");
    else
    {
        while ((c = fgetc(p1)) != EOF)
        {
            if (c == ';'||c == ',' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
             c == '(' || c == ')' || c == '>' || c == '<' || c == '!' || c == '|' || c == '&' || c == '=')
             {
                 fputc(' ', p2);
                 fputc(c, p2);
                 fputc(' ', p2);
                 continue;
             }
             fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);
    p3 = fopen("output_assignment2.txt","r");
    p4 = fopen("output_assignment2_final.txt","w");
    while ((c = fgetc(p3)) != EOF)
        {
            if(c == ' ')
                count = count +1;
            else
                count=0;
            if(count >= 2)
            {
                count--;
                continue;
            }
            fputc(c, p4);
        }
    fclose(p3);
    fclose(p4);
    p2 = fopen("output_assignment2_final_result.txt","w");
    p4= fopen("output_assignment2_final.txt","r");
                printf("Sample Output Assignment 2\n");
    while((c=fgetc(p4))!=EOF)
    {
        if (c!=' ')
            lex[pos] = c;
        else
        {
            lex[pos] = NULL;
            int key,id,number,ope,sep,paren,head,hash;
            key = keywordCheck();
         // printf("%d",key);
            id=identifierCheck();
            number = numberCheck();
            ope = operatorCheck();
            sep = separatorCheck();
            paren = parenthesesCheck();
            head  = headcheck();
            hash = hash_chack();


            if (hash == 1)
            {
                printf("[hash %s] ", lex);
                fprintf(p2, "[hash %s] ", lex);
                hash = 0 ;
            }

            else if(head == 1)
            {
                printf("[header %s] ", lex);
                fprintf(p2, "[header %s] ", lex);
                head = 0 ;
            }

            else if(key == 1)
            {
                printf("[kw %s] ", lex);
                fprintf(p2, "[kw %s] ", lex);
                key = 0 ;
            }
            else if(id == 1)
            {
                printf("[id %s] ", lex);
                fprintf(p2, "[id %s] ", lex);
                id =0;
            }
            else if(number == 1)
            {
                printf("[num %s] ", lex);
                fprintf(p2, "[num %s] ", lex);
                number = 0;
            }
            else if(ope == 1)
            {
                printf("[op %s] ", lex);
                fprintf(p2, "[op %s] ", lex);
                ope =0;
            }
            else if(sep == 1)
            {
                printf("[sep %s] ", lex);
                fprintf(p2, "[sep %s] ", lex);
                sep = 0;
            }
            else if(paren == 1)
            {
                printf("[par %s] ", lex);
                fprintf(p2, "[par %s] ", lex);
                paren = 0;
            }
            else
            {
                printf("[unkn %s] ", lex);
                fprintf(p2, "[unkn %s] ", lex);
            }
            pos=-1;
        }
        pos++;
    }
    fclose(p4);
     fclose(p2);
    printf("\n");
    assignment3();
}
int headcheck()
{
    if(!strcmp(lex, "include"))
        return 1;
    else
        return 0;
}
int hash_chack()
{
    for(a = 0; lex[a] != NULL; a++)
    {
        if(lex[a] == '#')
            continue;
        else
            return 0;
    }
    return 1;
}

int keywordCheck()
{
    if(!strcmp(lex, "if"))
        return 1;
    if(!strcmp(lex, "static"))
        return 1;
    if(!strcmp(lex, "while"))
        return 1;
    if(!strcmp(lex, "default"))
        return 1;
    if(!strcmp(lex, "goto"))
        return 1;
    if(!strcmp(lex, "sizeof"))
        return 1;
    if(!strcmp(lex, "volatile"))
        return 1;
    if(!strcmp(lex, "const"))
        return 1;
    if(!strcmp(lex, "float"))
        return 1;
    if(!strcmp(lex, "short"))
        return 1;
    if(!strcmp(lex, "unsigned"))
        return 1;
    if(!strcmp(lex, "enum"))
        return 1;
    if(!strcmp(lex,"auto"))
        return 1;
    if(!strcmp(lex, "double"))
        return 1;
    if(!strcmp(lex, "int"))
        return 1;
    if(!strcmp(lex, "struct"))
        return 1;
    if(!strcmp(lex, "break"))
        return 1;
    if(!strcmp(lex, "else"))
        return 1;
    if(!strcmp(lex, "long"))
        return 1;
    if(!strcmp(lex, "switch"))
        return 1;
    if(!strcmp(lex, "case"))
        return 1;
    if(!strcmp(lex, "register"))
        return 1;
    if(!strcmp(lex, "typedef"))
        return 1;
    if(!strcmp(lex, "char"))
        return 1;
    if(!strcmp(lex, "extern"))
        return 1;
    if(!strcmp(lex, "return"))
        return 1;
    if(!strcmp(lex, "union"))
        return 1;
    if(!strcmp(lex, "continue"))
        return 1;
    if(!strcmp(lex, "for"))
        return 1;
    if(!strcmp(lex, "signed"))
        return 1;
    if(!strcmp(lex, "void"))
        return 1;
    if(!strcmp(lex, "do"))
        return 1;
    else
        return 0;
}

int identifierCheck()
{
    if((lex[0] >= 'A' && lex[0] <= 'Z') || (lex[0] >= 'a' && lex[0] <= 'z') || (lex[0] == '_'))
    {
        for(a = 1; lex[a] != NULL; a++)
        {
            if((lex[a] >= 'A' && lex[a] <= 'Z') || (lex[a] >= 'a' && lex[a] <= 'z') || (lex[a] >= '0' && lex[a] <= '9') || (lex[a] == '_'))
                continue;
            else
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

int numberCheck()
{
    for(a = 0; lex[a] != NULL; a++)
    {
        if((lex[a] >= '0' && lex[a] <= '9') || (lex[a] == '.'))
            continue;
        else
            return 0;
    }
    return 1;
}

int operatorCheck()
{
    for(a = 0; lex[a] != NULL; a++)
    {
        if((lex[a] == '%') || (lex[a] == '*') || (lex[a] == '+') || (lex[a] == '-') || (lex[a] == '/') || (lex[a] == '<') || (lex[a] == '=')|| (lex[a] == '>'))
            continue;
        else
            return 0;
    }
    return 1;
}

int separatorCheck()
{
    for(a = 0; lex[a] != NULL; a++)
    {
        if((lex[a] == '"') || (lex[a] == 39) || (lex[a] == ',') || (lex[a] == ';'))
            continue;
        else
            return 0;
    }
    return 1;
}

int parenthesesCheck()
{
    for(a = 0; lex[a] != NULL; a++)
    {
        if((lex[a] == '(') || (lex[a] == ')') || (lex[a] == '{') || (lex[a] == '}') || (lex[a] == '[') || (lex[a] == ']'))
            continue;
        else
            return 0;
    }
    return 1;
}
void assignment3()
{
    int i=0,n,t,k=0,j, x=0, y=0,m;
    int e;
    FILE *fp = fopen("output_assignment2_final_result.txt","r");

    if (!fp)
        printf("The file can not be opened");
    else
    {
        printf("Input:\n");
        while ((e=fgetc(fp))!=EOF)
        {
            value1[i]=e;
            i++;
            printf("%c",e);
        }
        value1[i] = '\0';

    fclose(fp);

    for (i=0;i<strlen(value1);i++)
    {
        if(value1[i]=='[')
        {
            value2[k++] = value1[i++];
            j=0;
            while (value1[i]!=' ')
            {
                temp[j++] = value1[i];
                i++;
            }
            temp[j] = '\0';
            if(!strcmp(temp,"id"))
            {
                value2[k++]  = 'i';
                value2[k++]  = 'd';
               value2[k++]  = ' ';
            }
            i++;
            while(value1[i]!=']')
            {
                value2[k++]  = value1[i];
                i++;
            }
            value2[k++] =  value1[i];
        }
    }
  value2[k]  = '\0';
    printf("\n\n");
    puts(value2);
    fp = fopen("Token.txt","w");
    fputs(value2,fp);
    fclose(fp);
    k = 0;
    for(i=0;i<strlen(value2);i++)
    {
        if(value2[i]=='[')
        {
            j= 0;
            i++;
            while(value2[i]!=']' && value2[i]!=' ')
            {
                array[k][j++]  = value2[i++];
            }
            array[k][j]  = '\0';
            k++;
            if(value2[i]==' ')
            {
                j= 0;
                i++;
                while(value2[i]!=']')
                {
                    array[k][j++]  = value2[i++];
                }
                array[k][j]  = '\0';
                k++;
            }
        }
    }
    printf("\n\n");
    int it = 0;
    char * scope = "global";
    for(i=0;i<k;i++)
    {
        if(!strcmp(array[i],"id"))
        {
            if(!strcmp(array[i+2],"("))
            {
                if(!strcmp(array[i-1],"int") || !strcmp(array[i-1],"double") || !strcmp(array[i-1],"float") || !strcmp(array[i-1],"char") )
                {
                    inde[it++]  = cur;
                    insert(cur++,array[i+1],"func",array[i-1],scope,"");
                    scope = array[i+1];
                    i+= 2;
                }
                else
                {
                    int pq  = search(array[i+1],"func","global");
                    if(pq!=-1)
                        inde[it++] = pq;
                  else printf("\nID %s is not declared in global scope\n",array[i+1]);
                    i+= 2;
                }
            }
            else if(!strcmp(array[i+2],"="))
            {
                if(!strcmp(array[i-1],"int") || !strcmp(array[i-1],"double") || !strcmp(array[i-1],"float") || !strcmp(array[i-1],"char") )
                {
                    if(search(array[i+1],"var",scope)==-1)
                    {
                        inde[it++]  = cur;
                        insert(cur++,array[i+1],"var",array[i-1],scope,modify(array[i+3]));
                    }
                    else
                    {
                        printf("\nID %s already declared in %s scope\n",array[i+1],scope);
                    }
                }
                else
                {
                    int pq = search(array[i+1],"var",scope);
                    if(pq==-1)
                    {
                        printf("\nID %s is not declared in %s scope\n",array[i+1],scope);
                    }
                    else
                    {
                        update(pq,modify(array[i+3]));
                        inde[it++]  = pq;
                    }
                }
                i+=2;
            }
            else if(!strcmp(array[i+2],";") || !strcmp(array[i+2],",") || !strcmp(array[i+2],")") )
            {
                if(!strcmp(array[i-1],"int") || !strcmp(array[i-1],"double") || !strcmp(array[i-1],"float") || !strcmp(array[i-1],"char") )
                {
                    if(search(array[i+1],"var",scope)==-1)
                    {
                        inde[it++]  = cur;
                        insert(cur++,array[i+1],"var",array[i-1],scope,"");
                    }
                    else printf("\nID %s already declared in %s scope\n",array[i+1],scope);
                    i+= 2;
                }
                else
                {
                    if(search(array[i+1],"var",scope)==-1)
                    {
                        printf("\nID %s is not declared in %s scope\n",array[i+1],scope);
                    }
                    else inde[it++]  = search(array[i+1],"var",scope);
                    i+= 2;
                }
            }
        }
        else if(!strcmp(array[i],"}"))
        {
            scope = "global";
        }
    }
    display();
    printf("\n\n");


        printf("Sample Output Assignment 3\n");

    fp = fopen("output_assignment3.txt","w");
    it =0;
    for(i=0;i<strlen(value2);i++)
    {
        if(value2[i]=='[')
        {
            printf("%c",value2[i]);
            fputc(value2[i],fp);
            i++;
            while(value2[i]!=']' && value2[i]!=' ')
            {
                printf("%c",value2[i]);
                fputc(value2[i],fp);
                i++;
            }
            if(value2[i]==' ')
            {
                printf("%c",value2[i]);
                fputc(value2[i],fp);
                j= 0;
                i++;
                while(value2[i]!=']')
                      {
                    i++;
                }
                fputc(inde[it]+1+48,fp);
                       printf("%d",inde[it++]+1);
            }
            printf("%c",value2[i]);
            fputc(value2[i],fp);

        }
        else
        {
            printf("%c",value2[i]);
        }
    }
    fclose(fp);
    }
    assignment4();
}


void insert(int ind,char* _name, char* _id,char* _dat,char* _scope,char* _value)
{
    table[ind].name  =_name;
    table[ind].idType= _id;
    table[ind].dataType = _dat;
    table[ind].scope  =_scope;
    table[ind].value  =_value;
}



int search(char* _name,char* _id,char* _scope)
{
    int i=0;

    for(i=0;i<cur;i++)
    {
        if(strcmp(table[i].name,_name)==0 && strcmp(table[i].idType,_id)==0 && strcmp(table[i].scope,_scope)==0 )
        {
            return i;
        }
    }
    return -1;
}


char* modify(char * x)
{
    if(strlen(x)==0)
        return x;
    if(x[0]>='0' && x[0]<='9')
        return x;
    return "";
}

void update(int cur,char* val)
{
    table[cur].value  = val;
}

void display()
{
    int i=0;
    printf("\nSl.No.   Name   Id Type       Data Type       Scope         Value\n");
    for(i=0;i<cur;i++)
    {
        printf("%d          %s      %s         %s           %s          %s\n",i+1,table[i].name,table[i].idType,table[i].dataType,table[i].scope,table[i].value);
    }
}
//if & else will be check when try to calculate the if-else error;
//arithmatic gramer chack

void assignment4()
{
    FILE *p4,*p5,*p1,*p2,*p3,*p6;
    p1 = fopen("output_assignment1_3.txt","r");
    p2 = fopen("output_result2_3.txt","w");
    int count1=0;
    int value;
    char c;

    if(!p1)
        printf("File can not be opened");
    else
    {
        while ((c = fgetc(p1)) != EOF)
        {
            if (c=='{'||c=='}'||c == ';'||c == ',' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
             c == '(' || c == ')' || c == '>' || c == '<' || c == '!' || c == '|' || c == '&' || c == '=')
             {
                 fputc(' ', p2);
                 fputc(c, p2);
                 fputc(' ', p2);
                 continue;
             }
             fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);
    p3 = fopen("output_result2_3.txt","r");
    p4 = fopen("final3.txt","w");
    while ((c = fgetc(p3)) != EOF)
        {
            if(c!=' ')
                value = 1;
            if(c == ' ' && value !=1)
                continue;
            if(c == ' ' && value ==1)
                count1 = count1 +1;
            else
                count1=0;
            if(count1 >= 2)
            {
                continue;
            }
            fputc(c, p4);
        }
    fclose(p3);
    fclose(p4);
    int i;
    p5 = fopen("output_result2_3.txt","r");
    p6 = fopen("assignment_2_final_result_3.txt","w");
    while((c=fgetc(p5))!=EOF)
    {
        if(c != ' ')
            {
                lex[i] = c;
            }
            else
            {
                lex[i] = '\0';
                i = -1;
                 if(!keywordCheck() && identifierCheck())
                {
                    fprintf(p6, "id ");
                }
                fprintf(p6, "%s ", lex);
            }
            i++;
    }
    fclose(p5);
    fclose(p6);
    int countCurlyBracesF=0,countCurlyBracesL=0, countParentheses=0;
    int countLine = 1;
       int line = 1;
    int countSemiColon = 0;
    FILE *p7,*p8;
    p7 = fopen ("assignment_2_final_result_3.txt","r");
      strcpy(prev_lex, " ");
    printf("\n\n\nSample output of assignment 4");
    if (!p7)
        printf("File can not be opend");
    else
    {
        i =0;
        while((c=fgetc(p7))!=EOF)
        {
            if(c != ' ')
            {
                lex[i] = c;
            }
            else
            {
                lex[i] = '\0';
                i = -1;
                int key_if=0,key_else=0;
                int key_i ;
                int key_e ;
                key_i =keywordCheck_if();
                key_e =keywordCheck_else();
                key_if = key_if +key_i;
                key_else = key_else+key_e;


                if(key_e)
                {
                    printf("\n");
                    printf(" Unnecessary %s has been found in line no: %d\n", lex, countLine);
                   // key_else -- ;
                }
                /*if(key_if < key_else)
                {
                    printf("\n");
                    printf(" Unnecessary %s has been found in line no: %d\n", lex, countLine);
                    key_else -- ;
                }*/

                if(!strcmp(prev_lex, lex))
                {
                    printf("\n");
                    printf(" Unnecessary %s has been found in line no: %d\n", lex, countLine);

                }
                 strcpy(prev_lex, lex);

            }
            if (c=='\n')
            {
                countLine++;
            }
                i++;
            if (c == '}')
            {
                countCurlyBracesF--;
                if (countCurlyBracesF<0)
                {
                    printf("\n");
                    printf("Misplaced '}' at line %d",countLine);
                }
            }

            if (c == '}' && countCurlyBracesF<0)
            {
                continue;
            }
            if (c=='{')
            {
                countCurlyBracesF++;
                if (countCurlyBracesF>1)
                {
                    printf("\n");
                    printf("Misplaced '{' at line %d",countLine);
                }
            }

            if (c == ';')
                countSemiColon++;
            if (c!= '\n'&& c!=' ' && c!=';')
            {

                countSemiColon = 0;
            }
            if (c!= '\n'&& c==' ' && c!=';')
            {
                notSemicolon = 1;

            }
            if (notSemicolon != 0 && ((c>96 && c<123)||(c >64 && c<91)))
            {
                notSemicolon = 0;
                countSemiColon --;
            }
            if (c=='\n' && countSemiColon > 0)
            {
                printf("\n");
                printf("Duplicate ';' token at line %d", countLine-1);

                countSemiColon = 0;
            }
            else if (c=='\n'&& countSemiColon == 1)
            {

                  countSemiColon = 0;
            }
        }
    }
    return 0;
}


int keywordCheck_if()
{
    int len = strlen(lex);
    int i_value;
    if (len>1){
        i_value = I();
    }
    if(i_value == 2)
    {
        printf("IF is found but C language grammar is incorrect");
    }
    if (i_value == 1)
    {
        if_++;
        return if_;
    }

    else return 0;
}
int i =0;

int I()
{
    if (lex[i]=='i'){
        i++;
        int f;
        f=F(i);
        if(f == 1){
            return 1;
        }
        else if (f == 2) return 2;
        else return 0;
    }
}
int F(int i)
{
    if (lex[i]=='f')
    {
        i++;
        if(lex[i]!=' ' || lex[i]!= '\n' || lex[i]!='(')
        {
            return 2;
        }
       /* if(lex[i]!=' ' || lex[i]!= '\n' )
        {
            return 2;
        }*/
        return 1;
    }
}

int keywordCheck_else()
{

    int len = strlen(lex);
    int e_value;
    if (len>1)
    {
        e_value = E();
    }

        if(e_value == 2)
    {
         printf("Else is found but C language grammar is incorrect");
    }
    if(e_value == 1)
    {
        if (if_>=0)
        {
            if_ --;
        }
        if (if_<0)
        {
             return 1;
        }
    }
    else return 0;
}

int E()
{
    if (lex[k] == 'e'){
        k++;
         int l;
         l = L(k);
         if (l == 1){
            return 1;
         }
         else if (l == 2)
         {
             return 2;
         }
         else return 0;
    }
}
int L(int k)
{
    if (lex[k] == 'l'){
        k++;
        int s;
        s = S(k);
        if (s ==1){
            return 1;
        }
        else if (s == 2){
            return 2;
        }
        else return 0;
    }

}
int S(int k)
{
    if (lex[k] == 's'){
        k++;
        int le;
        le = LE(k);
        if (le == 1)
        {
            return 1;
        }
        else if (le == 2)
        {
            return 2;
        }
        else
            return 0;
    }
}
int LE(int k)
{
    if (lex[k] == 'e')
    {
        k++;
        return 1;
    }
}
