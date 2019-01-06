/* 先使用 GB2312 字符集？ */

struct bnode {
	int id;
	char c[4];
	int left;
	int right;
};


/**********************
 *   v  NUL 勹  丶    *
 *    \/     \/       *
 *     白   勺        *
 *       \ /          *
 *        的          *
 **********************/


struct bnode charset[]={
	/* 汉字森林 */
	{0, "始",   0,  0},
	{1, "的",   2,  3}, /* 拆分后两叉均存于本集 */
	{2, "白",   2,  0}, /* 不拆，需另表说明属性 */
	{3, "勺",   4,  5},
	{4, "勹",   4,  0},
	{5, "丶",   5,  0},
	{6, "京", -12,  7}, /* 拆分后有一叉不在本集 */
	{7, "小",   7,  0},
	{8, "影",  10,  9},
	{9, "彡",   9,  0},
	{10,"景",  11,  6},
	{11,"日",  11,  0},
	{-1,"终",  -1, -1}, /* member id is not used. */
};

/*
 * 互质汉字集/字根集
 * 拆分后部件在字符集中没有
 * 不能拆分或有多种拆法的字
   GB      B1 B2 NUL
   UTF     B1 B2 B3
   UNICODE FF B0 B1
 */
struct charattr {
	int id;
	char c[4];
	int strk;	/* 最多 13 划 */
};

struct charattr rootset[] = {
	/* 地上落叶 */
	{0, "始",  0},
	{1, "一",  1},
	{2, "丨",  2},
	{3, "丿",  3},
	{4, "丶",  4},
	{5, "乙",  5},
	{6, "白",  42511},
	{7, "勹",  35},
	{8, "丶",  5},
	{9, "小",  234},
	{10, "彡",  333},
	{11, "日", 2511},
	{12, "高", 41251}, /*TODO: 中间性质字根问题 */

	{-1, "终", -1},
};



