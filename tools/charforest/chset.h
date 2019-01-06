#ifndef __CHSET_H__
#define __CHSET_H__

struct bnode {
	int id;
	char c[4];
	int left;
	int right;
};

struct charattr {
	int id;
	char c[4];
	int strk;	/* ×î¶à 13 »® */
};

#endif
