#include <ansi.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIB"英雄會"NOR);
        set("long", @LONG
這裡是京城的一間豪華大宅，也不知是哪位富賈購置，後來有一天據說這位富
賈昔日乃是一位綠林大盜，從此這位富賈便音訊全無，可是過了不久，這裡陸陸續
續多了不少武林人物出入，儼然成了京城中各綠林好漢的匯聚之所。
院子裡備有馬匹，來往的好漢們可以隨時要馬(yaoma)離開京城。
LONG
        );
        set("indoors", "city");
        set("exits", ([
                "northeast"  :  __DIR__"dao3",
                "southeast"  :  __DIR__"dao4",
                "northwest"  :  __DIR__"dao9",
                "southwest"  :  __DIR__"dao10",
        ]));

        set("no_fight",1);
        set("no_fly",1);
        setup();
}

void init()
{
       //add_action("do_order","yaoma");
}

int do_order()
{
      object me=this_player(),*ilist;
      int i;

      ilist=all_inventory(me);
      for( i=0;i<sizeof(ilist);i++ )
      if( ilist[i]->is_character() && query_temp("chousha", ilist[i]) )
      delete_temp("chousha", ilist[i]);

      if( query_temp("chousha", me) )
      {
       message("channel:rumor",HIB"【江湖仇殺】風聞"+query("name", me )
       +"在仇殺中臨陣脫逃，倉皇離開了紫金城！\n"NOR,users());

       addn("score", -1000, me);
       delete_temp("chousha", me);
      }
      message_vision(YEL"$N一把牽過馬匹韁繩，縱身躍上馬背，飛奔而去......\n"NOR,me);
      me->move("/d/city/wumiao");

      return 1;
}
