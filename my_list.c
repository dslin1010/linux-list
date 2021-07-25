#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "list.h"

#include "common.h"

static uint16_t values[10];


int main(){

	
	struct list_head  list1;
	struct listitem *item = NULL, *is=NULL ;
	size_t i;
 	
	INIT_LIST_HEAD(&list1);
	
	random_shuffle_array(values, (uint16_t) ARRAY_SIZE(values));

	assert(list_empty(&list1));

	for (i = 0; i < ARRAY_SIZE(values); ++i){
		item = (struct listitem *) malloc(sizeof(*item));
		assert(item);
		item->i = values[i];
		list_add_tail(&item->list, &list1);//add item to list1 tail
	}

	printf("list: ");

    i = 0;
    list_for_each_entry_safe (item, is, &list1, list) { 
        assert(item->i == values[i]); 
		printf(" %d ", item->i);
        i++;
    }

    i = 0;
    list_for_each_entry_safe (item, is, &list1, list) { 
        assert(item->i == values[i]); 
        list_del(&item->list); 
        free(item);
        i++;
    }

	return 0;
}


