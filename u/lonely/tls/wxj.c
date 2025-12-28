// modified by snowman.  檢查是否busy或 fighting

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"無心井"NOR);
	set("long", @LONG
這是一口千年古井，井旁是用青石砌成的井臺，上面是用生鐵鑄
就的一個高一尺的井緣。井內深達十幾米，水面上漂滿了落葉。井旁
雜草叢生，井邊的軲轆架也早就朽了，顯然很久沒人用了，奇怪的是
井邊的石板居然十分光滑。
LONG);
	set("exits", ([
		"west" : __DIR__"bzqn",
	]));

        set("resource/water",1); 
	set("outdoors", "天龍寺");
	set("coor/x",-380);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}
void init()
{
        add_action("do_tiao", "tiao");  
}

int do_tiao(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

        if ( !arg || (arg != "leaf") )
		return notify_fail("你要挑什麼？\n");
         
        if( me->is_busy() || me->is_fighting() ) return notify_fail("你正忙著呢。\n");
        if (!weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("你要用手把樹葉挑出來？\n");

        if ((int)me->query_skill("sword", 1) < 30 )
          return notify_fail("你滿頭大汗的挑了半天，連一片頁子也沒碰著，還是乾脆用手拿吧。\n");

        if ((int)me->query_skill("sword", 1) >100 )
        return notify_fail("你“唰唰”幾劍就把所有的落葉都挑出了井外。\n");
    
	me->receive_damage("jingli", random(40));
        write("你不斷用劍把落葉挑出井外，落葉隨水漂來漂去，你對劍術有了新的認識。\n");
         me->improve_skill("sword", me->query("int"));       
         return 1;
}                                     
