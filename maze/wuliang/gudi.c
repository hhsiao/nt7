// Room: gudi.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "山谷底部");
	set("long", @LONG
只見左邊山崖上一條大瀑布如玉龍懸空，滾滾而下，傾入一座清澈異常的
大湖之中，大瀑布不斷傾入，湖水卻不滿溢，瀑布注入處湖水翻騰，只離得瀑
布十餘丈，湖水便又一平如鏡，四周圍長滿了雜草(cao)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"donghubian",            
        ]));
	set("item_desc",([	   
	   "cao" : "一大片雜草胡亂地長著，鑽進去不知道通向哪裡。\n"
	]));
	set("no_clean_up", 0);
        set("outdoors", "大理");
	setup(); 
}

void init()
{
	add_action("do_zuan", "zuan");
        add_action("do_zuan", "enter");
}

int do_zuan(string arg)
{
	object me;
	me = this_player();
        if (!arg || arg !="cao") 
           return notify_fail("你亂鑽什麼啊？\n");       
	message_vision("$N一頭鑽進了雜草叢。\n" , me);
        me->move("/d/dali/shanlu3");
        write("你眼前一亮，終於鑽出了雜草叢。\n");
	return 1;
}