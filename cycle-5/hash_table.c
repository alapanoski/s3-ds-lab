#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct entry
{
	int value;
	int occupied;
	struct entry *next;
};

typedef struct
{
	struct entry entries[TABLE_SIZE];
} hashtable;

hashtable *create_new_hashtable()
{
	hashtable *h = (hashtable *)malloc(sizeof(hashtable));

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		h->entries[i].value = 0;
		h->entries[i].occupied = 0;
	}

	return h;
}

// Mod
int hash(int key)
{
	// int r = TABLE_SIZE / 10 + 1;
	// int hash = 0;

	// key = key * key;
	// int key_save = key;
	// int number_of_digits = 0;
	// while(key > 0)
	//{
	//	number_of_digits++;
	//	key = key / 10;
	// }

	// key = key_save;
	// int mid = number_of_digits / 2;
	// for(int i = 0; i < mid / 2; i++)
	//		key = key / 10;
	// for(int i = 0; i < mid / 2; i++)
	//{
	//	hash = (key % 10) * 10 + hash;
	//	key = key / 10;
	// }

	// key = key_save;
	return (key % TABLE_SIZE);
}

void insert(int key, hashtable *h)
{
	int value = hash(key);
	if (!(h->entries[value].occupied))
	{
		h->entries[value].value = key;
		h->entries[value].occupied = 1;
	}
	else
	{
		struct entry *new_entry = (struct entry *)malloc(sizeof(struct entry));
		new_entry->next = NULL;
		struct entry *ptr = &(h->entries[value]);
		while (ptr->next != NULL)
			ptr = ptr->next;
		new_entry->value = key;
		new_entry->occupied = 1;
		ptr->next = new_entry;
	}
}


void search(int key, hashtable *h)
{
	int value = hash(key);
	if (!(h->entries[value].occupied))
	{
		printf("Element not found\n");
		return;
	}
	else
	{
		struct entry *ptr = &(h->entries[value]);
		while (ptr != NULL)
		{
			if (ptr->value == key)
			{
				printf("Element is present in the hash table\n");
				return;
			}
		ptr = ptr->next;
		}
	}
}

void print(hashtable *h)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		struct entry *ptr = &(h->entries[i]);
		if (ptr->occupied)
		{
			printf("%d:\t", i);
			while (ptr != NULL)
			{
				if (ptr->occupied)
					printf("%d,\t", ptr->value);
				else
					printf("NULL\t");
				ptr = ptr->next;
			}
			printf("\n");
		}
	}
}


int main()
{
	hashtable *h = (hashtable *)malloc(sizeof(hashtable));

	while (1)
	{
		printf("Enter a value to enter: ");
		int key;
		scanf("%d", &key);
		if (key == -1)
			break;
		insert(key, h);
	}

	printf("--------HASH TABLE--------\n");
	print(h);

	while (1)
	{
		printf("Enter a value to search: ");
		int key;
		scanf("%d", &key);
		if (key == -1)
			break;
		search(key, h);
	}
}
