// shulin2.c
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山中密林");
	set("long", @LONG
仰望高崖，白霧封谷，谷中靜悄悄的，別說人跡，就連獸蹤也無半點，唯
聞鳥語相間，遙相和呼，逆著瀑布從下往上看去，只見瀑布之右一塊石壁光潤
如玉，不知多少年的衝激磨洗，才將這半面石壁磨得如此平整，後來瀑水量減
少，才將這片如琉璃，如明鏡的石壁露了出來。
LONG
	);
        set("exits", ([
	    "south" : __DIR__"xihubian",
	]));
        set("outdoors", "大理");
	set("objects", ([
	        __DIR__"obj/yeguo" : 2,
	]));
	setup();
}