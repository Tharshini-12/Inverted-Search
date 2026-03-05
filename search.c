/*👤NAME        : THARSHINI S
  📅DATE        : 09-12-2025
  📝DESCRIPTION : INVERTED SEARCH - SEARCH DATABASE */ 
  
#include "inverted.h"
#include<string.h>

int search_database(Htable *table, char *word)
{
   //validate user input
   if(word==NULL||word[0]=='\0')
   {
    printf("ERROR: Invalid word!\n");
    return FAILURE;
   }

   //convert input word to lowercase
   char search[MAXWORD];
   int i;
   for(i=0;word[i]!='\0';i++)
   {
     if(word[i]>='A'&&word[i]<='Z')
     {
        search[i]=word[i]+32;//convert to lowercase
     }
     else
     {
        search[i]=word[i];
     }
   }
   search[i]='\0';

   //compute hash index
   int index=hash_key(search);
   WordNode *temp=table[index].head;

   //search for the word in linked list
   while(temp!=NULL)
   {
    if(strcmp(temp->word,search)==0)
    {
        printf("\nWord '%s' is found in the database and it is present in %d file(s)\n",search,temp->file_count);
        FileNode *f=temp->f_link;
        while(f!=NULL)
        {
            printf("In file: %s %d time(s)\n",f->fname,f->word_count);
            f=f->f_link;
        }
        return SUCCESS;
    }
    temp=temp->w_link;
   }

   //if word not found
   printf("Word '%s' is not found in the database\n",search);
   return FAILURE;
}
