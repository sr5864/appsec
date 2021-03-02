/*
 * Gift Card Example Writer
 * Original Author: Shoddycorp's Cut-Rate Contracting
 * Maintainer: ???
 * Comments added by Justin Cappos (JAC)
 * Modification Date: 8 July 2020
 */

#include <stdio.h>
#include "giftcard.h"

/* JAC: Why is this included? */
#include <time.h>

struct this_gift_card examplegc;
struct gift_card_data examplegcd;
struct gift_card_record_data examplegcrd;
struct gift_card_amount_change examplegcac;


// Break it up so that we don't have long functions!  Good programming style!
//  (JAC: This is so wrong.  Global variable use / initialization is a 
//  terrible thing to do.)
void setupgc() {
	examplegc.num_bytes = 115;
	examplegc.gift_card_data = (void *) &examplegcd;
	examplegcd.merchant_id = "GiftCardz.com                   ";
	examplegcd.customer_id = "DuaneGreenes Store 1451         ";
	examplegcd.number_of_gift_card_records = 1;

	/* JAC: Something seems fishy... */
	examplegcd.gift_card_record_data = malloc(examplegcd.number_of_gift_card_records);
	/* JAC: here too! */
	examplegcd.gift_card_record_data[0] = (void *) &examplegcrd;
	examplegcrd.record_size_in_bytes = 44;
	examplegcrd.type_of_record = 3; // JAC: Should be enum!  amount_change
	examplegcrd.actual_record = (void *) &examplegcac;
	examplegcac.amount_added = 2000;
	examplegcac.actual_signature = "[ insert crypto signature here ]";
}


// moved into separate files to avoid erroenous style checker error...
/* JAC: opening and writing a fixed filename using a global is terrible style.
 *     the style checker was right!  This code is terrible   
 */
void writegc() {
	FILE *fd1;
	// JAC: Why don't any of these check for error return codes?!?
	fd1 = fopen("fuzzer2.gft","w");
	fwrite(&examplegc.num_bytes,4,1,fd1);
	fwrite(examplegcd.merchant_id,32,1,fd1);
	fwrite(examplegcd.customer_id,32,1,fd1);
	fwrite(&examplegcd.number_of_gift_card_records,4,1,fd1);
	fwrite(&examplegcrd.record_size_in_bytes,4,1,fd1);
	fwrite(&examplegcrd.type_of_record,4,1,fd1);
/*	fwrite(&examplegcac.amount_added,4,1,fd1);
	fwrite(examplegcac.actual_signature,32,1,fd1);*/
	char message[] ="This is a message";
	//char program[] = {0x09,-3,0x0};
	//char program[] = {0x01, 48+8, 0x0};
	//char program[] = {0x4, 48+8, 0x0};
	//char program[] = "This is a message";
	//char program[] = {0x4, 48+8, 0x0};
	//fwrite(message, 32, 1, fd1);
	//fwrite(program, 3, 1, fd1);
	//char program2[] = {0x03,16,0x0};
	//fwrite(message, 32, 1, fd1);
	//fwrite(program2, 3, 1, fd1);
	//char program3[] = {0x03,1,0x0};
	//fwrite(message, 32, 1, fd1);
	//fwrite(program3, 3, 1, fd1);
	//for (int i = 1; i<9; i++){
	//	char program[] = {0x00 + i, 48+8, 0x0};
	//	fwrite(message, 32, 1, fd1);
	//	fwrite(program, 3, 1, fd1);
	//}
	//char program4[] = {0x04,1,0x0};
	//fwrite(message, 32, 1, fd1);
	//fwrite(program4, 3, 1, fd1);
	char program[] = {0x04,0x0,48+8};
	fwrite(message, 32, 1, fd1);
	fwrite(program, 3, 1, fd1); 
	//char program6[] = {0x06,1,0x0};
	//fwrite(message, 32, 1, fd1);
	//fwrite(program6, 3, 1, fd1);
	//char program7[] = {0x07,1,0x0};
	//fwrite(message, 32, 1, fd1);
	//fwrite(program7, 3, 1, fd1);
	//char program8[] = {0x08,1,0x0};
	//fwrite(message, 32, 1, fd1);
	//fwrite(program8, 3, 1, fd1);
	//char program10[] = {0x010,1,0x0};
	//fwrite(message, 32, 1, fd1);
	//fwrite(program10, 3, 1, fd1);
	//char program1[] = {0x01, 48+8, 0x0};
	//fwrite(message, 32, 2, fd1);
	//fwrite(program1, 3, 1, fd1);
	fclose(fd1);
}

/* JAC: No args and return -1 for no reason!?! */
int main(void) {

	setupgc();
	writegc();
	return -1;
}

