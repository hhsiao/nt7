#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"大雄寶殿"NOR);
        set("long",@LONG
這是一座寬廣的大殿，正中是三丈來高的南無如來釋迦牟尼佛、
南無金剛不壞佛、南無寶光佛三尊寶像，通體鍍金，光芒四射。寶座
下香爐中香菸繚繞，點的是那天竺檀香。蒲團前有一無量功德寶盒。
西過去通往地藏殿，東邊是藥師殿。
LONG);
        set("exits", ([
            "southdown" : __DIR__"road1",
                "north" : __DIR__"gfd",
                "west" : __DIR__"dizangdian",
                "east" : __DIR__"yaoshidian",
	]));
        set("coor/x",-350);
  set("coor/y",-330);
   set("coor/z",30);
   setup();
}

void init()
{
       add_action("do_ketou", "ketou");
}

int do_ketou(string arg)
{
object me=this_player();
int i;
i=me->query_skill("buddhism",1);
       if (me->is_busy()) return notify_fail("你正忙著呢。\n");
       if (i<20) return 0;
if (random(me->query("neili"))<i) {
   me->unconcious();
return 0;
}
       message_vision("$N虔誠地跪下來，在如來佛祖面前磕頭。\n", me);

    if (me->query("shen") > i)
    { me->add("shen", -i);
   me->add("neili",-i/10);}
    if (me->query("shen") <-i )
    { me->add("shen", i);
   me->add("neili",-i/10);}
   me->start_busy(random(2));
       return 1;
}
