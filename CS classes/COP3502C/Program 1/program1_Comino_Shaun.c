//Name:
//Dr. Steinberg
//COP3502C Spring 2022
//Programming Assignment 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 20

char ** doubleIt(char **arr, int *maxsize);
char ** populate(char ** words, FILE *fptr, int *currentsize, int *maxsize);
char* generateSentence(char ** noun, char ** verb, char ** adjective, char ** preposition, char ** article, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize); //write sentence to console window
void generateStory(char ** noun, char ** verb, char ** adjective, char ** preposition, char ** article, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize, FILE *fptr); //write story to txt file
void displaySentence(char * sentence);
void cleanUp(char ** nouns, char ** verbs, char ** adjectives, char ** prepositions, char ** articles, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize);

int main()
{
	//setup randomness
	int x;
	printf("Enter seed: ");
	scanf("%d", &x);
	srand(x); //set seed

	//declare necessary variables
	int nounsize = 0;
	int verbsize = 0;
	int adjsize = 0;
	int prepositionsize = 0;

	int nounmaxsize = 5;
	int verbmaxsize = 5;
	int adjmaxsize = 5;
	int prepositionmaxsize = 5;
	const int articlemaxsize = 3; //there are only 3 articles in the english language a, an, and the. that is why const is applied

	printf("Welcome to the random sentence generator.\n");

	//double pointers
	char ** nouns = NULL;
	char ** verbs = NULL;
	char ** adjectives = NULL;
	char ** preposition = NULL;
	char ** articles = NULL;

	nouns = (char **) malloc(sizeof(char *) * nounmaxsize);
	verbs = (char **) malloc(sizeof(char *) * verbmaxsize);
	adjectives = (char **) malloc(sizeof(char *) * adjmaxsize);
	preposition = (char **) malloc(sizeof(char *) * prepositionmaxsize);
	articles = (char **) malloc(sizeof(char *) * articlemaxsize);

	//make sure malloc was able to allocate memory
	if(nouns == NULL || verbs == NULL || adjectives == NULL || preposition == NULL || articles == NULL)
	{
		printf("malloc was not successful\n");
		printf("Program will now terminate.\n");
		exit(1);
	}

	//populate articles using strcpy. numbers represent how many characters are needed. this includes \0 character
	articles[0] = (char *) malloc(sizeof(char) * 2);
	strcpy(articles[0], "A");
	articles[1] = (char *) malloc(sizeof(char) * 3);
	strcpy(articles[1], "An");
	articles[2] = (char *) malloc(sizeof(char) * 4);
	strcpy(articles[2], "The");

	//open the file of words
	FILE *fptr = fopen("nouns.txt", "r");
	FILE *fptr2 = fopen("verbs.txt", "r");
	FILE *fptr3 = fopen("adjectives.txt", "r");
	FILE *fptr4 = fopen("preposition.txt", "r");

	//make sure the files were opened properly
	if(fptr == NULL || fptr2 == NULL || fptr3 == NULL || fptr4 == NULL)
	{
		printf("file was not successful in opening.");
		printf("Program will now terminate.\n");
		exit(1);
	}

	//populate the dynamic array
	nouns = populate(nouns, fptr, &nounsize, &nounmaxsize); //populate nouns
	verbs = populate(verbs, fptr2, &verbsize, &verbmaxsize); //populate verbs
	adjectives = populate(adjectives, fptr3, &adjsize, &adjmaxsize); //populate adjectives
	preposition = populate(preposition, fptr4, &prepositionsize, &prepositionmaxsize); //populate prepositions


	//close the files
	fclose(fptr);
	fclose(fptr2);
	fclose(fptr3);
	fclose(fptr4);

	//now lets generate 5 sentences and write them to the console window

	printf("Let's generate some random sentences that don't make sense.\n");

	for(int x = 0; x < 5; ++x)
	{
		char * sentence = generateSentence(nouns, verbs, adjectives, preposition, articles, nounsize, verbsize, adjsize, prepositionsize, articlemaxsize);
		displaySentence(sentence);
		free(sentence);
	}

	printf("Now let's create three stories that just don't make sense.\n");
	fptr = fopen("story1.txt", "w");
	generateStory(nouns, verbs, adjectives, preposition, articles, nounsize, verbsize, adjsize, prepositionsize, articlemaxsize, fptr); //story 1
	fclose(fptr);

	fptr = fopen("story2.txt", "w");
	generateStory(nouns, verbs, adjectives, preposition, articles, nounsize, verbsize, adjsize, prepositionsize, articlemaxsize, fptr); //story 2
	fclose(fptr);

	fptr = fopen("story3.txt", "w");
	generateStory(nouns, verbs, adjectives, preposition, articles, nounsize, verbsize, adjsize, prepositionsize, articlemaxsize, fptr); //story 3
	fclose(fptr);

	cleanUp(nouns,verbs, adjectives, preposition, articles, nounmaxsize, verbmaxsize, adjmaxsize, prepositionmaxsize, 3);


	printf("The stories were generated successfully and stored in their respective text files.\n");
	printf("Check them out!\n");

	return 0;
}

char ** doubleIt(char **arr, int *maxsize)
{

    // Declare new 2D char array
    char **new_arr = (char **) malloc(sizeof(char *) * (*maxsize * 2));

    if (new_arr == NULL)
    {
        printf("malloc was not successful\n");
		printf("Program will now terminate.\n");
		exit(1);
    }


    // Make room for an array in memory twice the size of the previous
    for (int i = 0; i < (*maxsize) * 2; i++)
    {
        new_arr[i] = (char *) malloc(sizeof(char) * LIMIT);
        if (new_arr[i] == NULL)
        {
            printf("malloc was not successful\n");
            printf("Program will now terminate.\n");
            exit(1);
        }
    }



    for (int i = 0; i < *maxsize; i++)
        strcpy(new_arr[i], arr[i]);

    // FREE THAT OLD ARRAY HE IS IMPRISONED IN MEMORY HELP HIM!
    for (int i = 0; i < *maxsize; i++)
    {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
    (*maxsize) *= 2;

    return new_arr;
}

char ** populate(char ** words, FILE *fptr, int *currentsize, int *maxsize)
{

    for (int i = 0; i < *maxsize; i++)
    {

        words[i] = (char *) malloc(sizeof(char) * LIMIT);
        char * new_word = (char *) malloc(sizeof(char) * LIMIT);

        if (words[i] == NULL || new_word == NULL)
        {
            printf("malloc was not successful\n");
            printf("Program will now terminate.\n");
            exit(1);
        }

        int scan_result = fscanf(fptr, "%s", new_word);

        if (scan_result > 0)
        {
            strcpy(words[i], new_word);
            (*currentsize)++;
        }


        if (*currentsize >= *maxsize)
            words = doubleIt(words, maxsize);

    }

    return words;

}

char* generateSentence(char ** noun, char ** verb, char ** adjective, char ** preposition, char ** article, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize)
{

    char * full_string = (char *) malloc(sizeof(char) * 100);

    if (full_string == NULL)
    {
        printf("malloc was not successful\n");
		printf("Program will now terminate.\n");
		exit(1);
    }

    int rand_article_index = rand() % articlesize;
    int rand_adjective_index = rand() % adjsize;
    int rand_preposition_index = rand() % prepositionsize;
    int rand_verb_index = rand() % verbsize;
    int rand_noun_index = rand() % nounsize;

    strcpy(full_string, article[rand_article_index]);
    strcat(full_string, " ");

    strcat(full_string, adjective[rand_adjective_index]);
    strcat(full_string, " ");


    strcat(full_string, noun[rand_noun_index]);
    strcat(full_string, " ");


    strcat(full_string, verb[rand_verb_index]);
    strcat(full_string, " ");

    strcat(full_string, preposition[rand_preposition_index]);
    strcat(full_string, " ");

    rand_article_index = rand() % articlesize;
    strcat(full_string, article[rand_article_index]);
    strcat(full_string, " ");

    rand_adjective_index = rand() % adjsize;
    strcat(full_string, adjective[rand_adjective_index]);
    strcat(full_string, " ");

    rand_noun_index = rand() % nounsize;
    strcat(full_string, noun[rand_noun_index]);
    strcat(full_string, ".");
    strcat(full_string, "\n");
    return full_string;

}

void displaySentence(char * sentence)
{
    printf("%s", sentence);
}

void generateStory(char ** noun, char ** verb, char ** adjective, char ** preposition, char ** article, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize, FILE *fptr)
{
    int rand_num = (rand() % (500 + 1 - 100) + 100);

    for (int i = 0; i < rand_num; i++)
    {
        char * random_sentence = generateSentence(noun, verb, adjective, preposition, article, nounsize, verbsize, adjsize, prepositionsize, articlesize);
        fprintf(fptr, "%s", random_sentence);
    }
}

void cleanUp(char ** nouns, char ** verbs, char ** adjectives, char ** prepositions, char ** articles, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize)
{
    for (int i = 0; i < nounsize; i++)
    {
        free(nouns[i]);
        nouns[i] = NULL;
    }
    free(nouns);
    nouns = NULL;

    for (int i = 0; i < verbsize; i++)
    {
        free(verbs[i]);
        verbs[i] = NULL;
    }
    free(verbs);
    verbs = NULL;

    for (int i = 0; i < adjsize; i++)
    {
        free(adjectives[i]);
        adjectives[i] = NULL;
    }
    free(adjectives);
    adjectives = NULL;

    for (int i = 0; i < prepositionsize; i++)
    {
        free(prepositions[i]);
        prepositions[i] = NULL;
    }
    free(prepositions);
    prepositions = NULL;

    for (int i = 0; i < articlesize; i++)
    {
        free(articles[i]);
        articles[i] = NULL;
    }
    free(articles);
    articles = NULL;

}

