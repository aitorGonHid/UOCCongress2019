#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "organization.h"

// Initialize the organization structure
tError organization_init(tOrganization* object, const char* name, tGuestTable* guests) {

    // PR1 EX2
	// verify pre conditions
	assert(object != NULL);
	assert(name != NULL);
	assert(guests != NULL);
	
    // Allocate the memory for all the fields, using the length of the provided text plus 1 space for the "end of string" char '\0'. To allocate memory we use the malloc command.
	object->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
	
    // Check that memory has been allocated for all fields. Pointer must be different from NULL.
    if(object->name == NULL) {
        // Some of the fields have a NULL value, what means that we found some problem allocating the memory
        return ERR_MEMORY_ERROR;
    }	
	// Once the memory is allocated, copy the data.
    //copying the name of the tOrganization object
	strcpy(object->name, name);
	object->guests= guests;
    
    return OK;    
}

// Remove the memory used by organization structure
void organization_free(tOrganization* object) {
    
    // PR1 EX2
	if(object->name != NULL) {
        free(object->name);
        object->name = NULL;
	}
	object->guests=NULL;
    return ;
}

// Compare two organizations
bool organization_equals(tOrganization* organization1, tOrganization* organization2) {
    
    // PR1 EX2
	// Verify pre conditions
    assert(organization1 != NULL);
    assert(organization2 != NULL);

    if(strcmp(organization1->name, organization2->name) != 0) {
        // Names are different
        return false;
	}
	if (!guestTable_equals(organization1->guests, organization2->guests)){
		//Guest tables are different
		return false;
	}
    
    return true;
	
}

// Copy the data of a organization to another organization
tError organization_cpy(tOrganization* dst, tOrganization* src) {
    // PR1 EX2
	// Verify pre conditions
    assert(dst != NULL);
    assert(src != NULL);
    
    // Free the space used by destination object. An initialized object is assumed.
    dst->name=NULL;
    
    // Initialize the element with the new data
    organization_init(dst, src->name, src->guests);
	
	 if(dst->name == NULL || dst->guests == NULL) {
        // Some of the fields have a NULL value, what means that we found some problem allocating the memory
        return ERR_MEMORY_ERROR;
	}

    else {
		return OK;
	}
}

// Get the guestTable of a organization
tGuestTable* organization_getGuests(tOrganization* organization) {
     // PR1 EX2
	tGuestTable *pntr;
	pntr=organization->guests;
	
	return pntr;
}


// Initialize the Table of organizations
void organizationTable_init(tOrganizationTable* table) {
    // PR1 EX3
	// Verify pre conditions
    assert(table != NULL);    
    
    // The initialization of a table is to set it to the empty state. That is, with 0 elements. 
    table->size = 0;
    // Using dynamic memory, the pointer to the elements must be set to NULL (no memory allocated). This is the main difference with respect to the user of static memory, were data was allways initialized (tGuest elements[MAX_ELEMENTS])
    table->elements = NULL;
    return ;
}

// Remove the memory used by organizationrTable structure
void organizationTable_free(tOrganizationTable* object) {
    // PR1 EX3
    return ;
}

// Add a new organization to the table
tError organizationTable_add(tOrganizationTable* table, tOrganization* organization) {
    // PR1 EX3
    return ERR_NOT_IMPLEMENTED;
}

// Delete an organization from the table
tError organizationTable_remove(tOrganizationTable* table, tOrganization* organization) {
    // PR1 EX3
    return ERR_NOT_IMPLEMENTED;
}

// Get organization by organization_name
tOrganization* organizationTable_find(tOrganizationTable* table, const char* organization_name) {
    // PR1 EX3
    return NULL;
}

// Get the size of a the table
unsigned int organizationTable_size(tOrganizationTable* table) {
    // PR1 EX3
    return 0;
}