// type_record.h

#ifndef TYPE_RECORD_H
#define TYPE_RECORD_H

typedef struct str_ty_record *ptr_record;
typedef struct str_ty_record {
	char name[100];
	int monincome;
	int link; 
} type_record;

#endif	// TYPE_RECORD_H