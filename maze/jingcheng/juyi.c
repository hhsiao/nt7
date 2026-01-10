#include <ansi.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"聚義廳"NOR);
        set("long", @LONG
這裡是京城的一間豪華大宅，據說曾經是一位與江湖白道頗有淵源的富賈購置，
這位富賈為了廣結白道人士，經常在這裡禮宴迎賓，久而久之，這裡竟成了京城中
白道人士的暫居之所。
院子裡備有馬匹，來往的俠士們可以隨時要馬(yaoma)離開京城。
LONG
        );
        set("indoors", "city");
        set("exits", ([
                "northeast"  :  __DIR__"dadao27",
                "southeast"  :  __DIR__"dadao28",
                "northwest"  :  __DIR__"dadao33",
                "southwest"  :  __DIR__"dadao34",
        ]));

        set("no_fight",1);
        set("no_fly",1);
        setup();
}

void init()
{
//       add_action("do_order","yaoma");
}

int do_order(string arg)
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
                delete_temp("chousha", me);
                addn("score", -1000, me);
        }
        message_vision(YEL"$N一把牽過馬匹韁繩，縱身躍上馬背，飛奔而去......\n"NOR,me);
        me->move("/d/city/wumiao");
        return 1;
}
