#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
int getword(char *, int);



#define NDISTINCT 1000

struct tnode{
    char * word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);

void sortlist(void);
void treestore(struct tnode *);

struct tnode *list[NDISTINCT];
int ntn =0;

int main()
{
    struct tnode *root;
    char word[MAXWORD];
    int i;
    root = NULL;
    while(getword(word, MAXWORD)!=EOF)
    {
        if(isalpha(word[0]))
        {
            root = addtree(root, word);
        }

    }
    treestore(root);
    sortlist();
    for(i =0; i<ntn; i++)
    {
        printf("%2d:%20s", list[i]->count, list[i]->word);
    }
    return 0;
}



#define BUFSIZE 100
char buf[BUFSIZE];
int bufp =0;
int getch(void)
{
    return (bufp>0)?buf[--bufp]:getchar();
}

/* getword: get next word or character from input*/
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c=getch()))
    {
        ;
    }
    if(c != EOF)
    {
        *w++ = c;
    }
    if(!isalpha(c))
    //if(!isdigit(c))
    {
        *w = '\0';
        return c;
    }
    for(; --lim>0;w++)
    {
        if(!isalnum(*w = getch()))
        //if(!isdigit(*w = getch()))
        {
            ungetch(*w);
            break;
        }

    }
    *w = '\0';
    return word[0];
}

/*treestore: store in list[] pointers to tree /nodes*/
void treestore(struct  )   u          yyy y  /